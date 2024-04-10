#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
#define LIMIT 300
int bef[300];
int nex[300];
int par[LIMIT];
int ran[LIMIT];
int ren[LIMIT];
ll dp[100001];
ll newdp[100001];
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
	int num,way;
	ll gen;
	scanf("%d%d%I64d",&num,&way,&gen);
	vector<ll>pri;
	init();
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		pri.push_back(zan);
	}
	fill(bef,bef+num,-1);
	fill(nex,nex+num,-1);
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		bef[zb]=za;
		nex[za]=zb;
		if(find(za)==find(zb))
		{
			printf("0\n");
			return 0;
		}
		unite(za,zb);
	}
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		if(bef[i]==-1)
		{
			int now=i;
			ll nowcost=pri[i];
			for(;;)
			{
				vec.push_back(nowcost);
				now=nex[now];
				if(now==-1)
				{
					break;
				}
				gen-=nowcost;
				nowcost+=pri[now];
			}
		}
	}
	if(gen<0)
	{
		printf("0\n");
		return 0;
	}
	fill(dp,dp+100001,0LL);
	fill(newdp,newdp+100001,0LL);
	dp[0]=1;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]>gen)
		{
			continue;
		}
		for(int j=0;j<=gen;j++)
		{
			newdp[j]=dp[j];
			if(j>=vec[i])
			{
				newdp[j]+=newdp[j-vec[i]];
				newdp[j]%=mod;
			}
		}
		for(int j=0;j<=gen;j++)
		{
			dp[j]=newdp[j];
			newdp[j]=0;
		}
	}
	printf("%I64d\n",dp[gen]);
}