#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
//inline void read(int &x) {
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 400000;
int n;
ll a[N];
map<ll,ll> f[N];
struct node {
	int l,r; ll mn;
} tree[N<<2];
inline void update(int k) {tree[k].mn=min(tree[lc(k)].mn,tree[rc(k)].mn);}
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r;
	if (l==r) {tree[k].mn=a[l]; return;}
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r); update(k);
}
inline int query(int i, ll r) { //minj(j>i): a[j]<=r
	int u; for (u=1; tree[u].l!=tree[u].r; u=i<=tree[lc(u)].r?lc(u):rc(u));
//	printf("query %d %lld: ",i,r);
	while (u>1) {
		int fa=u>>1; if (rc(fa)==u) {u=fa; continue;} u=fa;
		if (tree[rc(u)].mn<=r) {
			u=rc(u);
			for (;tree[u].l!=tree[u].r;)
				if (tree[lc(u)].mn<=r) u=lc(u); else u=rc(u);
		//	printf("%d\n",tree[u].l);
			return tree[u].l;
		}
	}
//	puts("");
	return n+1;
}

#define umax(a,b) {if (b>a) a=b;}
int main() { //freopen("data.in","r",stdin);
	read(n); rep(i,1,n) read(a[i]); build(1,1,n);
	f[1][a[1]-1]=0;
	rep(i,1,n-1) while (!f[i].empty()) {
		map<ll,ll> ::iterator it=f[i].begin(); f[i].erase(it); ll r=(*it).fi,k=(*it).se;
	//	if (i>n-30) printf("%d: %d (%lld %lld)\n",i,(int)f[i].size(),r,a[i+1]);
	//	printf("(%d %lld %lld)\n",i,r,k);
		if (r<a[i+1]) {int t=query(i+1,r)-1; if (f[t].count(r)) umax(f[t][r],k) else f[t][r]=k;}
		else {
			ll v=k+1LL*i*(a[i+1]*(r/a[i+1]));
			if (f[i+1].count(r%a[i+1])) umax(f[i+1][r%a[i+1]],v) else f[i+1][r%a[i+1]]=v;
			if (f[i+1].count(a[i+1]-1)) umax(f[i+1][a[i+1]-1],v-i*a[i+1]) else f[i+1][a[i+1]-1]=v-i*a[i+1];
		}
	}
	ll ans=0; while (!f[n].empty()) { 
		map<ll,ll> ::iterator it=f[n].begin(); //if (f[n].size()<=20) printf("%d\n",(int)f[n].size());
		ll r=(*it).fi,k=(*it).se; f[n].erase(it); 
		umax(ans,k+n*r);
	}
	printf("%lld",ans);
	return 0;
}
//WA:build/mn