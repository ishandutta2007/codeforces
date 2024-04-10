#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
#define LL long long
#define INF (LL)1e18
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,ff=1;W(!D) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,m,a[3][N+5];LL V1[N+5],V2[N+5],A[N+5],B[N+5],C[N+5];
struct Il {int l,r,v;bool operator < (Cn Il& o) Cn {return r<o.r;}};vector<Il> g[50];
struct TreeArray
{
	int lim;LL a[N+5];I void Init(CI l,CI r) {lim=r+1;for(RI i=l;i<=lim;++i) a[i]=-INF;}
	I void U(RI x,LL v) {++x;W(x&&a[x]<v) a[x]=v,x-=x&-x;}
	I LL Q(RI x) {LL t=-INF;++x;W(x<=lim) t=max(t,a[x]),x+=x&-x;return t;}
}T;
int ct;LL ans=-INF;I void Solve(CI o,CI l,CI r,LL c)
{
	if(l==r) return (void)(ans=max(ans,V1[l]+V2[l]-c));
	RI i,u=l+r>>1;LL v1=-INF,v2=-INF;for(i=l;i<=u;++i) v1=max(v1,V1[i]);for(;i<=r;++i) v2=max(v2,V2[i]);ans=max(ans,v1+v2-c);
	LL t;vector<Il>::iterator it;for(T.Init(l,r),i=l-1,it=g[o].begin();i<=r;++i)
		{t=-INF;W(it!=g[o].end()&&(it->r==i||i==r)) t=max(t,T.Q(max(it->l,l)-1)-it->v),++it;i<u&&(t=max(t,V1[i+1])),T.U(i,t);}
	for(i=u+1;i<=r;++i) ans=max(ans,T.Q(i)+V2[i]),T.U(i,t);
	RI lp=++ct,rp=++ct;LL lc=c,rc=c;g[lp].clear(),g[rp].clear();
	for(it=g[o].begin();it!=g[o].end();++it)
	{
		if(it->l<=l&&u<=it->r) lc=min(lc,(LL)it->v);else if(max(it->l,l)<=min(it->r,u)) g[lp].push_back(*it);
		if(it->l<=u+1&&r<=it->r) rc=min(rc,(LL)it->v);else if(max(it->l,u+1)<=min(it->r,r)) g[rp].push_back(*it);
	}
	Solve(lp,l,u,lc),Solve(rp,u+1,r,rc),ct-=2;
}
int main()
{
	RI i,j;for(read(n,m),j=0;j<=2;++j) for(i=1;i<=n;++i) read(a[j][i]);
	RI l,r,v;LL c=INF;for(i=1;i<=m;++i) read(l,r,v),l==1&&r==n?c=min(c,(LL)v):(g[0].push_back((Il){l,r,v}),0);
	for(i=1;i<=n;++i) A[i]=A[i-1]+a[0][i],B[i]=B[i-1]+a[1][i];for(i=n;i;--i) C[i]=C[i+1]+a[2][i];
	for(i=1;i<=n;++i) V1[i]=A[i]-B[i-1],V2[i]=C[i]+B[i];
	return sort(g[0].begin(),g[0].end()),Solve(0,1,n,c),printf("%lld\n",ans),0;
}