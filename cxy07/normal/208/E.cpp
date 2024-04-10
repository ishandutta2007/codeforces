//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,q;
int fa[MAXN],ans[MAXN],root[MAXN];
int p[MAXN][21],dep[MAXN];
vector<int> G[MAXN],rt;
vector<pii> Q[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

namespace K_Ancestor {
	void DFS(int x) {
		dep[x] = dep[fa[x]] + 1;
		p[x][0] = fa[x];
		for(register int i = 1;i <= 20; ++i)
			p[x][i] = p[p[x][i - 1]][i - 1];
		for(auto to : G[x]) DFS(to);
	}
	int kth(int x,int k) {
		if(k >= dep[x]) return 0;
		for(register int i = 20;~i; --i) 
			if((1 << i) <= k) x = p[x][i],k -= (1 << i);
		return x;
	}
}

namespace SegmentTree {
	int seg[MAXN * 30],cnt = 0;
	int ls[MAXN * 30],rs[MAXN * 30];
	void update(int &root,int l,int r,int pos) {
		if(!root) root = ++cnt;
		seg[root]++;
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(pos <= mid) update(ls[root],l,mid,pos);
		else update(rs[root],mid + 1,r,pos);
	}
	int query(int root,int l,int r,int pos) {
		if(pos > r) return 0;
		if(l == r) return seg[root];
		int mid = (l + r) >> 1;
		if(pos <= mid) return query(ls[root],l,mid,pos);
		else return query(rs[root],mid + 1,r,pos);
	}
	int merge(int &a,int &b) {
		if(!a || !b) return (a | b);
		seg[a] += seg[b];
		ls[a] = merge(ls[a],ls[b]);
		rs[a] = merge(rs[a],rs[b]);
		return a;
	}
	void DFS(int x) {
		update(root[x],1,n,dep[x]);
		for(auto to : G[x]) {
			DFS(to);
			root[x] = merge(root[x],root[to]);
		}
		for(auto p : Q[x]) {
			int s = p.fst,id = p.scd;
			ans[id] = query(root[x],1,n,dep[x] + s) - 1;
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(register int i = 1;i <= n; ++i) {
		read(fa[i]);
		if(fa[i]) G[fa[i]].push_back(i);
		else rt.push_back(i);
	}
	for(auto x : rt) K_Ancestor::DFS(x);
	read(q);
	for(register int i = 1,x,k;i <= q; ++i) {
		read(x); read(k);
		int anc = K_Ancestor::kth(x,k);
		if(!anc) ans[i] = 0;
		else Q[anc].push_back(mp(k,i));
	}
	for(auto x : rt) SegmentTree::DFS(x);
	for(register int i = 1;i <= q; ++i)
		printf("%d ",ans[i]);
	return 0;
}