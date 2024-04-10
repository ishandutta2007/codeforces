#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 300000
#define LN 19
#define LL long long
#define INF (LL)1e18
#define add(x,y,z0,z1) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v0=z0,e[ee].v1=z1)
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
	Tp void writeln(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,ee,lnk[N+5];LL a[N+5];struct edge {int to,nxt;LL v0,v1;}e[N<<1];
LL f[N+5],g[N+5],h[N+5];void dfs1(CI x,CI lst=0)
{
	f[x]=g[x]=a[x];for(int i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^lst&&
		(dfs1(y,x),(h[y]=f[y]+e[i].v0+e[i].v1)<f[x]?(g[x]=f[x],f[x]=h[y]):g[x]=min(g[x],h[y]));
}
LL F[N+5];void dfs2(CI x,CI lst=0,LL o=INF)
{
	F[x]=min(f[x],o);for(int i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^lst&&(dfs2(y,x,min(o,h[y]^f[x]?f[x]:g[x])+e[i].v0+e[i].v1),0);
}
namespace T
{
	int D[N+5],f[N+5][LN+1];LL E0[N+5],E1[N+5];
	struct Data
	{
		int x,y;LL v[2][2];
		LL* operator [] (CI x) {return v[x];}Cn LL* operator [] (CI x) Cn {return v[x];}
		Data operator + (Cn Data& o) Cn
		{
			if(!~x) return o;if(!~o.x) return *this;Data t;t.x=x,t.y=o.y;
			t[0][0]=min(v[0][0]+o[0][0]+E0[y],v[0][1]+o[1][0]+E1[y]);
			t[0][1]=min(v[0][0]+o[0][1]+E0[y],v[0][1]+o[1][1]+E1[y]);
			t[1][0]=min(v[1][0]+o[0][0]+E0[y],v[1][1]+o[1][0]+E1[y]);
			t[1][1]=min(v[1][0]+o[0][1]+E0[y],v[1][1]+o[1][1]+E1[y]);return t;
		}
		void Rev() {swap(x,y),swap(v[0][1],v[1][0]);}
	}g[N+5][LN+1];
	void Init(CI x,CI lst=0)
	{
		int i,y;g[x][0].x=g[x][0].y=x,g[x][0][0][1]=g[x][0][1][0]=F[x];
		for(i=1;g[x][i]=g[x][i-1]+g[f[x][i-1]][i-1],f[x][i]=f[f[x][i-1]][i-1];++i);
		for(i=lnk[x];i;i=e[i].nxt) (y=e[i].to)^lst&&(E0[y]=e[i].v0,E1[y]=e[i].v1,D[y]=D[f[y][0]=x]+1,Init(y,x),0);
	}
	Data Get(int x,int y)
	{
		int i;Data tx,ty;tx.x=tx.y=ty.x=ty.y=-1;
		if(D[x]>D[y]) {for(i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(tx=tx+g[x][i],x=f[x][i]);if(x==y) return tx+g[x][0];}
		else {for(i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(ty=ty+g[y][i],y=f[y][i]);if(x==y) return (ty=ty+g[y][0]).Rev(),ty;}
		for(i=0;f[x][i]^f[y][i];++i);for(--i;~i;--i) f[x][i]^f[y][i]&&(tx=tx+g[x][i],ty=ty+g[y][i],x=f[x][i],y=f[y][i]);
		return (ty=ty+g[y][1]).Rev(),tx+g[x][0]+ty;
	}
	LL Q(CI a,CI b) {return Get(a+1>>1,b+1>>1)[a&1^1][b&1^1];}
}
int main()
{
	int i,x,y;LL z0,z1;for(read(n),i=1;i<=n;++i) read(a[i]);
	for(i=1;i^n;++i) read(x,y,z0,z1),add(x,y,z0,z1),add(y,x,z0,z1);dfs1(1),dfs2(1),T::Init(1);
	int Qt;read(Qt);while(Qt--) read(x,y),writeln(T::Q(x,y));return 0;
}