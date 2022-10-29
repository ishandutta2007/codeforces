#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[2000][2000];
bool flag[2000];
int num;
void dfs(int node)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	for(int i=0;i<num;i++)
	{
		if(map[node][i]!=0)
		{
			dfs(i);
		}
	}
}
void rdfs(int node)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	for(int i=0;i<num;i++)
	{
		if(map[i][node]!=0)
		{
			rdfs(i);
		}
	}
}
int main()
{
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	fill(flag,flag+num,false);
	dfs(0);
	for(int i=0;i<num;i++)
	{
		if(!flag[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	fill(flag,flag+num,false);
	rdfs(0);
	for(int i=0;i<num;i++)
	{
		if(!flag[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}