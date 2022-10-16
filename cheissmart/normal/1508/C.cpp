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

const int INF = 1e9 + 7, N = 2e5 + 7;

unordered_set<int> G[N];
int vis[N], p[N];

int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	p[x] = y;
}

signed main()
{
	IO_OP;
	
	int n, m, x; cin >> n >> m;
	ll to_add = (ll) n * (n - 1) / 2 - m;
	V<array<int, 3>> edges(m);
	for(int i = 0; i < m; i++) {
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
		x ^= edges[i][0];
		G[edges[i][1]].insert(edges[i][2]);
		G[edges[i][2]].insert(edges[i][1]);
	}
	sort(ALL(edges));
	for(int i = 1; i <= n; i++) p[i] = i;
	unordered_set<int> s;
	for(int i = 1; i <= n; i++) s.insert(i);
	for(int i = 1; i <= n; i++) if(s.count(i)) {
		s.erase(i);
		queue<int> q({i});
		while(q.size()) {
			int u = q.front(); q.pop();
			for(auto it = s.begin(); it != s.end();) {
				int v = *it;
				if(G[u].count(v)) it++;
				else q.push(v), unite(u, v), it = s.erase(it), to_add--;
			}
		}
	}
	ll ans = 0;
	V<array<int, 3>> yes, no;
	for(auto e:edges)
		if(find(e[1]) != find(e[2])) {
			ans += e[0], unite(e[1], e[2]);
			yes.PB(e);
		} else {
			no.PB(e);
		}
	if(to_add == 0) {
		int add = x;
		for(int i = 1; i <= n; i++) p[i] = i;
		for(auto e:yes) unite(e[1], e[2]);
		for(auto e:no) if(find(e[1]) != find(e[2])) add = min(add, e[0]);
		ans += add;
	}
	cout << ans << '\n';

}