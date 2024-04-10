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
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int g[N+5],sz[N+5];I void Init(CI x=1,CI lst=0)
{
	sz[x]=1;for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
		(Init(e[i].to,x),sz[x]+=sz[e[i].to],sz[e[i].to]>sz[g[x]]&&(g[x]=e[i].to));
}
#define A(x) (!s[++c[x]]&&++p,s[c[x]]+=x)
#define D(x) (!(s[c[x]--]-=x)&&--p)
int p,c[N+5];LL s[N+5];I void T(CI x,CI lst,CI op)
{
	op?A(a[x]):D(a[x]);for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(T(e[i].to,x,op),0);
}
LL ans[N+5];I void DSU(CI x=1,CI lst=0)
{
	RI i;for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&e[i].to^g[x]&&(DSU(e[i].to,x),T(e[i].to,x,0),0);
	if(g[x]) for(DSU(g[x],x),i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&e[i].to^g[x]&&(T(e[i].to,x,1),0);
	A(a[x]),ans[x]=s[p];
}
int main()
{
	RI i,x,y;for(read(n),i=1;i<=n;++i) read(a[i]);for(i=1;i^n;++i) read(x,y),add(x,y),add(y,x);
	for(Init(),DSU(),i=1;i<=n;++i) write(ans[i]);return clear(),0;
}