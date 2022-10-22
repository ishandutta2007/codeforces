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
int n,a[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
int Mx[N+5];long long ans;void dfs(CI x,CI lst=0)
{
	RI i,fg=0;for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs(e[i].to,x),Mx[x]=max(Mx[x],Mx[e[i].to]),fg=1);
	if(!fg) return (void)(Mx[x]=a[x],ans+=a[x]);if(lst) return (void)(Mx[x]<a[x]&&(ans+=a[x]-Mx[x],Mx[x]=a[x]));
	RI Sx=Mx[x]=0;for(i=lnk[x];i;i=e[i].nxt) Mx[e[i].to]>Mx[x]?(Sx=Mx[x],Mx[x]=Mx[e[i].to]):Sx=max(Sx,Mx[e[i].to]);
	ans+=max(a[x]-Sx,0)+max(a[x]-Mx[x],0);
}
int main()
{
	RI i,rt=0;for(read(n),i=1;i<=n;++i) read(a[i]),a[i]>a[rt]&&(rt=i);
	RI x,y;for(i=1;i^n;++i) read(x,y),add(x,y),add(y,x);return dfs(rt),printf("%lld\n",ans),0;
}