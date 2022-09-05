#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=time(0);
	return seed^=seed<<13,seed^=seed>>7,seed^=seed<<17;
}
const int N = 152000;
int n,m,h,a[N],b[N];
struct node {
	int l,r,val; int lazy;
} tree[N<<2];
inline int min(int a, int b) {return a<b?a:b;}
inline void update(int k) {
	tree[k].val=min(tree[lc(k)].val,tree[rc(k)].val);
}
inline void pushdown(int k) {
	if (tree[k].lazy) {
		int &t=tree[k].lazy;
		tree[lc(k)].lazy+=t; tree[lc(k)].val+=t;
		tree[rc(k)].lazy+=t; tree[rc(k)].val+=t;
		t=0;
	}
}
inline void build(int k, int l, int r) { //v[i]=-i
	tree[k].l=l; tree[k].r=r; 
	if (l==r) {tree[k].val=-l; return;}
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
	update(k);
}
inline void modify(int k, int l, int r, int v) {
	if (r<tree[k].l||l>tree[k].r) return;
	if (l<=tree[k].l&&r>=tree[k].r) {
		tree[k].lazy+=v; tree[k].val+=v; return;
	}
	pushdown(k);
	modify(lc(k),l,r,v); modify(rc(k),l,r,v);
	update(k);
}
inline void add(int i, int xs) {
	int L=1,R=m,p=m+1;
	while (L<=R) {
		int mid=(L+R)>>1;
		if (b[mid]<=a[i]) p=mid,R=mid-1; else L=mid+1;
	}
	if (p<=m) modify(1,p,m,xs);
}
int main() {
	read(n);read(m);read(h);
	rep(i,1,m)read(b[i]); rep(i,1,n)read(a[i]);
	sort(b+1,b+m+1);
	rep(i,1,m) b[i]=h-b[i]; build(1,1,m); int ans=0;
	rep(i,1,m-1) add(i,1);
	rep(i,m,n) {
		add(i,1); ans+=(tree[1].val>=0); add(i-m+1,-1);
	}
	cout<<ans;
	return 0;
}