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
#define LN 18
#define LL long long
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,rt1,rt2,ee,lnk[N+5];struct edge {int to,nxt,v;}e[N<<1];
namespace TD
{
	int q[N+5];LL dis[N+5];I int BFS(CI x)
	{
		RI i,k,H=1,T=1;for(i=1;i<=n;++i) dis[i]=-1;dis[q[1]=x]=0;
		RI f=0;W(H<=T) for(i=lnk[k=q[H++]];i;i=e[i].nxt) 
			!~dis[e[i].to]&&(dis[q[++T]=e[i].to]=dis[k]+e[i].v)>dis[f]&&(f=e[i].to);
		return f;
	}
	I void Get(int& x,int& y) {x=BFS(1),y=BFS(x);}
}
class Tree
{
	private:
		int t,rk[N+5],p[N+5],g[N+5],f[N+5][LN+5];LL ans[N+5],d[N+5],w[N+5];
		struct Data
		{
			int x;LL y;I Data(CI a=0,Con LL& b=0):x(a),y(b){}
			I bool operator < (Con Data& o) Con {return y>o.y;}
		}s[N+5];
		I void dfs1(CI x)
		{
			RI i;for(i=1;i<=LN;++i) f[x][i]=f[f[x][i-1]][i-1];
			for(i=lnk[x];i;i=e[i].nxt) e[i].to^f[x][0]&&
			(
				d[e[i].to]=d[f[e[i].to][0]=x]+e[i].v,dfs1(e[i].to),
				w[e[i].to]+e[i].v>w[x]&&(w[x]=w[g[x]=e[i].to]+e[i].v)
			);
		}
		I void dfs2(CI x,CI c)
		{
			(p[x]=c)==x&&(s[++t]=Data(x,w[x]+d[x]-d[f[x][0]]),0),g[x]&&(dfs2(g[x],c),0);
			for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^f[x][0]&&e[i].to^g[x]&&(dfs2(e[i].to,e[i].to),0);
		}
	public:
		I void Init(CI rt)
		{
			dfs1(rt),dfs2(rt,rt),sort(s+1,s+t+1);
			for(RI i=1;i<=t;++i) rk[s[i].x]=i,ans[i]=ans[i-1]+s[i].y;
		}
		I LL GetAns(CI x,CI k)
		{
			if(rk[p[x]]<=k) return ans[k];RI u=x,v=x;
			for(RI i=LN;~i;--i) rk[p[f[u][i]]]>=k&&(u=f[u][i]);
			for(RI i=LN;~i;--i) rk[p[f[v][i]]]>k&&(v=f[v][i]);
			return d[x]+w[x]+max(-d[f[u][0]]+ans[k-1],-d[f[v][0]]-w[f[v][0]]+ans[k]);
		}
}T1,T2;
int main()
{
	RI Qt,i,x,y,z,c=0;LL s=0,t=0;for(scanf("%d%d",&n,&Qt),i=1;i^n;++i)
		scanf("%d%d%d",&x,&y,&z),s+=z,add(x,y,z),add(y,x,z);TD::Get(rt1,rt2);
	for(i=1;i<=n;++i) c+=!e[lnk[i]].nxt;
	T1.Init(rt1),T2.Init(rt2);W(Qt--) scanf("%d%d",&x,&y),x=(x+t-1)%n+1,
		y=(y+t-1)%n+1,printf("%lld\n",t=2*y>=c?s:max(T1.GetAns(x,2*y-1),T2.GetAns(x,2*y-1)));
	return 0;
}