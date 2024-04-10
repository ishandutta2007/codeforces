#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 3e5 + 7;

void NO() {
	cout << "NO\n";
	exit(0);
}

vi G[N], pre , post;
int a[N], b[N], aux[N], mx[N], d[N], p[N], ans[N], tt;

void dfs(int u, int depth = 0) {
	ans[u] = ++tt, mx[u] = a[u], d[u] = depth;
	pre.PB(u);
	for(int v:G[u]) {
		dfs(v, depth + 1);
		mx[u] = max(mx[u], mx[v]);
	}
	post.PB(u);
}

signed main()
{
	IO_OP;

	ll steps = 0;

	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], b[a[i]] = i;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[v] = u;
		G[u].PB(v);
	}
	for(int i = 1; i <= n; i++) sort(ALL(G[i]), [&] (int x, int y) { return a[x] < a[y]; });
	dfs(1);
	int c = 1;
	while(c <= n && mx[b[c]] == a[b[c]]) steps += d[b[c++]];
	if(c <= n) {
		int u = b[c], ptr = u;
		steps += d[u];
		for(int i = 0; i < d[u]; i++) swap(a[ptr], a[p[ptr]]), ptr = p[ptr];
		for(int i = 0; i < d[u]; i++) {
			int nxt = -1;
			for(int v:G[ptr]) if(a[v] > a[ptr]) if(nxt == -1 || a[v] < a[nxt]) nxt = v;
			if(nxt == -1) NO();
			swap(a[nxt], a[ptr]), ptr = nxt;
		}
		if(ptr != u) NO();
		for(int i = 0; i < d[u]; i++) swap(a[ptr], a[p[ptr]]), ptr = p[ptr];
	}

	memset(aux, -1, sizeof aux);
	for(int i = 1; i < c; i++) aux[post[i - 1]] = i;
	for(int i:pre) if(aux[i] == -1) aux[i] = c++;

	for(int i = 1; i <= n; i++) if(a[i] != aux[i]) NO();
	
	cout << "YES\n";
	cout << steps << '\n';
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';

}