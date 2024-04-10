#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}

int n,m,q,w[200010]; int idtot;
struct Edge{
	int to,nxt;
}edge[400010];
int cnt=1,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
namespace R  //rebuild tree
{
	struct Edge{
		int to,nxt;
	}edge[400010];
	int cnt=1,last[200010];
	inline void addedge(int x,int y)
	{
		//printf("R::addedge %d %d\n",x,y);
		edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
		edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
	}
	typedef pair<int,int> P;
	priority_queue<P,vector<P>,greater<P> > que[200010];
	int fat[200010],son[200010],dep[200010],siz[200010];
	int top[200010],id[200010],od[200010];
	void dfs1(int cur,int fat,int dep)
	{
		R::dep[cur]=dep; R::fat[cur]=fat; siz[cur]=1;
		for (int i=last[cur];i;i=edge[i].nxt)
			if (edge[i].to^fat)
			{
				dfs1(edge[i].to,cur,dep+1);
				siz[cur]+=siz[edge[i].to];
				if (!son[cur]||siz[son[cur]]<siz[edge[i].to]) son[cur]=edge[i].to;
			}
	}
	void dfs2(int cur,int top)
	{
		R::top[cur]=top; id[cur]=++*id; od[*id]=cur;
		if (siz[cur]==1) return;
		dfs2(son[cur],top);
		for (int i=last[cur];i;i=edge[i].nxt)
			if (edge[i].to!=fat[cur]&&edge[i].to!=son[cur])
				dfs2(edge[i].to,edge[i].to);
	}
	#define mid (l+r>>1)
	#define lson (cur<<1)
	#define rson (cur<<1|1)
	struct Node{
		int minn;
	}node[800010];
	void build(int cur,int l,int r)
	{
		if (l==r) return node[cur].minn=w[od[l]],void();
		build(lson,l,mid); build(rson,mid+1,r);
		node[cur].minn=min(node[lson].minn,node[rson].minn);
	}
	void update(int cur,int l,int r,int pos)
	{
		if (l==r) return node[cur].minn=w[od[l]],void();
		if (pos<=mid) update(lson,l,mid,pos);
		else update(rson,mid+1,r,pos);
		node[cur].minn=min(node[lson].minn,node[rson].minn);
	}
	int query(int cur,int l,int r,int ql,int qr)
	{
		if (l==ql&&r==qr) return node[cur].minn;
		if (qr<=mid) return query(lson,l,mid,ql,qr);
		if (ql>mid) return query(rson,mid+1,r,ql,qr);
		return min(query(lson,l,mid,ql,mid),query(rson,mid+1,r,mid+1,qr));
	}
	int doit(int x,int y)
	{
		int res=0x7fffffff;
		while (top[x]^top[y])
		{
			if (dep[top[x]]<dep[top[y]]) swap(x,y);
			res=min(res,query(1,1,idtot,id[top[x]],id[x]));
			x=fat[top[x]];
		}
		if (dep[x]>dep[y]) swap(x,y);
		res=min(res,query(1,1,idtot,id[x],id[y]));
		if (x>n) res=min(res,w[fat[x]]);
		return res;
	}
	#undef mid
	#undef lson
	#undef rson
	void solve()
	{
		dfs1(1,0,1); dfs2(1,1);
		for (int i=1;i<=n;i++) if (fat[i]) que[fat[i]].push((P){w[i],i});
		for (int i=n+1;i<=idtot;i++) w[i]=que[i].top().first;
		build(1,1,idtot);   //caution idtot and n
		char opt[3]; int x,y;
		while (q--)
		{
			scanf("%s",opt); x=read(),y=read();
			if (opt[0]=='C')
			{
				w[x]=y; update(1,1,idtot,id[x]);
				if (fat[x])
				{
					que[fat[x]].push((P){w[x],x});
					while (que[fat[x]].top().first!=w[que[fat[x]].top().second]) que[fat[x]].pop();
					w[fat[x]]=que[fat[x]].top().first;
					update(1,1,idtot,id[fat[x]]);
				}
				continue;
			}
			printf("%d\n",doit(x,y));
		}
	}
}
int dfn[100010],low[100010];
int stk[100010];  //siz
void tarjan(int cur)
{
	dfn[cur]=low[cur]=++*dfn;
	stk[++*stk]=cur;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (!dfn[edge[i].to])
		{
			int tmp=*stk;
			tarjan(edge[i].to);
			low[cur]=min(low[cur],low[edge[i].to]);
			if (low[edge[i].to]>=dfn[cur])
			{
				idtot++;
				while ((*stk)!=tmp) R::addedge(stk[*stk],idtot),--*stk;
				R::addedge(cur,idtot);
			}
		}
		else low[cur]=min(low[cur],dfn[edge[i].to]);
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read(),m=read(),q=read(); idtot=n;
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<=m;i++) addedge(read(),read());
	tarjan(1);
	R::solve();
	return 0;
}