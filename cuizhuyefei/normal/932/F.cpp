#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define mid ((l+r)>>1)
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 402000, mx = 100000;
int n,a[N],B[N];
int head[N],to[N],nxt[N],edgenum;
inline void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
/*struct line {
	ll k,b; //kx+b
	bool operator < (const line &a) {return k>a.k;}
};
set<line> Set;*/
ll dp[N];
int size[N],L[N],R[N],dy[N],num;
inline void pre(int u, int fa) {
	size[u]=1; L[u]=++num; dy[num]=u;
	L(i,u) if (to[i]!=fa) {pre(to[i],u); size[u]+=size[to[i]];}
	R[u]=num;
}
struct seg {
	int l,r;
	ll k,b;
} tree[N<<2];
int sta[6000000],top;
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r; tree[k].b=1e18; if (l==r) return;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
}
inline void update(int k, ll K, ll b) {
	int l=tree[k].l,r=tree[k].r; sta[++top]=k;
	int cnt=(l*tree[k].k+tree[k].b<=l*K+b)+(r*tree[k].k+tree[k].b<=r*K+b);
	if (cnt==2) return; if (cnt==0) {tree[k].k=K; tree[k].b=b; return;} if (l==r) return;
	double pos=((double)b-tree[k].b)/(tree[k].k-K);
	if (pos<=mid) {
		if (K<tree[k].k) {
			update(lc(k),tree[k].k,tree[k].b);
			tree[k].k=K; tree[k].b=b;
		}
		else {
			update(lc(k),K,b);
		}
	}
	else {
		if (K<tree[k].k) {
			update(rc(k),K,b);
		}
		else {
			update(rc(k),tree[k].k,tree[k].b);
			tree[k].k=K; tree[k].b=b;
		}
	}
}
inline void ins(int u) {
	ll k=B[u],b=dp[u]; update(1,k,b);
}
inline ll query(int k, int x) {
	ll mx=x*tree[k].k+tree[k].b;
	if (tree[k].l==tree[k].r) return mx;
	return min(mx,x<=tree[lc(k)].r ? query(lc(k),x) : query(rc(k),x));
}
inline void erase() {
	while (top) {tree[sta[top]].k=0; tree[sta[top]].b=1e18; top--;}
}
inline void dfs(int u, int fa, bool keep) {
	int mx=-1;
	L(i,u) if (fa!=to[i]&&(mx==-1||size[to[i]]>size[mx])) mx=to[i];
	L(i,u) if (fa!=to[i]&&to[i]!=mx) dfs(to[i],u,0);
	if (mx!=-1) dfs(mx,u,1);
	L(i,u) if (to[i]!=fa&&to[i]!=mx) {
		int v=to[i];
		rep(j,L[v],R[v]) ins(dy[j]);
	}
	dp[u]=query(1,a[u]); if (mx==-1) dp[u]=0; ins(u);
	if (!keep) erase();
}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) read(B[i]); int x,y; build(1,-mx,mx);
	rep(i,1,n-1) {read(x);read(y);addedge(x,y);addedge(y,x);}
	pre(1,0); dfs(1,0,1); rep(i,1,n) printf("%lld ",dp[i]);
	return 0;
}