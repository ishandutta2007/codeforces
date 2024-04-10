#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define LN 20
#define Gmin(x,y) (x>(y)&&(x=(y)))
using namespace std;
int n,m;
namespace G
{
	int ee,lnk[N+5];struct edge {int to,nxt,p;}e[2*N+5];
	I void add(CI x,CI y) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y;}
	int d,dfn[N+5],low[N+5];I void Tarjan(CI x,CI lst=0)
	{
		dfn[x]=low[x]=++d;for(RI i=lnk[x],t=1;i;i=e[i].nxt)
		{
			if(t&&e[i].to==lst) {t=0;continue;}
			if(dfn[e[i].to]) {Gmin(low[x],dfn[e[i].to]);continue;}
			if(Tarjan(e[i].to,x),Gmin(low[x],low[e[i].to]),low[e[i].to]<=dfn[x]) continue;
			e[i].p=e[((i-1)^1)+1].p=1;
		};
	}
	int cnt,c[N+5];I void Col(CI x,CI C,CI lst=0)
	{
		c[x]=C;for(RI i=lnk[x];i;i=e[i].nxt)
			e[i].to^lst&&!e[i].p&&!c[e[i].to]&&(Col(e[i].to,C,x),0);
	}
}
namespace T
{
	int ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
	I void add(CI x,CI y) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y;}
	int d[N+5],f[N+5][LN+5];I void Init(CI x)
	{
		RI i;for(i=1;i<=LN;++i) f[x][i]=f[f[x][i-1]][i-1];
		for(i=lnk[x];i;i=e[i].nxt) e[i].to^f[x][0]&&
			(d[e[i].to]=d[f[e[i].to][0]=x]+1,Init(e[i].to),0);
	}
	I int LCA(RI x,RI y)
	{
		RI i;for(d[x]<d[y]&&(x^=y^=x^=y),i=0;d[x]^d[y];++i) (d[x]^d[y])>>i&1&&(x=f[x][i]);
		if(x==y) return x;for(i=LN;~i;--i) f[x][i]^f[y][i]&&(x=f[x][i],y=f[y][i]);return f[x][0];
	}
	int tg[N+5][2];I void U(CI x,CI y)
	{
		RI z=LCA(x,y);z?(++tg[x][0],++tg[y][1],--tg[z][0],--tg[z][1]):(puts("No"),exit(0),0);
	}
	I void Check(CI x)
	{
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^f[x][0]&&
			(Check(e[i].to),tg[x][0]+=tg[e[i].to][0],tg[x][1]+=tg[e[i].to][1]);
		if(tg[x][0]&&tg[x][1]) puts("No"),exit(0);
	}
}
int main()
{
	using namespace G;RI Qt,i,x,y;scanf("%d%d%d",&n,&m,&Qt);
	for(i=1;i<=m;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(i=1;i<=n;++i) !dfn[i]&&(Tarjan(i),0);for(i=1;i<=n;++i) !c[i]&&(Col(i,++cnt),0);
	for(i=1;i<=ee;i+=2) e[i].p&&(T::add(c[e[i].to],c[e[i+1].to]),T::add(c[e[i+1].to],c[e[i].to]),0);
	for(i=1;i<=cnt;++i) !T::d[i]&&(T::d[i]=1,T::Init(i),0);
	W(Qt--) scanf("%d%d",&x,&y),T::U(c[x],c[y]);
	for(i=1;i<=cnt;++i) T::d[i]==1&&(T::Check(i),0);return puts("Yes"),0;
}