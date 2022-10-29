#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool map[5000][5000];
bool flag[5000];
vector<int>topo;
int ban[5000];
int kai[5000];
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
		if(map[node][i])
		{
			dfs(i);
		}
	}
	topo.push_back(node);
}
void rdfs(int node,int b)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	for(int i=0;i<num;i++)
	{
		if(map[i][node])
		{
			rdfs(i,b);
		}
	}
	ban[node]=b;
}
int scc()
{
	fill(flag,flag+num,false);
	for(int i=0;i<num;i++)
	{
		if(!flag[i])
		{
			dfs(i);
		}
	}
	fill(flag,flag+num,false);
	int now=0;
	for(int i=num-1;i>=0;i--)
	{
		if(!flag[topo[i]])
		{
			rdfs(topo[i],now);
			now++;
		}
	}
	return now;
}
int main()
{
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		char zan[5001];
		scanf("%s",zan);
		for(int j=0;j<num;j++)
		{
			if(zan[j]=='1')
			{
				map[i][j]=true;
			}
			else
			{
				map[i][j]=false;
			}
		}
	}
	if(scc()==num)
	{
		printf("-1\n");
		return 0;
	}
	int nn;
	for(int i=0;i<num;i++)
	{
		kai[ban[i]]++;
		if(kai[ban[i]]>1)
		{
			nn=i;
			break;
		}
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(map[nn][i]&&map[i][j]&&map[j][nn])
			{
				printf("%d %d %d\n",nn+1,i+1,j+1);
				return 0;
			}
		}
	}
}