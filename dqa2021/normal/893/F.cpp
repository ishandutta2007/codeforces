#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}

int n,m;
int w[100010];
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[100010],son[100010],dep[100010],maxdep[100010];
int top[100010],id[100010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=maxdep[cur]=dep;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			dfs1(edge[i].to,cur,dep+1);
			if (maxdep[edge[i].to]>maxdep[cur]) maxdep[cur]=maxdep[edge[i].to],son[cur]=edge[i].to;
		}
}
void dfs2(int cur,int top)
{
	::top[cur]=top; id[cur]=++*id;
	if (!son[cur]) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat[cur]&&edge[i].to!=son[cur])
			dfs2(edge[i].to,edge[i].to);
}

#define mid (l+r>>1)
struct Node{
	int lson,rson,val;
}node[18*200000+10];
int rt[100010],idtot;
void update(int &u,int v,int l,int r,int pos,int val)
{
	node[u=++idtot]=node[v];
	if (l==r){if (!node[u].val||node[u].val>val) node[u].val=val/*!*/; return;}  //the way to update
	if (pos<=mid) update(node[u].lson,node[v].lson,l,mid,pos,val);
	else update(node[u].rson,node[v].rson,mid+1,r,pos,val);
	node[u].val=min(node[node[u].lson].val,node[node[u].rson].val);
}
int query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur].val;
	if (qr<=mid) return query(node[cur].lson,l,mid,ql,qr);
	if (ql>mid) return query(node[cur].rson,mid+1,r,ql,qr);
	return min(query(node[cur].lson,l,mid,ql,mid),query(node[cur].rson,mid+1,r,mid+1,qr));
}

void dfs3(int cur)
{
	if (!son[cur])
	{
		update(rt[cur],0,1,n,id[cur],w[cur]);
		return;
	}
	dfs3(son[cur]);
	update(rt[cur],rt[son[cur]],1,n,id[cur],w[cur]);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat[cur]&&edge[i].to!=son[cur])
		{
			dfs3(edge[i].to);
			for (int j=0;j<=maxdep[edge[i].to]-dep[edge[i].to];j++)
			{
				update(rt[cur],rt[cur],1,n,id[cur]+j+1,query(rt[edge[i].to],1,n,id[edge[i].to]+j,id[edge[i].to]+j));
			}
		}
}

int main()
{
	int rt;
	read(n);read(rt);
	for (int i=1;i<=n;i++) read(w[i]);
	for (int i=2,x,y;i<=n;i++)
	{
		read(x);read(y); addedge(x,y);
	}
	dfs1(rt,0,1); dfs2(rt,rt); dfs3(rt);
	read(m);
	for (int i=1,lastans=0,x,y;i<=m;i++)
	{
//		lastans=0;  //!!!
		read(x);read(y); x=(x+lastans)%n+1;y=(y+lastans)%n;
//		printf("query %d %d\n",x,y);
		printf("%d\n",lastans=query(::rt[x],1,n,id[x],id[x]+min(y,maxdep[x]-dep[x])));
	}
	return 0;
}