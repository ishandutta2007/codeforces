#include<bits/stdc++.h>
#define MaxN 500123
typedef long long LL;
const LL Mod=1e9+7;
inline LL pow_mod(LL a,LL b)
{
	LL res=(a?1:0);
	for(;b;b>>=1,a=a*a%Mod)
	if(b&1)res=res*a%Mod;
	return res;
}
struct Edge
{
	int u,v;
	LL w;
	Edge(int _u=0,int _v=0,LL _w=0):
		u(_u),v(_v),w(_w){}
	friend bool operator<(const Edge&lhs,const Edge&rhs)
	{return lhs.w<rhs.w;}
};
int n,m,k;
LL c[MaxN];
int pre[MaxN];
std::vector<Edge>G;
inline int Find(int x){return pre[x]==x?x:pre[x]=Find(pre[x]);}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	scanf("%lld",c+i);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		G.push_back(Edge(u,v,c[u]^c[v]));
	}
	std::sort(G.begin(),G.end());
	std::iota(pre+1,pre+n+1,1);
	std::vector<int>q;
	LL ans=0,cnt=0;
	for(std::size_t i=0,j;i<G.size();i=j)
	{
		++cnt;LL n0=n;q.clear();
		for(j=i;j<G.size()&&G[j].w==G[i].w;++j)
		{
			const auto&e=G[j];
			if(Find(e.u)!=Find(e.v))
			{
				pre[Find(e.u)]=Find(e.v);
				--n0;
			}
			q.push_back(e.u);q.push_back(e.v);
		}
		ans=(ans+pow_mod(2,n0))%Mod;
		for(auto u:q)pre[u]=u;
	}
	ans=(ans+(pow_mod(2,k)-cnt+Mod)%Mod*pow_mod(2,n))%Mod;
	printf("%lld\n",ans);
	return 0;
}