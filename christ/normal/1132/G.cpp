#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6 + 2, LOG = 17, INF = 1e8;
int a[MN], st[MN], ed[MN], p[MN], tt; vector<int> adj[MN]; bool vis[MN];
struct Node {
	int mx,lz;
} tree[MN<<2];
void push_down (int ind, bool go) {
	if (!tree[ind].lz) return;
	tree[ind].mx += tree[ind].lz;
	if (go) {
		tree[lc].lz += tree[ind].lz;
		tree[rc].lz += tree[ind].lz;
	}
	tree[ind].lz = 0;
}
void update (int ind, int tl, int tr, int l, int r, int v) {
	push_down(ind,tl!=tr);
	if (tl > r || tr < l) return;
	if (l <= tl && tr <= r) {
		tree[ind].lz += v;
		push_down(ind,tl!=tr);
		return;
	}
	int mid = (tl + tr) / 2;
	update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	tree[ind].mx = max(tree[lc].mx,tree[rc].mx);
}
void setV (int ind, int tl, int tr, int i, int v) {
	push_down(ind,tl!=tr);
	if (tl == tr) {
		tree[ind].mx = v;
		return;
	}
	int mid = (tl + tr) / 2;
	if (i <= mid) setV(lc,tl,mid,i,v), push_down(rc,mid+1!=tr);
	else setV(rc,mid+1,tr,i,v), push_down(lc,tl!=mid);
	tree[ind].mx = max(tree[lc].mx,tree[rc].mx);
}
int query (int ind, int tl, int tr, int i) {
	push_down(ind,tl!=tr);
	if (tl == tr) return tree[ind].mx;
	int mid = (tl + tr) / 2;
	return i <= mid ? query(lc,tl,mid,i) : query(rc,mid+1,tr,i);
}
void dfs (int cur) {
	st[cur] = ++tt;  vis[cur] = 1;
	for (int i : adj[cur]) dfs(i);
	ed[cur] = tt;
}
void add (int x) {
	int depth = p[x] ? max(query(1,1,tt,st[p[x]]),0) + 1 : 1;
	setV(1,1,tt,st[x],depth);
}
void del (int x) {
	setV(1,1,tt,st[x],-INF);
	update(1,1,tt,st[x],ed[x],-1);
}
int main () { 
	int n,k;
	scanf ("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	stack<int> stk;
	for (int i = n; i >= 1; i--) {
		while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
		if (!stk.empty()) adj[stk.top()].push_back(i), p[i] = stk.top();
		stk.push(i);
	}
	for (int i = n; i >= 1; i--) if (!vis[i]) dfs(i);
	for (int i = 0; i < (MN << 2); i++) tree[i] = {-INF,0};
	for (int i = n; i > n - k; i--) add(i);
	vector<int> ans = {tree[1].mx};
	for (int i = n-k; i >= 1; i--) {
		add(i); del(i+k);
		ans.push_back(tree[1].mx);
	}
	reverse(all(ans));
	for (int i : ans) printf ("%d ",i);
	printf ("\n");
	return 0;
}