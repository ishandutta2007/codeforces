#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 500000
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].w=z)
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp void write(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int n,m,a[N+5],d[N+5],q[N+5],vis[N+5],ee,lnk[N+5];struct edge {int to,nxt,w;}e[N+5];
int main()
{
	int i,x,y,z;if(read(n,m),n==1) return puts("0\n0"),0;
	for(i=1;i<=m;++i) read(x,y,z),add(y,x,z);
	int H,T,k;q[H=T=1]=n;while(H<=T) for(i=lnk[k=q[H++]];i;i=e[i].nxt)
		vis[e[i].to]^3&&((vis[e[i].to]|=1<<e[i].w)==3?d[q[++T]=e[i].to]=d[k]+1:a[e[i].to]=e[i].w^1);
	for(vis[1]^3?puts("-1"):printf("%d\n",d[1]),i=1;i<=n;++i) putchar(48|a[i]);return 0;
}