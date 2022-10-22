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
#define M 300000
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,m,s,ee,lnk[N+5];struct edge {int to,nxt,v;}e[2*M+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
}using namespace FastIO;
long long dis[N+5];int IQ[N+5];queue<int> Q;I void SPFA()
{
	RI i,k;for(i=1;i<=n;++i) dis[i]=1e18;dis[s]=0,Q.push(s);
	W(!Q.empty()) for(i=lnk[k=Q.front()],Q.pop(),IQ[k]=0;i;i=e[i].nxt)
		dis[k]+e[i].v<dis[e[i].to]&&(dis[e[i].to]=dis[k]+e[i].v,!IQ[e[i].to]&&(Q.push(e[i].to),IQ[e[i].to]=1));
}
int q[N+5],fa[N+5],sz[N+5],deg[N+5];I void Topo()
{
	RI i,k,H,T;for(k=1;k<=n;++k) for(i=lnk[k];i;i=e[i].nxt) dis[k]+e[i].v==dis[e[i].to]&&++deg[e[i].to];
	sz[fa[q[H=T=1]=s]=s]=1;W(H<=T) for(i=lnk[k=q[H++]];i;i=e[i].nxt) dis[k]+e[i].v==dis[e[i].to]&&
		(fa[e[i].to]=k==s||fa[e[i].to]&&fa[e[i].to]^fa[k]?e[i].to:fa[k],!--deg[e[i].to]&&(++sz[fa[q[++T]=e[i].to]]));
	RI t=0;for(i=1;i<=n;++i) i^s&&(t=max(t,sz[i]));printf("%d\n",t);
}
int main()
{
	RI i,x,y,z;for(read(n),read(m),read(s),i=1;i<=m;++i) read(x),read(y),read(z),add(x,y,z),add(y,x,z);
	return SPFA(),Topo(),0;
}