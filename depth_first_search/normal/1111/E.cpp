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
#define M 300
#define LN 17
#define X 1000000007
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,k,rt,o[N+5],Ic[M+5],C[M+5][M+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
namespace VT
{
	int ee,lnk[N+5],vis[N+5];edge e[N<<1];
	int d,dI[N+5],dO[N+5],D[N+5],fa[N+5][LN+1];I void Init(CI x=1)
	{
		RI i,y;for(i=1;;++i) if(!(fa[x][i]=fa[fa[x][i-1]][i-1])) break;
		for(dI[x]=++d,i=::lnk[x];i;i=::e[i].nxt) (y=::e[i].to)^fa[x][0]&&(D[y]=D[fa[y][0]=x]+1,Init(y),0);dO[x]=d;
	}
	I int LCA(RI x,RI y)
	{
		RI i;for(D[x]<D[y]&&(swap(x,y),0),i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(x=fa[x][i]);if(x==y) return x;
		for(i=0;fa[x][i]^fa[y][i];++i);for(--i;~i;--i) fa[x][i]^fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0];
	}
	int f[N+5][M+5];I void dfs(CI x,CI lst=0)
	{
		RI i,j,y;for(j=0;j<=m;++j) f[x][j]=1;
		for(i=lnk[x];i;i=e[i].nxt) if((y=e[i].to)^lst) for(dfs(y,x),j=0;j<=m;++j) f[x][j]=1LL*f[x][j]*f[y][j]%X;
		if(vis[x]==1) {for(j=m;j;--j) f[x][j]=1LL*f[x][j-1]*j%X;f[x][j]=0;}
	}
	I bool cmp(CI x,CI y) {return dI[x]<dI[y];} 
	int S[N+5];I void Solve()
	{
		RI i,j;for(i=1;i<=k;++i) vis[o[i]]=1;!vis[rt]&&(vis[o[++k]=rt]=2),sort(o+1,o+k+1,cmp);
		RI x,t=k;for(i=1;i^t;++i) !vis[x=LCA(o[i],o[i+1])]&&(vis[o[++k]=x]=2);sort(o+1,o+k+1,cmp);
		RI T;for(S[T=1]=o[1],i=2;i<=k;++i) {W(dO[S[T]]<dI[o[i]]) --T;add(S[T],o[i]),add(o[i],S[T]),S[++T]=o[i];}
		RI *F=f[rt];for(dfs(rt),ee=0,i=1;i<=k;++i) vis[o[i]]=lnk[o[i]]=0;
		for(i=0;i<=m;++i) for(j=0;j^i;++j) F[i]=(F[i]-1LL*C[i][j]*F[j]%X+X)%X;
		for(t=0,i=1;i<=m;++i) t=(t+1LL*F[i]*Ic[i])%X;writeln(t);
	}
}
int main()
{
	RI Qt,i,j,x,y;for(read(n,Qt),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);VT::Init();
	for(x=i=1;i<=M;++i) x=1LL*x*i%X;for(Ic[i=M]=QP(x,X-2);i;--i) Ic[i-1]=1LL*Ic[i]*i%X;
	for(C[0][0]=i=1;i<=M;++i) for(C[i][0]=j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%X;
	W(Qt--) {for(read(k,m,rt),i=1;i<=k;++i) read(o[i]);VT::Solve();}return clear(),0;
}