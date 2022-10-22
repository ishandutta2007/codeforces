#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define SN 320
#define INF 1e9
#define X 998244353
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
#define Dec(x,y) ((x-=(y))<0&&(x+=X))
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,k,f[N+5],p1[N+5],p2[N+5];
namespace Block
{
	int sz,bl[N+5];I void Bd() {sz=sqrt(n);for(RI i=0;i<=n;++i) bl[i]=i/sz+1;}
	int tot,c[N+5],tg[SN],g[SN][N+5];I void BF(CI l,CI r,CI v)
	{
		RI i,o=bl[l];for(i=(o-1)*sz;i<=min(o*sz-1,n);++i) c[i]+tg[o]<=k&&Dec(tot,f[i]),g[o][c[i]]=0;for(i=l;i<=r;++i) c[i]+=v;
		for(i=(o-1)*sz;i<=min(o*sz-1,n);++i) (c[i]+=tg[o])<=k&&Inc(tot,f[i]),Inc(g[o][c[i]],f[i]);tg[o]=0;
	}
	I void U(CI l,CI r,CI v)
	{
		RI L=bl[l],R=bl[r];if(L==R) return (void)BF(l,r,v);BF(l,L*sz-1,v),BF((R-1)*sz,r,v);
		for(RI i=L+1;i<R;++i) tg[i]+=v,~v?k+1-tg[i]>=0&&Dec(tot,g[i][k+1-tg[i]]):k-tg[i]>=0&&Inc(tot,g[i][k-tg[i]]);
	}
	I void Ins(CI x) {c[x]<=k&&Inc(tot,f[x]),Inc(g[bl[x]][c[x]],f[x]);}
}using namespace Block;
int main()
{
	RI i,x;for(read(n,k),Bd(),f[0]=1,Ins(0),i=1;i<=n;++i)
		read(x),p1[x]&&(U(p2[x],p1[x]-1,-1),p2[x]=p1[x]),U(p1[x],i-1,1),p1[x]=i,f[i]=tot,Ins(i);
	return printf("%d\n",f[n]),0;
}