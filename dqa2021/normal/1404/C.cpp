#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0,_t=x.size();i<_t;i++)
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
const int INF=1e9;

int n,q;
int a[300010],r[300010];
int b[300010];
vector<int> c[300010];
#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
struct Node{
	int tag,tot,mn;
}node[1<<20];
void pushup(int x){
	node[x].tot=node[ls].tot+node[rs].tot;
	node[x].mn=min(node[ls].mn,node[rs].mn);
}
void pushdown(int x){
	node[ls].mn-=node[x].tag;
	node[rs].mn-=node[x].tag;
	node[ls].tag+=node[x].tag;
	node[rs].tag+=node[x].tag;
	node[x].tag=0;
}
void build(int x,int l,int r){
	if (l==r){
		if (a[l]>l||a[l]<l-b[l]) node[x]=(Node){0,0,INF};
		else node[x]=(Node){0,1,a[l]-(l-b[l])};
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr){
		node[x].tag++; node[x].mn--;
		return;
	}
	pushdown(x);
	if (ql<=mid) update(ls,l,mid,ql,qr);
	if (mid<qr) update(rs,mid+1,r,ql,qr);
	pushup(x);
}
int query(int x,int l,int r){
	if (l==r) return l;
	pushdown(x);
	if (node[ls].mn<0) return query(ls,l,mid);
	return query(rs,mid+1,r);
}
int query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return node[x].tot;
	pushdown(x);
	int res=0;
	if (ql<=mid) res=query(ls,l,mid,ql,qr);
	if (mid<qr) res+=query(rs,mid+1,r,ql,qr);
	return res;
}
void modify(int x,int l,int r,int p){
	if (l==r) return node[x]=(Node){0,0,INF},void();
	pushdown(x);
	if (p<=mid) modify(ls,l,mid,p);
	else modify(rs,mid+1,r,p);
	pushup(x);
}
#undef ls
#undef rs
#undef mid
int ans[300010];
int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1,t=0;i<=n;i++){
		b[i]=t;
		if (i-t<=a[i]&&a[i]<=i) t++;
	}
	build(1,1,n);
	for (int i=1;i<=q;i++){
		int x=read(),y=read();
		c[x+1].pb(i); r[i]=n-y;
	}
	for (int i=1;i<=n;i++){
		forall(c[i],j){
			int p=c[i][j];
			ans[p]=query(1,1,n,1,r[p]);
		}
		static int que[300010],hd,tl;
		if (query(1,1,n,i,i)){
			que[++tl]=i; modify(1,1,n,i);
			while (hd<tl){
				int u=que[++hd];
				if (u<n) update(1,1,n,u+1,n);
				while (node[1].mn<0){
					int v=query(1,1,n);
					que[++tl]=v;
					modify(1,1,n,v);
				}
			}
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}