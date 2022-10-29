#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int par[2000];
int ran[2000];
int ren[2000];
void init()
{
	for(int i=0;i<2000;i++)
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
	int nin;
	scanf("%d",&nin);
	int numl;
	scanf("%d",&numl);
	for(int i=0;i<numl;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		unite(za,zb);
	}
	int numd;
	scanf("%d",&numd);
	for(int j=0;j<numd;j++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		za=find(za);
		zb=find(zb);
		if(za==zb)
		{
			ren[za]=0;
		}
	}
	int maxi=0;
	for(int k=0;k<nin;k++)
	{
		maxi=max(ren[find(k)],maxi);
	}
	printf("%d\n",maxi);
}