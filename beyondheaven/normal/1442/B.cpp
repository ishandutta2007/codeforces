#include<bits/stdc++.h>
#define MaxN 200123
const int Mod=998244353;

int n,k;
int a[MaxN],rev[MaxN],b[MaxN];
int vis[MaxN];
int nxt[MaxN],pre[MaxN];

inline void Del(int x)
{
	nxt[pre[x]]=nxt[x];
	pre[nxt[x]]=pre[x];
}

inline void Solve()
{
	for(int i=1;i<=n;++i)vis[i]=0;
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i),rev[a[i]]=i;
	for(int i=1;i<=k;++i)
	scanf("%d",b+i),vis[b[i]]=1;
	
	for(int i=1;i<=n;++i)
	nxt[i]=(i==n?0:i+1),pre[i]=i-1;
	
	int ans=1;
	for(int i=1;i<=k;++i)
	{
		int x=rev[b[i]],cnt=0;
		if(nxt[x]&&!vis[a[nxt[x]]])++cnt;
		if(pre[x]&&!vis[a[pre[x]]])++cnt;
		ans=(ans*cnt)%Mod;
		Del(x);
		vis[a[x]]=0;
	}
	printf("%d\n",ans);
}

int main()
{
	int T;scanf("%d",&T);
	while(T--)Solve();
	return 0;
}