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

V<pi> G[N], G2[N], g[N];
int ans[N], a[N * 2], b[N * 2], dead[N * 2], vis[N];
pi l[N * 2], r[N * 2];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int w;
		cin >> a[i] >> b[i] >> w;
		if(w == 1) {
			G[a[i]].EB(i, 0), G[b[i]].EB(i, 1);
		} else {
			G2[a[i]].EB(i, 0), G2[b[i]].EB(i, 1);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += int(G[i].size() & 1);
	cout << cnt << '\n';

	auto other = [&] (int edge, int u) {
		return a[edge] ^ b[edge] ^ u;
	};
	function<void(int, int)> expand = [&] (int edge, int dir) {
		if(edge <= m) {
			ans[edge] = dir;
		} else {
			expand(l[edge].F, l[edge].S ^ dir);
			expand(r[edge].F, r[edge].S ^ dir);
		}
	};

	int sz = m;
	auto contract = [&] (V<pi>* G) {
		auto reduce = [&] (int u) {
			while(G[u].size() && dead[G[u].back().F])
				G[u].pop_back();
		};
		for(int i = 1; i <= n; i++) {
			while(true) {
				reduce(i);
				if(G[i].empty())
					break;
				auto e = G[i].back(); G[i].pop_back();
				reduce(i);
				if(G[i].empty()) {
					G[i].PB(e);
					break;
				}
				auto ee = G[i].back(); G[i].pop_back();
				e.S ^= 1;
				assert(!dead[e.F] && !dead[ee.F]);
				assert(e.F != ee.F);
				dead[e.F] = dead[ee.F] = 1;
				int x = other(e.F, i), y = other(ee.F, i);
				if(x == y) {
					expand(e.F, e.S);
					expand(ee.F, ee.S);
					continue;
				}
				sz++;
				a[sz] = x, b[sz] = y;
				l[sz] = e, r[sz] = ee;
				G[x].EB(sz, 0), G[y].EB(sz, 1);
			}
		}
		for(int i = 1; i <= n; i++) {
			reduce(i);
			if(G[i].size()) {
				g[i].PB(G[i].back());
			}
		}
	};
	contract(G), contract(G2);

	function<void(int, int)> dfs = [&] (int u, int p) {
		if(vis[u]) return;
		vis[u] = 1;
		for(auto e:g[u]) {
			if(e.F != p) {
				expand(e.F, e.S);
				dfs(other(e.F, u), e.F);
				break;
			}
		}
	};

	for(int i = 1 ; i <= n; i++) if(!vis[i] && int(g[i].size()) == 1)
		dfs(i, -1);

	for(int i = 1 ; i <= n; i++) if(!vis[i])
		dfs(i, -1);

	for(int i = 1; i <= m; i++)
		cout << ans[i] + 1;
	cout << '\n';
}