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
#define X 1000000007
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
#define adde(x,y,z) (add(x,y,z),add(y,x,z),++deg[x],++deg[y])
using namespace std;
int n,m,ans[2],ty[N+5],lst[N+5],op[N+5],deg[N+5],ee,lnk[N+5];struct edge {int to,nxt,v;}e[2*N+5];
int nc[N+5];I bool Cir(CI x,CI fi,CI pre=0)
{
	#define E(x) ((((x)-1)^1)+1)
	if(nc[x]) return 0;for(RI i=lnk[x];i;i=e[i].nxt)
		if(i^E(pre)&&(e[i].to==fi||Cir(e[i].to,fi,i))) return 1;return nc[x]=1,0;
}
int cnt,ed,g[N+5],vis[N+5];I void Get(CI x)
{
	++cnt,vis[ed=x]=1;for(RI i=lnk[x];i;i=e[i].nxt) !vis[e[i].to]&&(g[cnt]=e[i].v,Get(e[i].to),0);
}
int s[2],f[N+5][2][2];I void DP(CI op)
{
	RI i,p,x,y;for(i=1;i^cnt;++i) for(p=0;p<=1;++p)
		for(x=0;x<=1;++x) for(y=0;y<=1;++y) Inc(f[i+1][p^(x|y)][y^g[i]],f[i][p][x]);
	for(y=0;y<=1;++y) if(op^!y) for(p=0;p<=1;++p) for(x=0;x<=1;++x) Inc(s[p^(x|y)],f[cnt][p][x]);
	for(i=1;i<=cnt;++i) f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=0;
}
I void Calc()
{
	int res[2]={0,0};for(RI x=0;x<=1;++x) for(RI y=0;y<=1;++y) res[x^y]=(1LL*s[x]*ans[y]+res[x^y])%X;
	ans[0]=res[0],ans[1]=res[1],s[0]=s[1]=0;
}
int main()
{
	RI i,x,y,o;for(scanf("%d%d",&n,&m),ans[0]=i=1;i<=n;++i)
	{
		scanf("%d%d",ty+i,&x),o=abs(x)!=x,lst[x=abs(x)]?(adde(lst[x],i,o^op[x]),lst[x]=-1):(lst[x]=i,op[x]=o);
		if(ty[i]==1) continue;if(scanf("%d",&y),abs(x)==abs(y))
			{vis[i]=1,o^(abs(y)!=y)?(swap(ans[0],ans[1]),lst[x]=0):(Inc(ans[0],ans[1]),ans[1]=ans[0]);continue;}
		o=abs(y)!=y,lst[y=abs(y)]?(adde(lst[y],i,o^op[y]),lst[y]=-1):(lst[y]=i,op[y]=o);
	}
	for(i=1;i<=m;++i) !lst[i]&&(ans[0]=2LL*ans[0]%X,ans[1]=2LL*ans[1]%X);for(i=1;i<=n;++i) if(!vis[i])
	{
		if(!deg[i]) {if(ty[i]==1) {Inc(ans[0],ans[1]);ans[1]=ans[0];continue;}
			int res[2]={(3LL*ans[1]+ans[0])%X,(3LL*ans[0]+ans[1])%X};ans[0]=res[0],ans[1]=res[1];continue;}
		if(!Cir(i,i)) {deg[i]==1&&(cnt=0,Get(i),f[1][0][0]=1,f[1][0][1]=ty[i]!=1,DP(ty[ed]^1?2:0),Calc(),0);continue;}
		for(cnt=0,Get(i),x=lnk[i];e[x].to^ed;x=e[x].nxt);
		e[x].v==0?(f[1][0][0]=1,DP(0),f[1][0][1]=1,DP(1),Calc()):(f[1][0][0]=1,DP(1),f[1][0][1]=1,DP(0),Calc());
	}return printf("%d\n",ans[1]),0;
}