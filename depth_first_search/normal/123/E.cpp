#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,P,Q,p[N+5],q[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int sz[N+5],sp[N+5],sq[N+5];long long ans;I void dfs(CI x=1,CI lst=0)
{
	sz[x]=1,sp[x]=p[x],sq[x]=q[x];for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
		(dfs(e[i].to,x),sz[x]+=sz[e[i].to],sp[x]+=sp[e[i].to],sq[x]+=sq[e[i].to]);
	x^1&&(ans+=1LL*q[lst]*(P-sp[x])*sz[x]+1LL*q[x]*sp[x]*(n-sz[x]));
}
int main()
{
	RI i,x,y;for(read(n),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);
	for(i=1;i<=n;++i) read(p[i],q[i]),P+=p[i],Q+=q[i];return dfs(),printf("%.12lf\n",(n-1)-1.0*ans/P/Q),0;
}