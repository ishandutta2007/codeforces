#include<bits/stdc++.h>
#define MaxN 100123
#define Size 323
int n,m;
int a[MaxN],bel[MaxN];
struct Query
{
	int l,r,k,id;
	Query(int _l=0,int _r=0,int _k=0,int _id=0):
		l(_l),r(_r),k(_k),id(_id){}
	friend bool operator<(const Query&lhs,const Query&rhs)
	{
		if(bel[lhs.l]==bel[rhs.l])return lhs.r<rhs.r;
		return lhs.l<rhs.l;
	}
}q[MaxN];

inline void Init()
{
	static int c[MaxN],dfn[MaxN],size[MaxN];
	static std::vector<int>G[MaxN];
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	scanf("%d",c+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	int dfs_clock=0;
	std::function<void(int,int)> Dfs=[&](int u,int f)->void
	{
		size[u]=1;
		dfn[u]=++dfs_clock;
		a[dfs_clock]=c[u];
		for(int v:G[u])
		if(v!=f)
		{
			Dfs(v,u);
			size[u]+=size[v];
		}
	};
	
	Dfs(1,0);
	
	for(int i=1,u,k;i<=m;++i)
	{
		scanf("%d%d",&u,&k);
		q[i]=Query(dfn[u],dfn[u]+size[u]-1,k,i);
	}
	
	for(int i=1;i<=n;++i)
	bel[i]=(i-1)/Size+1;
}

int cnt[MaxN],sum[MaxN],blo[MaxN];
inline void Fix(int x,int v)
{
	sum[x]+=v;
	blo[bel[x]]+=v;
}
inline int Calc(int l,int r)
{
	if(l>r)return 0;
	int res=0;
	if(bel[l]==bel[r])
	for(int i=l;i<=r;++i)res+=sum[i];
	else
	{
		for(int i=l;bel[i]==bel[l];++i)res+=sum[i];
		for(int i=r;bel[i]==bel[r];--i)res+=sum[i];
		for(int i=bel[l]+1;i<bel[r];++i)res+=blo[i];
	}
	return res;
}
inline void Add(int x)
{
	Fix(cnt[a[x]],-1);
	++cnt[a[x]];
	Fix(cnt[a[x]],1);
}
inline void Del(int x)
{
	Fix(cnt[a[x]],-1);
	--cnt[a[x]];
	Fix(cnt[a[x]],1);
}

int ans[MaxN];
inline void Solve()
{
	std::sort(q+1,q+m+1);
	for(int i=1,l=1,r=0;i<=m;++i)
	{
		while(l<q[i].l)Del(l++);
		while(l>q[i].l)Add(--l);
		while(r<q[i].r)Add(++r);
		while(r>q[i].r)Del(r--);
		ans[q[i].id]=Calc(q[i].k,n);
	}
	for(int i=1;i<=m;++i)
	printf("%d\n",ans[i]);
}
int main()
{
	Init();
	Solve();
	return 0;
}