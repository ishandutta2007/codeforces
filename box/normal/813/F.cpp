// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int bcj[200010], siz[200010]; stack<pii> res;
void init(int n) { rep(i, n+2) bcj[i] = i, siz[i] = 1; }
int groot(int n) { return (bcj[n] == n) ? n : groot(bcj[n]); }
bool merg(int u, int v) {
	u = groot(u), v = groot(v);
	if(u == v) return 0;
	if(siz[u] > siz[v]) swap(u, v);
	res.push({u, v});
	bcj[u] = v; siz[v] += siz[u];
	return 1;
}
void redact() {
	assert(res.size()); pii k = res.top(); res.pop();
	bcj[k.fi] = k.fi; bcj[k.se] = k.se; siz[k.se] -= siz[k.fi];
}
void redact(int n) { while(res.size() != n) redact(); }
struct cmd { int s, t; };
int ans[1<<18];
vector<cmd> queries[1<<20];
int N;
void insert(int idx, int l, int r, int L, int R, cmd q) {
	if(r - l < 0) return;
	if(L <= l && r <= R) { queries[idx].pb(q); return; }
	if(R < l || r < L) return;
	insert(2*idx, l, (l+r)/2, L, R, q);
	insert(2*idx+1, (l+r)/2+1, r, L, R, q);
}
void dfs(int idx, int l, int r) {
	if(r - l < 0) return;
	int sz = res.size();
	for(cmd& k:queries[idx]) {
		merg(k.s,k.t+N);
		merg(k.t,k.s+N);
		if(groot(k.s)==groot(k.s+N)||groot(k.t)==groot(k.t+N)) return redact(sz);
	}
	if(r - l == 0) return ans[l] = 1, void();
	dfs(2*idx, l, (l+r)/2);
	dfs(2*idx+1, (l+r)/2+1, r);
	redact(sz);
}

map<int, int> edges[100005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> N >> q;
    init(2*N+1);
    rep1(i, q) {
		int x, y; cin >> x >> y; x--; y--;
		assert(x < y);
		if(edges[x][y] == 0) edges[x][y] = i;
		else {
			insert(1, 0, q+3, edges[x][y], i-1, {x, y});
			edges[x][y] = 0;
		}
	}
	rep(i, N)
		for(auto k:edges[i]) 
			if(k.se)
				insert(1, 0, q+3, k.se, q, {i, k.fi});
	dfs(1, 0, q+3);
	rep1(i, q) cout << (ans[i]?"YES\n":"NO\n");
}