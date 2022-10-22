#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define V 1000000
#define LL long long
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,ee,lnk[V+5];struct edge {int to,nxt,v;}e[3*V+5];LL k,f[V+5],g[V+5][20];
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
int main()
{
	RI i,j,x;for(i=2;i<=V;++i) if(!lnk[i]) for(j=i;j<=V;j+=i) {add(j,i),x=j;W(!(x%i)) x/=i,++e[ee].v;}
	for(read(n),i=1;i<=n;++i) read(x),read(g[x][1]);read(k);
	RI t;for(i=V;i;--i)
	{
		for(t=0,j=1;j^20;++j) j<=t+g[i][t]?(g[i][t]+=g[i][j],g[i][j]=0):t=j;
		for(j=1;j^20;++j) if(g[i][j])
		{
			if(j>k) {f[i]+=g[i][j];continue;}j+g[i][j]-1>k&&(f[i]+=j+g[i][j]-1-k,g[i][j]=k-(j-1));
			for(x=lnk[i-1];x;x=e[x].nxt) g[e[x].to][j+1]+=g[i][j]*e[x].v;
		}
	}
	for(t=0,i=1;i<=V;++i) f[i]&&++t;for(writeln(t),i=1;i<=V;++i) f[i]&&(write(i),writeln(f[i]),0);return clear(),0;
}