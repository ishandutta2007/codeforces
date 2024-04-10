#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define LIMIT 1000000
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
int ji[1000000];
int hai[1000000];
bool used[1000000];
int main()
{
	init();
	int cit,way;
	scanf("%d%d",&cit,&way);
	fill(ji,ji+cit,0);
	fill(used,used+cit,false);
	used[0]=true;
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		ji[za]^=1;
		ji[zb]^=1;
		unite(za,zb);
		used[za]=true;
		used[zb]=true;
	}
	for(int i=0;i<cit;i++)
	{
		if(used[i])
		{
			hai[find(i)]+=ji[i];
		}
	}
	int count=0;
	int sum=0;
	int zeronum=0;
	for(int i=0;i<cit;i++)
	{
		if(par[i]==i)
		{
			if(used[i])
			{
				sum+=hai[i];
				count++;
				if(hai[i]==0)
				{
					zeronum++;
				}
			}
		}
	}
	int ret=0;
	ret+=count-1;
	if(zeronum!=count)
	{
		sum-=(count-zeronum-1)*2;
	}
	else
	{
		if(zeronum!=1)
		{
			ret++;
		}
	}
	ret+=sum/2;
	printf("%d\n",ret);
}