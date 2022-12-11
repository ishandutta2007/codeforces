#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n,m,q;
struct Edge{
	int to,nxt,val;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y,int v)
{
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}

ll sum[100010];   //sum used
int fat[100010],son[100010],siz[100010],dep[100010];
int top[100010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1; int tmp=0;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			sum[edge[i].to]=sum[cur]+edge[i].val;
			dfs1(edge[i].to,cur,dep+1);
			siz[cur]+=siz[edge[i].to];
			if (siz[edge[i].to]>tmp) tmp=siz[edge[i].to],son[cur]=edge[i].to;
		}
}
void dfs2(int cur,int top)
{
	::top[cur]=top;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat[cur]&&edge[i].to!=son[cur])
			dfs2(edge[i].to,edge[i].to);
}
int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fat[top[x]];
	}
	if (dep[x]>dep[y]) return y; return x;
}

namespace Rst
{
	struct Edge{
		int to,nxt,val;
	}edge[50];
	int cnt,last[100010];
	void addedge(int x,int y,int v)
	{
		edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
		edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
	}
	int rec[50];
	bool vis[100010];
}

namespace SSSP
{
	typedef pair<ll,int> P;
	priority_queue<P,vector<P>,greater<P> > que;
	ll dis[100010][50];   //init
	void getdis(int st,int id)
	{
		dis[st][id]=0; que.push((P){dis[st][id],st});
		while (!que.empty())
		{
			P cur=que.top(); que.pop();
			if (dis[cur.second][id]!=cur.first) continue;
			int u=cur.second,v;
			for (int i=last[u];i;i=edge[i].nxt)
				if (v=edge[i].to,dis[u][id]+edge[i].val<dis[v][id])
				{
					dis[v][id]=dis[u][id]+edge[i].val;
					que.push((P){dis[v][id],v});
				}
			for (int i=Rst::last[u];i;i=Rst::edge[i].nxt)
				if (v=Rst::edge[i].to,dis[u][id]+Rst::edge[i].val<dis[v][id])
				{
					dis[v][id]=dis[u][id]+Rst::edge[i].val;
					que.push((P){dis[v][id],v});
				}
		}
	}
}

namespace UF
{
	int fat[100010],dep[100010];
	int find(int x)
	{
		return x==fat[x]?x:fat[x]=find(fat[x]);
	}
	void merge(int x,int y)
	{
		if (dep[x]>dep[y]) fat[y]=x,dep[x]=max(dep[x],dep[y]+1);
		else fat[x]=y,dep[y]=max(dep[y],dep[x]+1);
	}
}

int main()
{
	memset(SSSP::dis,0x7f,sizeof SSSP::dis);
	read(n);read(m);
	for (int i=1;i<=n;i++) UF::fat[i]=i,UF::dep[i]=1;
	for (int i=1,x,y,z,a,b;i<=m;i++)
	{
		read(x);read(y);read(z);
		if ((a=UF::find(x))!=(b=UF::find(y))) UF::merge(a,b),addedge(x,y,z);
		else
		{
			if (!Rst::vis[x]) Rst::vis[x]=true,Rst::rec[++(*Rst::rec)]=x;
			if (!Rst::vis[y]) Rst::vis[y]=true,Rst::rec[++(*Rst::rec)]=y;
			Rst::addedge(x,y,z);
		}
	}
	dfs1(1,0,1),dfs2(1,1);
	for (int i=1;i<=(*Rst::rec);i++) SSSP::getdis(Rst::rec[i],i);
	read(q);
	for (int i=1,x,y;i<=q;i++)
	{
		read(x),read(y);
		ll ans=sum[x]+sum[y]-sum[lca(x,y)]*2;
		for (int j=1;j<=(*Rst::rec);j++) ans=min(ans,SSSP::dis[x][j]+SSSP::dis[y][j]);
		printf("%lld\n",ans);
	}
	return 0;
}