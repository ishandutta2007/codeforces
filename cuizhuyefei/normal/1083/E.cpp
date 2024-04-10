#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
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
const int N = 1020000, M = 9000000, mx = 1e9;
const ll inf = 1e18;
struct ele{int x,y;ll a;}s[N];
bool cmp(const ele &a, const ele &b){return a.x<b.x;}
ll dp[N];int n;
struct node{
	ll k,b;
}tree[M];int lc[M],rc[M],rt,sz;
inline void modify(int &k, ll K, ll B, int l, int r){
	if(!k){k=++sz;tree[k].b=-inf;}
	bool bl=tree[k].k*l+tree[k].b<K*l+B;
	bool br=tree[k].k*r+tree[k].b<K*r+B;
	if(bl&&br){tree[k].k=K;tree[k].b=B;return;}
	if(!bl&&!br)return;int mid=(l+r)>>1;
	if(bl){
		if(tree[k].k*mid+tree[k].b<K*mid+B)modify(rc[k],tree[k].k,tree[k].b,mid+1,r),tree[k].k=K,tree[k].b=B;
		else modify(lc[k],K,B,l,mid);
	}
	else{
		if(tree[k].k*mid+tree[k].b<K*mid+B)modify(lc[k],tree[k].k,tree[k].b,l,mid),tree[k].k=K,tree[k].b=B;
		else modify(rc[k],K,B,mid+1,r);
	}
}
inline ll query(int k, int x, int l, int r){
	if(!k)return -inf;if(l==r)return tree[k].k*x+tree[k].b;
	int mid=(l+r)>>1;
	if(x<=mid)return max(query(lc[k],x,l,mid),tree[k].k*x+tree[k].b);
	return max(query(rc[k],x,mid+1,r),tree[k].k*x+tree[k].b);
}
int main() {
	read(n);rep(i,1,n)read(s[i].x),read(s[i].y),scanf("%lld",&s[i].a);
	sort(s+1,s+n+1,cmp);
	ll res=0;
	rep(i,1,n){
		dp[i]=1LL*s[i].x*s[i].y-s[i].a+max(query(rt,s[i].y,1,mx),0LL);
		modify(rt,-s[i].x,dp[i],1,mx);res=max(res,dp[i]);
	}
	printf("%lld\n",res);
	return 0;
}