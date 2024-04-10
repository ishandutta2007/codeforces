#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define LIMIT 100000
int par[LIMIT];
int ran[LIMIT];
int ren[LIMIT];
void init()
{
	for(int i=0;i<LIMIT;i++)
	{
		par[i]=i;
		ran[i]=0;
		ren[i]=1;
	}
}
int find(int a)
{
	if(par[a]==a)
	{
		return a;
	}
	else
	{
		return par[a]=find(par[a]);
	}
}
void unite(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
	{
		return;
	}
	if(ran[a]>ran[b])
	{
		par[b]=a;
		ren[a]+=ren[b];
	}
	else
	{
		par[a]=b;
		ren[b]+=ren[a];
	}
	if(ran[a]==ran[b])
	{
		ran[b]++;
	}
}
vector<int>pat[100000];
vector<int>topo;
bool flag[100000];
int ban[100000];
void dfs(int node)
{
	if(flag[node])return;
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		dfs(pat[node][i]);
	}
	topo.push_back(node);
	ban[node]=topo.size()-1;
}
bool dat[100000];
int main()
{
	init();
	int num,way;
	scanf("%d%d",&num,&way);
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		unite(za,zb);
	}
	fill(flag,flag+num,false);
	for(int i=0;i<num;i++)
	{
		if(!flag[i])dfs(i);
	}
	fill(dat,dat+num,true);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<pat[i].size();j++)
		{
			if(ban[i]<ban[pat[i][j]])dat[find(i)]=false;
		}
	}
	int ret=0;
	for(int i=0;i<num;i++)
	{
		if(i==find(i))
		{
			if(dat[i])ret+=ren[i]-1;
			else ret+=ren[i];
		}
	}
	printf("%d\n",ret);
}