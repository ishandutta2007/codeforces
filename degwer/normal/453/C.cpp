#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
vector<int>ko[100000];
bool flag[100000];
int par[100000];
#define LIMIT 100000
int pare[LIMIT];
int ran[LIMIT];
int ren[LIMIT];
void init()
{
	for(int i=0;i<LIMIT;i++)
	{
		pare[i]=i;
		ran[i]=0;
		ren[i]=1;
	}
}
int find(int a)
{
	if(pare[a]==a)
	{
		return a;
	}
	else
	{
		return pare[a]=find(pare[a]);
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
		pare[b]=a;
		ren[a]+=ren[b];
	}
	else
	{
		pare[a]=b;
		ren[b]+=ren[a];
	}
	if(ran[a]==ran[b])
	{
		ran[b]++;
	}
}
void dfs(int node)
{
	if(flag[node])
	{
		return;
	}
	flag[node]=true;
	for(int i=0;i<pat[node].size();i++)
	{
		if(!flag[pat[node][i]])
		{
			par[pat[node][i]]=node;
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
vector<int>ret;
int dat[100000];
int ance=0;
void calc(int node)
{
	for(int i=0;i<ko[node].size();i++)
	{
		ret.push_back(node);
		dat[node]^=1;
		calc(ko[node][i]);
	}
	ret.push_back(node);
	dat[node]^=1;
	if(dat[node]==1)
	{
		if(node!=ance)
		{
			ret.push_back(par[node]);
			ret.push_back(node);
			dat[node]^=1;
			dat[par[node]]^=1;
		}
		else
		{
			ret.pop_back();
			dat[node]^=1;
		}
	}
}
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	init();
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
		unite(za,zb);
	}
	fill(flag,flag+num,false);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&dat[i]);
	}
	bool f=false;
	for(int i=0;i<num;i++)
	{
		if(dat[i]==1&&(!f))
		{
			ance=i;
			f=true;
		}
		if(dat[i]==1)
		{
			if(find(i)!=find(ance))
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	dfs(ance);
	calc(ance);
	printf("%d\n",int(ret.size()));
	for(int i=0;i<ret.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ret[i]+1);
	}
	printf("\n");
}