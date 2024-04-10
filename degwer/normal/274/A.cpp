#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
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
int main()
{
	init();
	int num;
	ll gen;
	scanf("%d%I64d",&num,&gen);
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<num;i++)
	{
		int low=lower_bound(vec.begin(),vec.end(),vec[i]*gen)-vec.begin();
		if(low!=vec.size())
		{
			if(vec[i]*gen==vec[low])
			{
				unite(i,low);
			}
		}
	}
	int ret=0;
	for(int i=0;i<num;i++)
	{
		if(i==find(i))
		{
			ret+=(ren[i]+1)/2;
		}
	}
	printf("%d\n",ret);
}