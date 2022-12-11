#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;

int n;
std::vector<int>G[MaxN];
int a[MaxN];

LL sum[MaxN];
int leaf[MaxN];

LL val;

bool flag;

inline void Dfs(int u)
{
	if(!G[u].size())leaf[u]=1;
	else leaf[u]=0;
	sum[u]=a[u];
	for(int v:G[u])
	{
		Dfs(v);
		leaf[u]+=leaf[v];
		sum[u]+=sum[v];
	}
}

inline bool Check(LL Mid)
{
	val=Mid;
	for(int u=1;u<=n;++u)
	{
		if(val==0)
		{
			if(sum[u])return false;
		}
		else
		{
			if(sum[u]/val>leaf[u])return false;
			else if(sum[u]/val==leaf[u]&&sum[u]%val!=0)return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i=2,f;i<=n;++i)
	{
		scanf("%d",&f);
		G[f].push_back(i);
	}
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	
	Dfs(1);
	
	LL L=0,R=2e14,Mid,ans=-1;
	while(L<=R)
	{
		Mid=((L+R)>>1);
		if(Check(Mid))
		{
			ans=Mid;
			R=Mid-1;
		}
		else L=Mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}