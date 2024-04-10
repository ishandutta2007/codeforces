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
int n,m,k,f[N+5],g[N+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int main()
{
	RI i,x,y;for(read(n,m,k),i=1;i<=m;++i) read(x,y),(x=fa(x))^(y=fa(y))&&(f[x]=y);
	RI c=0,u=0,t=0;for(i=1;i<=n;++i) ++g[fa(i)];for(i=1;i<=n;++i) !f[i]&&(++c,g[i]==1&&++u,t+=min(g[i],k));
	RI s=0;W(t<2*(c-1)) ++s,--c,u-=2,t-=2,t+=min(2,k);return printf("%d\n",s),0;
}