#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define FROM 0
#define TO 1
#define DISTANCE 0
#define STATUS 1
#define SPENT 0
#define PENDING 1
#define GAP 6

int main() {
    
	int cases, nodes, edges, active, i, origin;
	int node[1000+1][2];		// [node][distance / status]
	int edge[1000*(1000-1)/2+1][2];	// [edge][from node / to node]
	
	scanf("%d", &cases);
	
	while(cases--)
	{
		
		scanf("%d%d", &nodes, &edges);
		
		for(i=1; i <= edges; i++){
			scanf("%d%d", &edge[i][FROM], &edge[i][TO]);
		}
	
		for(i=1; i <= nodes; i++){
			node[i][DISTANCE] = -1;
			node[i][STATUS] = PENDING;
		}
		
		scanf("%d", &origin);
	        active = origin;
		node[origin][DISTANCE] = 0;
		unsigned int min;
		while(active)
		{
			
			active = 0;
			min = -1;
			for(i=1; i <= nodes; i++)
			{
				if(node[i][STATUS]==PENDING && node[i][DISTANCE]!=-1 && node[i][DISTANCE]<min)
				{
					min = node[i][DISTANCE];
					active = i;
				}
			}
	
			for(i=1; i<=edges; i++)
			{ //originally thought it was a directed graph :/
				if(edge[i][FROM]==active)
				{
					if(node[edge[i][TO]][DISTANCE]>node[edge[i][FROM]][DISTANCE]+GAP || node[edge[i][TO]][DISTANCE]==-1)
					{
						node[edge[i][TO]][DISTANCE]=node[edge[i][FROM]][DISTANCE]+GAP;
					}
				}
				if(edge[i][TO]==active)
				{
					if(node[edge[i][FROM]][DISTANCE]>node[edge[i][TO]][DISTANCE]+GAP || node[edge[i][FROM]][DISTANCE]==-1)				{			
						node[edge[i][FROM]][DISTANCE]=node[edge[i][TO]][DISTANCE]+GAP;
					}
				}
			}
	
			node[active][STATUS] = SPENT;
	
		}
	
		for(i=1; i<=nodes; i++)
		{
			if(i!=origin)printf("%i ", node[i][DISTANCE]);
		
		}
	
		printf("\n");
	}
    
    return 0;
}

// some day I'm going to look back on this and want to smack myself

