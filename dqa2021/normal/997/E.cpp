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
void print(ll x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}

int n,m,w[120010];
ll ans[120010];
struct Edge{
	int to,nxt,pos;
}edge[120010];
int cnt,last[120010];
inline void addedge(int x,int y,int z)
{
	edge[++cnt]=(Edge){y,last[x],z},last[x]=cnt;
}
#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	int minval,mintot,valtag;
	ll ans; int anstag;
}node[480010];
void build(int cur,int l,int r)
{
	node[cur]=(Node){l,1,0,0,0};
	if (l==r) return;
	build(lson,l,mid); build(rson,mid+1,r);
}
void pushdown(int cur,int l,int r)
{
	if (node[cur].valtag)
	{
		node[lson].valtag+=node[cur].valtag;
		node[rson].valtag+=node[cur].valtag;
		node[lson].minval+=node[cur].valtag;
		node[rson].minval+=node[cur].valtag;
		node[cur].valtag=0;
	}
	if (node[cur].anstag)
	{
		if (node[lson].minval==node[cur].minval)
		{
			node[lson].anstag+=node[cur].anstag;
			node[lson].ans+=1LL*node[cur].anstag*node[lson].mintot;
		}
		if (node[rson].minval==node[cur].minval)
		{
			node[rson].anstag+=node[cur].anstag;
			node[rson].ans+=1LL*node[cur].anstag*node[rson].mintot;
		}
		node[cur].anstag=0;
	}
}
void pushup(int cur)
{
	node[cur].minval=min(node[lson].minval,node[rson].minval);
	node[cur].mintot=(node[cur].minval==node[lson].minval?node[lson].mintot:0)+(node[cur].minval==node[rson].minval?node[rson].mintot:0);
	node[cur].ans=node[lson].ans+node[rson].ans;
}
void update(int cur,int l,int r,int ql,int qr,int val)
{
	if (l==ql&&r==qr)
	{
		node[cur].minval+=val; node[cur].valtag+=val;
		return;
	}
	pushdown(cur,l,r);
	if (qr<=mid) update(lson,l,mid,ql,qr,val);
	else if (ql>mid) update(rson,mid+1,r,ql,qr,val);
	else update(lson,l,mid,ql,mid,val),update(rson,mid+1,r,mid+1,qr,val);
	pushup(cur);
}
void maketag()
{
	node[1].ans+=node[1].mintot; node[1].anstag++;
}
ll query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur].ans;
	pushdown(cur,l,r);
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	return query(lson,l,mid,ql,mid)+query(rson,mid+1,r,mid+1,qr);
}
#undef mid
#undef lson
#undef rson
int minstk[120010],maxstk[120010];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read();
	for (int i=1;i<=n;i++) w[i]=read();
	m=read();
	for (int i=1,x,y;i<=m;i++)
	{
		x=read(),y=read();
		addedge(y,x,i);
	}
	build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		//printf("case %d\n",i);
		while ((*minstk)&&w[i]<w[minstk[*minstk]])
		{
			//printf("%d to %d min change from %d to %d\n",(*minstk)==1?1:minstk[(*minstk)-1]+1,minstk[*minstk],w[minstk[*minstk]],w[i]);
			update(1,1,n,(*minstk)==1?1:minstk[(*minstk)-1]+1,minstk[*minstk],-w[i]+w[minstk[*minstk]]),
			--*minstk;
		}
		minstk[++*minstk]=i;
		while ((*maxstk)&&w[i]>w[maxstk[*maxstk]])
		{
			//printf("%d to %d max change from %d to %d\n",(*maxstk)==1?1:maxstk[(*maxstk)-1]+1,maxstk[*maxstk],w[maxstk[*maxstk]],w[i]);
			update(1,1,n,(*maxstk)==1?1:maxstk[(*maxstk)-1]+1,maxstk[*maxstk],w[i]-w[maxstk[*maxstk]]),
			--*maxstk;
		}
		maxstk[++*maxstk]=i;
		maketag();
		for (int j=last[i];j;j=edge[j].nxt)
			ans[edge[j].pos]=query(1,1,n,edge[j].to,i);
	}
	for (int i=1;i<=m;i++) print(ans[i]),putchar('\n');
	return 0;
}