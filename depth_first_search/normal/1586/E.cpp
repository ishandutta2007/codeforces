#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,s[N+5],qx[N+5],qy[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
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
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
	I void writeln() {pc('\n');}
}using namespace FastIO;
int f[N+5],D[N+5];I void Bd(CI x=1)
{
	for(RI i=lnk[x];i;i=e[i].nxt) !D[e[i].to]&&(D[e[i].to]=D[f[e[i].to]=x]+1,Bd(e[i].to),0);
}
int p[N+5],q[N+5];I void Walk(RI x,RI y)
{
	RI u=0,v=0;W(D[x]>D[y]) p[++u]=x,x=f[x];W(D[y]>D[x]) q[++v]=y,y=f[y];W(x^y) p[++u]=x,q[++v]=y,x=f[x],y=f[y];
	RI i;for(writeln(u+v+1),i=1;i<=u;++i) write(p[i]);write(x);for(i=v;i;--i) write(q[i]);writeln();
}
int main()
{
	RI i,x,y;for(read(n,m),i=1;i<=m;++i) read(x,y),add(x,y),add(y,x);D[1]=1,Bd();
	RI Qt;for(read(Qt),i=1;i<=Qt;++i) read(qx[i],qy[i]),s[qx[i]]^=1,s[qy[i]]^=1;
	RI t=0;for(i=1;i<=n;++i) t+=s[i];if(t) return printf("NO\n%d\n",t>>1),0;
	for(puts("YES"),i=1;i<=Qt;++i) Walk(qx[i],qy[i]);return clear(),0;
}