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
#define M 300000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,d[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[2*M+5];
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
}using namespace FastIO;
int op,vis[M+5];I void Euler(CI x) {RI y;for(RI& i=lnk[x];i;i=e[i].nxt)
	!vis[i+1>>1]&&(vis[i+1>>1]=1,Euler(y=e[i].to),(op^=1)?(write(x),writeln(y)):(write(y),writeln(x)),0);}
int main()
{
	RI i,x,y;for(read(n,m),i=1;i<=m;++i) read(x,y),add(x,y),add(y,x),d[x]^=1,d[y]^=1;
	RI t=0;for(i=1;i<=n;++i) d[i]&&(t?(++m,add(t,i),add(i,t),t=0):t=i);m&1&&(++m,add(1,1),add(1,1));
	writeln(m),Euler(1);return clear(),0;
}