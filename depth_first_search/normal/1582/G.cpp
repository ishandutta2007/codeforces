#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,a[N+5],f[N+5],St[N+5];char s[N+5];vector<pair<int,int> > g[N+5];
I bool cmp(CI x,CI y) {return (~x?f[x]:0)<(~y?f[y]:0);}
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		int V[N<<2];
	public:
		I void Bd(PT) {if(V[rt]=n,l==r) return;RI mid=l+r>>1;Bd(LT),Bd(RT);}
		I void U(CI L,CI R,CI v,PT)
		{
			if(V[rt]<=v) return;if(L<=l&&r<=R) return (void)(V[rt]=v);
			RI mid=l+r>>1;L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0);
		}
		I void Get(RI v=n,PT)
		{
			if(v=min(v,V[rt]),l==r) return (void)(f[l]=v);RI mid=l+r>>1;Get(v,LT),Get(v,RT);
		}
}S;
int tt[N+5],p[N+5][10],c[N+5][10];I void Init()
{
	RI i,j,x;for(i=2;i<=N;++i) if(!tt[i]) for(j=i;j<=N;j+=i) {p[x=j][++tt[j]]=i;W(!(x%i)) x/=i,++c[j][tt[j]];}
}
int main()
{
	RI i,j,x;for(Init(),scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);scanf("%s",s+1);
	for(i=1;i<=n;++i) for(j=1;j<=tt[a[i]];++j) g[p[a[i]][j]].push_back(make_pair(i,(s[i]=='*'?1:-1)*c[a[i]][j]));
	RI ct=0,z,T;for(S.Bd(),i=1;i<=N;++i) if(z=g[i].size())
	{
		for(j=0;j^z;++j) f[j]=(j?f[j-1]:0)+g[i][j].second;for(T=0,j=z-1;~j;--j)
		{
			W(T&&f[St[T]]>f[j]) --T;if(St[++T]=j,f[St[1]]>=(j?f[j-1]:0)) continue;
			S.U((j?g[i][j-1].first:0)+1,g[i][j].first,g[i][St[lower_bound(St+1,St+T+1,j-1,cmp)-St-1]].first-1);
		}
	}
	long long t=0;for(S.Get(),i=1;i<=n;++i) t+=f[i]-i+1;return printf("%lld\n",t),0;
}