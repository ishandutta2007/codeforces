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
#define K 20
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,k,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int f[N+5][K<<1];I void dfs1(CI x,CI lst=0)
{
	RI j;for(j=k;j^(k<<1);++j) f[x][j]=a[x];for(RI i=lnk[x];i;i=e[i].nxt)
		if(e[i].to^lst) for(dfs1(e[i].to,x),j=0;j^(k<<1);++j) f[x][j]^=f[e[i].to][(j+1)%(k<<1)];
}
int g[N+5][K<<1];bool ans[N+5];I void dfs2(CI x,CI lst=0)
{
	ans[x]=f[x][0]^g[x][0];for(RI i=lnk[x];i;i=e[i].nxt) if(e[i].to^lst) {for(RI j=0;j^(k<<1);++j)
		g[e[i].to][j]=g[x][(j+1)%(k<<1)]^f[x][(j+1)%(k<<1)]^f[e[i].to][(j+2)%(k<<1)];dfs2(e[i].to,x);}
}
int main()
{
	RI i,x,y;for(read(n),read(k),i=1;i^n;++i) read(x),read(y),add(x,y),add(y,x);
	for(i=1;i<=n;++i) read(a[i]);for(dfs1(1),dfs2(1),i=1;i<=n;++i) putchar(ans[i]|48),putchar(' ');return 0;
}