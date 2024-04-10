#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 150000
#define V 150000000000LL
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
struct Seg
{
	LL k,b;I Seg(Cn LL& x=0,Cn LL& y=0):k(x),b(y){}
	I LL operator () (Cn LL& x) Cn {return k*x+b;}
};
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		Seg P[N<<2];
	public:
		I void Cl(PT) {if(!P[rt].k) return;if(P[rt]=Seg(),l==r) return;RI mid=l+r>>1;Cl(LT),Cl(RT);}
		I LL Q(CI x,PT) {RI mid=l+r>>1;return max(l^r?(x<=mid?Q(x,LT):Q(x,RT)):0,P[rt](x));}
		I void A(Seg s,PT)
		{
			if(!P[rt].k) return (void)(P[rt]=s);RI mid=l+r>>1;s(mid)>P[rt](mid)&&(swap(s,P[rt]),0);
			if(l==r) return;s(l)>P[rt](l)&&(A(s,LT),0),s(r)>P[rt](r)&&(A(s,RT),0);
		}
}S;
namespace T
{
	int u[N+5];LL ans;
	int rt,Sz[N+5],Mx[N+5];I void GetRt(CI x,CI lst,RI sz)
	{
		Sz[x]=1,Mx[x]=0;for(RI i=lnk[x];i;i=e[i].nxt) !u[e[i].to]&&
			e[i].to^lst&&(GetRt(e[i].to,x,sz),Sz[x]+=Sz[e[i].to],Mx[x]=max(Mx[x],Sz[e[i].to]));
		(Mx[x]=max(Mx[x],sz-Sz[x]))<Mx[rt]&&(rt=x);
	}
	I void U(CI x,CI lst,RI c,LL t,LL s)
	{
		S.A(Seg(t+=a[x],s+=1LL*(++c)*a[x]));
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&!u[e[i].to]&&(U(e[i].to,x,c,t,s),0);
	}
	I void Q(CI x,CI lst,RI c,LL t,LL s)
	{
		++c,s+=(t+=a[x]),ans=max(ans,S.Q(c)+s);
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&!u[e[i].to]&&(Q(e[i].to,x,c,t,s),0);
	}
	int T,St[N+5];I void Solve(RI x)
	{
		RI i;for(u[x]=1,S.Cl(),i=lnk[x];i;i=e[i].nxt) !u[e[i].to]&&
			(Q(St[++T]=e[i].to,x,1,a[x],a[x]),U(e[i].to,x,0,0,0),0);ans=max(ans,S.Q(1)+a[x]);
		S.Cl(),S.A(Seg(a[x],a[x]));W(T) Q(St[T],x,0,0,0),U(St[T--],x,1,a[x],a[x]);
		for(i=lnk[x];i;i=e[i].nxt) !u[e[i].to]&&(GetRt(e[i].to,rt=0,Sz[e[i].to]),Solve(rt),0);
	}
}
int main()
{
	RI i,x,y;for(read(n),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);for(i=1;i<=n;++i) read(a[i]);
	using namespace T;return Mx[0]=1e9,GetRt(1,rt=0,n),Solve(rt),printf("%lld\n",ans),0;
}