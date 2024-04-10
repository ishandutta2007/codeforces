#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,a[N+5],ee,lnk[N+5];LL s;struct edge {int to,nxt;}e[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
}F;
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (V[x]=min(V[x<<1],V[x<<1|1]))
		#define PD(x) F[x]&&(T(x<<1,F[x]),T(x<<1|1,F[x]),F[x]=0)
		#define T(x,v) (V[x]+=v,F[x]+=v)
		LL V[N<<2],F[N<<2];
	public:
		I void Build(PT)
		{
			if(V[rt]=1e18,l==r) return;RI mid=l+r>>1;Build(LT),Build(RT);
		}
		I void U(CI x,LL v)
		{
			RI l=1,r=n,rt=1,mid;W(l^r) PD(rt),mid=l+r>>1,x<=mid?(r=mid,rt<<=1):(l=mid+1,(rt<<=1)|=1);
			V[rt]=min(V[rt],v);W(rt>>=1) PU(rt);
//			if(l==r) return (void)(V[rt]=min(V[rt],v));RI mid=l+r>>1;
//			PD(rt),x<=mid?U(x,v,LT):U(x,v,RT),PU(rt);
		}
		I LL Q(CI x)
		{
			RI l=1,r=n,rt=1,mid;W(l^r) PD(rt),mid=l+r>>1,x<=mid?(r=mid,rt<<=1):(l=mid+1,(rt<<=1)|=1);return V[rt];
//			if(l==r) return V[rt];RI mid=l+r>>1;return PD(rt),x<=mid?Q(x,LT):Q(x,RT);
		}
		I void A(CI L,CI R,Con LL& v,PT)
		{
			if(L<=l&&r<=R) return (void)T(rt,v);RI mid=l+r>>1;PD(rt);
			L<=mid&&(A(L,R,v,LT),0),R>mid&&(A(L,R,v,RT),0),PU(rt);
		}
		I LL G(CI L,CI R,PT)
		{
			if(L==l&&r==R) return V[rt];RI mid=l+r>>1;PD(rt);
			if(R<=mid) return G(L,R,LT);if(L>mid) return G(L,R,RT);return min(G(L,mid,LT),G(mid+1,R,RT));
		}
}S;
class LongChainDissection
{
	private:
		int d,g[N+5],C[N+5],Mx[N+5],id[N+5];
	public:
		I void Init(CI x=1)
		{
			RI i;for(i=lnk[x];i;i=e[i].nxt) (Init(e[i].to),Mx[e[i].to]>Mx[C[x]]&&(C[x]=e[i].to));Mx[x]=Mx[C[x]]+1;
		}
		I int DP(CI x=1)
		{
			if(id[x]=d++,!C[x]) return S.U(id[x]+1,a[x]),g[x]=1;g[x]=DP(C[x]);
			RI i;for(i=lnk[x];i;i=e[i].nxt) e[i].to^C[x]&&(g[x]+=DP(e[i].to));
			RI lim=min(Mx[x],m);S.A(id[x]+2,id[x]+lim,a[x]);
			RI j;LL t;for(i=lnk[x];i;i=e[i].nxt) if(e[i].to^C[x])
				for(j=min(Mx[e[i].to],m-1);j;--j) (t=S.Q(id[e[i].to]+j)+a[x])<=s&&(S.U(id[x]+j+1,t),0);
			S.G(id[x]+2,id[x]+lim)>s&&(S.U(id[x]+1,a[x]),++g[x]);return g[x];
		}
}T;
int main()
{
	RI i,x;for(F.read(n),F.read(m),F.read(s),i=1;i<=n;++i) if(F.read(a[i]),a[i]>s) return puts("-1"),0;
	for(i=2;i<=n;++i) F.read(x),add(x,i);return S.Build(),T.Init(),printf("%d\n",m^1?T.DP():n),0;
}