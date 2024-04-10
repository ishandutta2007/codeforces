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
int n,a[N+5],w[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
struct S {int x,y,v,id;I bool operator < (Cn S& o) Cn {return v<o.v;}}s[N+5];
int f[N+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
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
int d,fi[N+5];I void dfs(CI x,CI lst=0)
{
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs(e[i].to,x),!fi[x]&&(fi[x]=fi[e[i].to]),0);
	!fi[x]&&(fi[x]=++d),s[x]=(S){fi[x],d+1,a[x],x};
}
int main()
{
	RI i,x,y;for(read(n),i=1;i<=n;++i) read(a[i]);for(i=1;i^n;++i) read(x,y),add(x,y),add(y,x);dfs(1);
	RI j,k,c=0;long long t=0;for(sort(s+1,s+n+1),i=1;i<=n;i=j+1)
	{
		for(j=i;s[j+1].v==s[i].v;++j);for(k=i;k<=j;++k) (x=fa(s[k].x))^(y=fa(s[k].y))&&(w[s[k].id]=1,++c);
		for(k=i;k<=j;++k) (x=fa(s[k].x))^(y=fa(s[k].y))&&(t+=s[k].v,f[x]=y);
	}
	for(printf("%lld %d\n",t,c),i=1;i<=n;++i) w[i]&&(write(i),0);return clear(),0;
}