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
#define K 50
#define X 1000000007
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,k,Fc[N+5],px[K+5],py[K+5],pv[K+5];
int ee,lnk[2*K+5];struct edge {int to,nxt,v;}e[2*K+5];
struct Discretization
{
	int dc,dv[K+5];I void A(CI v) {dv[++dc]=v;}
	I void Init() {sort(dv+1,dv+dc+1),dc=unique(dv+1,dv+dc+1)-dv-1;}
	I int GV(CI x) {return lower_bound(dv+1,dv+dc+1,x)-dv;} 
}Dx,Dy;
namespace S1
{
	int ct,G[K+5],sz[1<<K/2];
	int c1,c2,q1[K+5],q2[K+5],vis[2*K+5];void dfs(CI x)
	{
		vis[x]=1,x<=Dx.dc?q1[++c1]=x:q2[++c2]=x;
		for(RI i=lnk[x];i;i=e[i].nxt) !vis[e[i].to]&&(dfs(e[i].to),0);
	}
	int id[2*K+5],f[2][1<<K/2];I void DP()
	{
		RI i,j,p,o,v;if(c1<c2) for(swap(c1,c2),i=1;i<=c1;++i) swap(q1[i],q2[i]);
		RI l=1<<c2;for(i=1;i<=c2;++i) id[q2[i]]=i-1;for(i=1;i^l;++i) f[0][i]=0;
		for(f[0][0]=i=1;i<=c1;++i) for(j=l-1;~j;--j) if(v=f[i&1][j]=f[i&1^1][j])
			for(p=lnk[q1[i]];p;p=e[p].nxt) o=id[e[p].to],!(j>>o&1)&&(f[i&1][j^(1<<o)]=(f[i&1][j^(1<<o)]+1LL*v*e[p].v)%X);
		RI t=0;for(i=ct;~i;--i) for(j=1;j^l;++j) G[i+sz[j]]=(G[i+sz[j]]+1LL*G[i]*f[c1&1][j])%X;ct+=c2;
	}
	I void Solve()
	{
		RI i,j,p,v,o,l=1<<K/2;for(i=1;i^l;++i) sz[i]=sz[i>>1]+(i&1);
		for(G[0]=i=1;i<=Dx.dc;++i) !vis[i]&&(c1=c2=0,dfs(i),DP(),0);
		RI t=0;for(i=0;i<=ct;++i) t=(t+1LL*G[i]*Fc[n-i])%X;printf("%d\n",t);
	}
}
namespace S2
{
	int c,F[K+5],G[K+5];struct line {int x,y,v;}s[K+5];
	int vis[2*K+5];void dfs(CI x,CI lst=0)
	{
		vis[x]=1;for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&
			(vis[e[i].to]?x<e[i].to&&(s[++c]=(line){x,e[i].to,e[i].v},0):(dfs(e[i].to,x),0));
	}
	int fg[2*K+5],f[2*K+5][K+5][2],g[2*K+5];void DP(CI x)
	{
		RI i,j,k,y;W(f[x][g[x]][0]=f[x][g[x]][1]=0,g[x]) --g[x];
		for(vis[x]=f[x][0][0]=1,i=lnk[x];i;i=e[i].nxt)
		{
			if(vis[e[i].to]) continue;
			for(DP(y=e[i].to),j=g[x];~j;--j) for(k=g[y];~k;--k)
				k&&(f[x][j+k][0]=(f[x][j+k][0]+1LL*f[x][j][0]*f[y][k][0])%X),
				k&&(f[x][j+k][1]=(f[x][j+k][1]+1LL*f[x][j][1]*f[y][k][0])%X),
				f[x][j+k][1]=(f[x][j+k][1]+1LL*f[x][j][0]*f[y][k][1]%X*e[i].v)%X;
			g[x]+=g[y];
		}
		if(fg[x]) {for(i=0;i<=g[x];++i) f[x][i][1]=0;return;}
		for(i=g[x];~i;--i) f[x][i+1][0]=(f[x][i+1][0]+f[x][i][1])%X,f[x][i][1]=f[x][i][0];f[x][g[x]+1][0]&&++g[x];
	}
	int tt,vv;I void Work()
	{
		RI i,j,k,ct=0;for(i=1;i<=Dx.dc+Dy.dc;++i) vis[i]=0;
		for(F[0]=i=1;i<=Dx.dc;++i) if(!vis[i])
			{for(DP(i),j=ct;~j;--j) for(k=1;k<=g[i];++k) F[j+k]=(F[j+k]+1LL*F[j]*f[i][k][0])%X;ct+=g[i];}
		for(i=0;i<=ct;++i) G[tt+i]=(G[tt+i]+1LL*F[i]*vv)%X,F[i]=0;
	}
	void BF(CI x)
	{
		if(x>c) return Work();BF(x+1);if(fg[s[x].x]||fg[s[x].y]) return;
		RI v=vv;fg[s[x].x]=fg[s[x].y]=1,++tt,vv=1LL*vv*s[x].v%X,BF(x+1),fg[s[x].x]=fg[s[x].y]=0,--tt,vv=v;
	}
	I void Solve()
	{
		RI i;for(i=1;i<=Dx.dc;++i) !vis[i]&&(dfs(i),0);vv=1,BF(1);
		RI t=0;for(i=0;i<=Dx.dc;++i) t=(t+1LL*G[i]*Fc[n-i])%X;printf("%d\n",t);
	}
}
int main()
{
	RI i;for(scanf("%d%d",&n,&k),Fc[0]=i=1;i<=n;++i) Fc[i]=1LL*Fc[i-1]*i%X;
	for(i=1;i<=k;++i) scanf("%d%d%d",px+i,py+i,pv+i),Dx.A(px[i]),Dy.A(py[i]),--pv[i];
	RI x,y;for(Dx.Init(),Dy.Init(),i=1;i<=k;++i) x=Dx.GV(px[i]),y=Dy.GV(py[i]),add(x,Dx.dc+y,pv[i]),add(Dx.dc+y,x,pv[i]);
	return Dx.dc+Dy.dc<=0.6*k?S1::Solve():S2::Solve(),0;
}