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
const int Mod=1004535809;

int n,m;
struct Rec{
	int c,q;
}rec[200010];
bool operator<(const Rec x,const Rec y)
{
	if (x.q^y.q) return x.q>y.q;
	return x.c<y.c;
}
unsigned rnd()
{
	static unsigned sd=45783U;
	return sd*=57291U;
}
#define ls node[cur].lson
#define rs node[cur].rson
struct Node{
	int lson,rson,siz;
	int ans,anstag,val,valtag;
}node[200010];
int rt;
void pushdown(int cur)
{
	if (node[cur].anstag)
	{
		node[ls].anstag+=node[cur].anstag;
		node[ls].ans+=node[cur].anstag;
		node[rs].anstag+=node[cur].anstag;
		node[rs].ans+=node[cur].anstag;
		node[cur].anstag=0;
	}
	if (node[cur].valtag)
	{
		node[ls].valtag+=node[cur].valtag;
		node[ls].val+=node[cur].valtag;
		node[rs].valtag+=node[cur].valtag;
		node[rs].val+=node[cur].valtag;
		node[cur].valtag=0;
	}
}
void pushup(int cur)
{
	node[cur].siz=node[ls].siz+1+node[rs].siz;
}
void split(int cur,int val,int &x,int &y)  //<=val L R
{
	if (!cur) return x=y=0,void();
	pushdown(cur);
	if (node[cur].val<=val) {x=cur; split(rs,val,node[x].rson,y);pushup(x);}
	else {y=cur; split(ls,val,x,node[y].lson);pushup(y);}
}
int merge(int x,int y)
{
	if (!x||!y) return x|y;
	if (rnd()%(node[x].siz+node[y].siz)<node[x].siz)
	{
		pushdown(x);
		node[x].rson=merge(node[x].rson,y);
		pushup(x);
		return x;
	}
	pushdown(y);
	node[y].lson=merge(x,node[y].lson);
	pushup(y);
	return y;
}
int bin[200010];
bool cmp(int x,int y)
{
	return node[x].val<node[y].val;
}
int build(int l,int r)
{
	int mid=l+r>>1;
	int cur=bin[mid];
	if (l<mid) node[cur].lson=build(l,mid-1);
	if (mid<r) node[cur].rson=build(mid+1,r);
	node[cur].siz=r-l+1;
	return cur;
}
void dfs(int cur)
{
	if (!cur) return;
	pushdown(cur);
	dfs(ls); bin[++*bin]=cur; dfs(rs);
}
#undef ls
#undef rs
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	n=read();
	for (int i=1;i<=n;i++) rec[i].c=read(),rec[i].q=read();
	sort(rec+1,rec+n+1);
	m=read();
	for (int i=1;i<=m;i++) node[i].val=read(),bin[i]=i;
	sort(bin+1,bin+m+1,cmp);
	rt=build(1,m);
	for (int i=1;i<=n;i++)
	{
		int x,y,z;
		split(rt,rec[i].c-1,x,y);   //caution empty
		node[y].ans++,node[y].anstag++;
		node[y].val-=rec[i].c,node[y].valtag-=rec[i].c;
		split(y,rec[i].c*2-1,y,z);
		rt=merge(x,z);
		(*bin)=0; dfs(y);
		for (int j=1;j<=(*bin);j++)
		{
			y=bin[j];
			node[y].lson=node[y].rson=0; node[y].siz=1;
			split(rt,node[y].val,x,z);
			rt=merge(x,merge(y,z));
		}
	}
	(*bin)=0; dfs(rt);
	for (int i=1;i<=m;i++) printf("%d ",node[i].ans); putchar('\n');
	return 0;
}