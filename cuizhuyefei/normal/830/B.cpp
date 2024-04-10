#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
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
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 400040,inf=1e9;
int n,a[N],s[N];
struct node{
	int l,r,min,cnt;
}tree[N<<2];
void build(int k, int l, int r){
	tree[k].l=l;tree[k].r=r;tree[k].min=a[l];tree[k].cnt=r-l+1;
	if(l==r)return;int mid=(l+r)>>1;
	build(lc(k),l,mid);build(rc(k),mid+1,r);
	tree[k].min=min(tree[lc(k)].min,tree[rc(k)].min);
}
void modify(int k, int p){
	tree[k].cnt--;if(tree[k].l==tree[k].r){tree[k].min=inf;return;}
	if(p<=tree[lc(k)].r)modify(lc(k),p);else modify(rc(k),p);
	tree[k].min=min(tree[lc(k)].min,tree[rc(k)].min);
}
int query(int k, int p, int v){//>=p, ==v
	if(tree[k].r<p||tree[k].min>v)return 0;if(tree[k].l==tree[k].r)return tree[k].l;
	int x=query(lc(k),p,v);if(x)return x;return query(rc(k),p,v);
}
int qsum(int k, int l, int r){
	if(r<tree[k].l||l>tree[k].r)return 0;
	if(l<=tree[k].l&&r>=tree[k].r)return tree[k].cnt;
	return qsum(lc(k),l,r)+qsum(rc(k),l,r);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);rep(i,1,n)a[i+n]=a[i];
	build(1,1,n+n);rep(i,1,n)s[i]=a[i];
	sort(s+1,s+n+1);ll res=0,now=1;
	rep(i,1,n){
		int p=query(1,now,s[i]);res+=qsum(1,now,p);//printf("%d %lld: %lld --> %d\n",i,res,now,p);
		now=p;now=now<=n?now:now-n;
		modify(1,now);modify(1,n+now);
	}
	printf("%lld\n",res);
	return 0;
}