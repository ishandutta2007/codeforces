#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5],b[N+5],c[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
int ct,pd[N+5],IS[N+5];I bool dfs(CI x)
{
	if(pd[x]) return 1;pd[x]=IS[x]=1;
	for(RI i=lnk[x];i;i=e[i].nxt) if(IS[e[i].to]||!dfs(e[i].to)) return 0;return IS[x]=0,1;
}
int main()
{
	RI Tt,i,j,z,p,t=0;read(Tt);W(Tt--)
	{
		for(read(n),i=0;i<=n;++i) c[i]=0;
		for(i=1;i<=n;++i) read(a[i]),++c[a[i]];for(i=1;i<=n;++i) read(b[i]);
		for(t=0,i=1;i<=n;++i) t<c[i]&&(t=c[i],p=i);
		for(ee=0,i=1;i<=n;++i) lnk[i]=pd[i]=IS[i]=0;for(i=1;i<=n;++i) add(a[i],b[i]);
		for(pd[p]=i=1;i<=n;++i) if(!dfs(i)) break;puts(i<=n?"WA":"AC");
	}return 0;
}