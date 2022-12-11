#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;

int n,q;
struct Edge{
	int to,nxt;
}edge[100010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int fat[100010],son[100010],siz[100010],dep[100010];
int top[100010],id[100010];
void dfs1(int cur,int dep)
{
	::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs1(edge[i].to,dep+1);
		siz[cur]+=siz[edge[i].to];
		if (!son[cur]||siz[edge[i].to]>siz[son[cur]]) son[cur]=edge[i].to;
	}
}
void dfs2(int cur,int top)
{
	::top[cur]=top; id[cur]=++*id;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^son[cur])
			dfs2(edge[i].to,edge[i].to);
}
#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	ll a,b;  //int enough?
	bool tag;
}node[400010];
void pushup(int cur)
{
	node[cur].a=node[lson].a+node[rson].a;
	node[cur].b=max(node[lson].b+node[rson].a,node[rson].b);
}
void pushdown(int cur,int l,int r)
{
	if (!node[cur].tag) return;
	node[cur].tag=false;
	node[lson]=(Node){-mid+l-1,0,true};
	node[rson]=(Node){mid-r,0,true};
}
void update1(int cur,int l,int r,int pos,ll a,ll b)
{
	if (l==r) return node[cur]=(Node){a,b,false},void();
	pushdown(cur,l,r);
	if (pos<=mid) update1(lson,l,mid,pos,a,b);
	else update1(rson,mid+1,r,pos,a,b);
	pushup(cur);
}
void update2(int cur,int l,int r,int pos)
{
	if (l==r) return node[cur].a++,node[cur].b++,void();
	pushdown(cur,l,r);
	if (pos<=mid) update2(lson,l,mid,pos);
	else update2(rson,mid+1,r,pos);
	pushup(cur);
}
void clear(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur]=(Node){-r+l-1,0,true},void();
	pushdown(cur,l,r);
	if (qr<=mid) clear(lson,l,mid,ql,qr);
	else if (ql>mid) clear(rson,mid+1,r,ql,qr);
	else clear(lson,l,mid,ql,mid),clear(rson,mid+1,r,mid+1,qr);
	pushup(cur);
}
Node query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur];
	pushdown(cur,l,r);
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	Node a=query(lson,l,mid,ql,mid); Node b=query(rson,mid+1,r,mid+1,qr);
	//printf("query %d %d  :  %lld %lld\n",ql,qr,a.a+b.a,max(a.b+b.a,b.b));
	return (Node){a.a+b.a,max(a.b+b.a,b.b)};
}
Node getdp(int cur)
{
	Node a=query(1,1,n,id[top[cur]],id[cur]),b;
	cur=fat[top[cur]];
	while (cur)
	{
		b=query(1,1,n,id[top[cur]],id[cur]);
		a=(Node){b.a+a.a,max(b.b+a.a,a.b)};
		cur=fat[top[cur]];
	}
	return a;
}
#undef mid
#undef lson
#undef rson
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read(),q=read();
	for (int i=2;i<=n;i++) fat[i]=read(),addedge(fat[i],i);
	dfs1(1,1); dfs2(1,1); node[1]=(Node){-n,0,true};
	int opt,x;
	while (q--)
	{
		opt=read(),x=read();
		if (opt==1)
		{
			update2(1,1,n,id[x]);  //x and id[x] !
			continue;
		}
		if (opt==2)
		{
			if (x==1) node[1]=(Node){-n,0,true};
			else
			{
				Node a=getdp(fat[x]),b=query(1,1,n,id[x],id[x]);
				b.a-=b.b; b.b=0;
				if (max(a.a,a.b)+b.a>0) b.a=-max(a.a,a.b);
				update1(1,1,n,id[x],b.a,b.b);
				if (siz[x]^1) clear(1,1,n,id[x]+1,id[x]+siz[x]-1);
			}
			continue;
		}
		Node a=getdp(x);
		//printf("%lld %lld\n",a.a,a.b);
		//for (int i=1;i<=n;i++) printf("%d: %lld %lld\n",i,query(1,1,n,id[i],id[i]).a,query(1,1,n,id[i],id[i]).b);
		//printf("test %lld %lld\n",query(1,1,n,1,1).a,query(1,1,n,1,1).b);
		//printf("test %lld %lld\n",query(1,1,n,1,2).a,query(1,1,n,1,2).b);
		//printf("test %lld %lld\n",query(1,1,n,1,3).a,query(1,1,n,1,3).b);
		//printf("test %lld %lld\n",query(1,1,n,1,4).a,query(1,1,n,1,4).b);
		//printf("test %lld %lld\n",query(1,1,n,3,4).a,query(1,1,n,3,4).b);
		puts(a.a>0||a.b>0?"black":"white");
	}
	return 0;
}