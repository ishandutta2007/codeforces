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
#define mp make_pair
#define pb push_back
using namespace std;
int n,m,tot,tn[10],ps[10],p[10][10],t[10][10],X[N+5],Y[N+5];
vector<pair<int,int> > res;
namespace NetFlow
{
	#define PS 30
	#define ES 100
	#define add(x,y,f) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f)
	int ee,lnk[PS+5],cur[PS+5],d[PS+5],q[PS+5];struct edge {int F,to,nxt;}e[2*ES+5];
	I void Add(CI x,CI y,CI f) {add(x,y,f),add(y,x,0);}
	I bool BFS()
	{
		RI i,k,H=1,T=1;for(i=1;i<=tot;++i) d[i]=0;d[q[1]=1]=1;W(H<=T&&!d[2])
			for(i=lnk[k=q[H++]];i;i=e[i].nxt) e[i].F&&!d[e[i].to]&&(d[q[++T]=e[i].to]=d[k]+1);
		return d[2]&&memcpy(cur,lnk,sizeof(lnk)),d[2];
	}
	I int DFS(CI x=1,RI f=1e9)
	{
		if(!f||x==2) return f;RI i,t,res=0;for(i=cur[x];i;i=e[i].nxt)
		{
			if(d[e[i].to]^(d[x]+1)||!(t=DFS(e[i].to,min(f,e[i].F)))) continue;
			if(e[i].F-=t,e[((i-1)^1)+1].F+=t,res+=t,!(f-=t)) break;
		}return cur[x]=i,res;
	}
	I int MaxFlow() {RI f=0;W(BFS()) f+=DFS();return f;}
	int M,Mx[10];I void Build()
	{
		RI i,j;for(ee=0,i=1;i<=tot;++i) lnk[i]=0;for(i=1;i<=m;++i) Mx[i]=0;
		for(i=1;i<=m;++i) for(j=i+1;j<=m;++j) t[i][j]&&(Mx[i]+=t[i][j],Mx[j]+=t[i][j],
			Add(1,p[i][j]+m+2,t[i][j]),Add(p[i][j]+m+2,i+2,t[i][j]),Add(p[i][j]+m+2,j+2,t[i][j]),0);
		for(M=0,i=1;i<=m;++i) M+=(Mx[i]-=((i^m)?tn[i+1]:n+1)-ps[i]-1),Add(i+2,2,Mx[i]);
	}
	I void Work()
	{
		RI i,j,k,w;for(i=1;i<=m;++i) for(j=i+1;j<=m;++j)
			if(t[i][j]) for(k=lnk[p[i][j]+m+2];k;k=e[k].nxt)
			{
				if(e[k].to==i+2) for(w=1;w<=t[i][j]-e[k].F;++w) res.pb(mp(tn[i],++ps[j]));
				if(e[k].to==j+2) for(w=1;w<=t[i][j]-e[k].F;++w) res.pb(mp(++ps[i],tn[j]));
			}
	}
	I bool Check()
	{
		Build();for(RI i=1;i<=m;++i) if(Mx[i]<0) return 0;
		return MaxFlow()==M?(Work(),1):0;
	}
}
namespace DFS
{
	int fa[10],vis[10];I bool IsTree()
	{
		memset(vis,0,sizeof(vis));for(RI i=2,x;i<=m;++i)
			{x=i;W(x^1&&vis[x]^i) vis[x]=i,x=fa[x];if(x^1) return 0;}return 1;
	}
	I bool dfs(CI x)
	{
		if(x>m) return IsTree()&&NetFlow::Check();
		for(RI i=1;i<=m;++i) if(x^i&&t[x][i])
		{
			fa[x]=i,--t[x][i],--t[i][x],res.pb(mp(tn[x],tn[i]));
			if(dfs(x+1)) return 1;++t[x][i],++t[i][x],res.pop_back();
		}return 0;
	}
}
int main()
{
	RI i,j,k=0;char s1[10],s2[10];for(scanf("%d",&n),i=1;i^n;++i)
		cin>>s1>>s2,++t[X[i]=strlen(s1)][Y[i]=strlen(s2)],X[i]^Y[i]&&++t[Y[i]][X[i]];
	for(k=m=1;k<=n;++m) k*=10;for(--m,k=0,i=1;i<=m;++i) for(j=i+1;j<=m;++j) p[i][j]=++k;
	for(i=1;i<=m;++i) for(ps[i]=tn[i]=(i^1)?tn[i-1]*10:1,j=1;j<=t[i][i];++j) res.pb(mp(tn[i],++ps[i]));
	if(tot=p[m-1][m]+m+2,!DFS::dfs(2)) return puts("-1"),0;
	for(i=0;i<n-1;++i) printf("%d %d\n",res[i].first,res[i].second);return 0;
}