#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct bian
{
	int nxt,to;
}bi[400040];
int n,m,k,qnum,head[200020],num;
inline void add(int from,int to)
{
	bi[++num]=bian{head[from],to};
	head[from]=num;
}
int id[200020],idnum,up[200020][18],dep[200020];
void dfs(int v,int fa)
{
	id[v]=++idnum;dep[v]=dep[fa]+1;
	up[v][0]=fa;
	for(int i=1;i<=17;++i)up[v][i]=up[up[v][i-1]][i-1];
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=0;i<=17;++i)if(d>>i&1)x=up[x][i];
	if(x==y)return x;
	for(int i=17;~i;--i)if(up[x][i]!=up[y][i])x=up[x][i],y=up[y][i];
	return up[x][0];
}
int qdis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int s[200020],st[200020],tp,p[200020],cnt,a[200020];
bool vis[200020];
queue<int>q;
vector<int>E[200020];
int fr[200020],kd[200020],ans[200020];
int calc(int x,int y,int p)
{
	if(!x||!y)return x+y;
	int d1=qdis(x,p),d2=qdis(y,p);
	if((d1+s[x]-1)/s[x]<(d2+s[y]-1)/s[y]||((d1+s[x]-1)/s[x]==(d2+s[y]-1)/s[y]&&kd[x]<kd[y]))return x;
	else return y;
}
void dfs1(int v)
{
//	printf("%d ",v);
	fr[v]=0;
	if(s[v])fr[v]=v;
	for(auto u:E[v])
	{
		dfs1(u);
		fr[v]=calc(fr[v],fr[u],v);
	}
//	printf("%d %d\n",v,fr[v]);
}
void dfs2(int v,int f)
{
	fr[v]=calc(fr[v],f,v);
	ans[v]=kd[fr[v]];
	for(auto u:E[v])dfs2(u,fr[v]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	scanf("%d",&qnum);
	while(qnum--)
	{
		scanf("%d %d",&k,&m);
		for(int i=1,x;i<=k;++i)
		{
			scanf("%d",&x);scanf("%d",&s[x]);kd[x]=i;
			if(!vis[x])vis[x]=1,q.push(x),p[++cnt]=x;
		}
		for(int i=1,x;i<=m;++i)
		{
			scanf("%d",&x);a[i]=x;
			if(!vis[x])vis[x]=1,q.push(x),p[++cnt]=x;
		}
		if(!vis[1])vis[1]=1,q.push(1),p[++cnt]=1;
		sort(p+1,p+1+cnt,[&](int x,int y){return id[x]<id[y];});
		st[tp=1]=1;
	//	for(int i=1;i<=cnt;++i)printf("%d ",p[i]);printf("\n");
		for(int i=2;i<=cnt;++i)
		{
			int l=lca(st[tp],p[i]);//printf("%d %d %d\n",st[tp],p[i],l);
			while(dep[l]<dep[st[tp]])
			{
				if(dep[l]<=dep[st[tp-1]])
				{
					E[st[tp-1]].emplace_back(st[tp]);//printf("%d %d\n",st[tp-1],st[tp]);
					--tp;
				}
				else
				{
					E[l].emplace_back(st[tp]);//printf("%d %d\n",l,st[tp]);
					st[tp]=l;q.push(l);
				}
			}
			st[++tp]=p[i];
		}
		while(tp>1)E[st[tp-1]].emplace_back(st[tp]),--tp;
		dfs1(1);
		dfs2(1,0);
		for(int i=1;i<=m;++i)printf("%d ",ans[a[i]]);printf("\n");
		while(!q.empty())
		{
			int x=q.front();q.pop();
			E[x].clear();
			vis[x]=0,s[x]=0;
		}
		cnt=0;
	}
	return 0;
}