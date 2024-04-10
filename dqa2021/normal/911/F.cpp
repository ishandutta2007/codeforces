#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

int n;
bool vis[200010];    //vis used
struct Edge{
	int to,nxt;
}edge[400010];
int cnt,last[200010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}

int fat[200010],dep[200010];
int maxdep,maxson,rt;
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep;
	if (dep>maxdep) maxdep=dep,maxson=cur;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat) dfs1(edge[i].to,cur,dep+1);
}
ll ans;
struct Rec{
	int a,b;
}rec[200010];
int rectop;
int stk[200010];
void dfs3(int cur,int maxnode,int dis)
{
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat[cur])
			dfs3(edge[i].to,maxnode,dis+1);
	rec[++rectop]=(Rec){cur,maxnode};
	ans+=dis;
}
void dfs2(int cur)
{
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		if (edge[i].to==fat[cur]) continue;
		if (!vis[edge[i].to])
			if (dep[cur]>dep[maxson]-dep[cur]+1) dfs3(edge[i].to,rt,dep[cur]);
			else dfs3(edge[i].to,maxson,dep[maxson]-dep[cur]+1);
		else dfs2(edge[i].to);
	}
}

int que[200010],hd,tl;
int bfs()
{
	que[++tl]=1; vis[1]=true;
	while (hd<tl)
	{
		int u=que[++hd];
		for (int i=last[u];i;i=edge[i].nxt)
			if (!vis[edge[i].to])
				vis[edge[i].to]=true,que[++tl]=edge[i].to;
	}
	return que[tl];
}

int main()
{
	scanf("%d",&n);
	for (int i=2,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs1(rt=bfs(),0,1);
	memset(vis,false,sizeof vis);
	int tmp=maxson; vis[tmp]=true; stk[++(*stk)]=tmp;
	for (;fat[tmp];tmp=fat[tmp],vis[tmp]=true,stk[++(*stk)]=tmp);
	dfs2(rt);
	ans+=(ll)(*stk)*((*stk)-1)/2;
	printf("%lld\n",ans);
	for (int i=1;i<=rectop;i++) printf("%d %d %d\n",rec[i].a,rec[i].b,rec[i].a);
	for (int i=1;i<(*stk);i++) printf("%d %d %d\n",stk[i],stk[(*stk)],stk[i]);
	return 0;
}