#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 505000;
int n,a[N],num;
inline int gcd(int a, int b){return !b ? a : gcd(b,a%b);}
struct Tree {
	int l,r,gcd;
} tree[N<<2];
inline void update(int k) {
	tree[k].gcd=gcd(tree[lc(k)].gcd,tree[rc(k)].gcd);
}
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r;
	if (l==r) {tree[k].gcd=a[l]; return;}
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
	update(k);
}
inline void query(int k, int l, int r, int x) {
	if (r<tree[k].l||l>tree[k].r||tree[k].gcd%x==0||num>=2) return;
	if (tree[k].l==tree[k].r) {
		num++; return;
	}
	query(lc(k),l,r,x); query(rc(k),l,r,x);
}
inline void modify(int k, int p, int v) {
	if (tree[k].l==tree[k].r) {tree[k].gcd=v; return;}
	if (p<=tree[lc(k)].r) modify(lc(k),p,v); else modify(rc(k),p,v);
	update(k);
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) read(a[i]); build(1,1,n);
	int q; read(q);
	while (q--) {
		int op; read(op); 
		if (op==1) {
			int l,r,x; read(l); read(r); read(x);
			num=0; query(1,l,r,x);
			printf("%s\n",num<=1?"YES":"NO");
		}
		else {
			int i,y; read(i); read(y);
			modify(1,i,y);
		}
	}
	return 0;
}