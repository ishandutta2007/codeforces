#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define LIMIT 100
int par[LIMIT];
int ran[LIMIT];
int ren[LIMIT];
typedef pair<int,int>pii;
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
int main()
{
	init();
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		for(int j=0;j<i;j++)
		{
			if(za==vec[j].first||zb==vec[j].second)
			{
				unite(i,j);
			}
		}
		vec.push_back(make_pair(za,zb));
	}
	int ret=0;
	for(int i=0;i<num;i++)
	{
		if(par[i]==i)
		{
			ret++;
		}
	}
	printf("%d\n",ret-1);
}