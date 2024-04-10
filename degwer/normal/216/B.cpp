#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define LIMIT 100
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
int main()
{
	init();
	int cit,way;
	scanf("%d%d",&cit,&way);
	int ans=0;
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		if(find(za)==find(zb))
		{
			if(ren[find(za)]%2==1)
			{
				ans++;
			}
		}
		else
		{
			unite(za,zb);
		}
	}
	if((cit-ans)%2==1)
	{
		ans++;
	}
	printf("%d\n",ans);
}