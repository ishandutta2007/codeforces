#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 1e5 + 7;

signed main()
{
	IO_OP;

	int m;
	cin >> m;
	vi n(m);
	V<vi> a(m);
	V<string> ans(m);
	map<int, V<pi>> mp;
	for(int i = 0; i < m; i++) {
		cin >> n[i];
		a[i] = vi(n[i]);
		ans[i] = string(n[i], '-');
		for(int j = 0; j < n[i]; j++) {
			cin >> a[i][j];
			mp[a[i][j]].EB(i, j);
		}
	}

	V<vi> G(m);

	vi es(1);
	V<pi> aux(1);

	for(auto&[x, tt] : mp) {
		if(SZ(tt) & 1) {
			cout << "NO\n";
			return 0;
		}
		for(int i = 0; i < SZ(tt); i += 2) {
			aux.EB(x, i);
			G[tt[i].F].PB(SZ(es));
			G[tt[i + 1].F].PB(-SZ(es));
			es.PB(tt[i].F ^ tt[i + 1].F);
		}
	}

	auto go = [&] (int e) {
		assert(e);
		auto[x, i] = aux[abs(e)];
		if(e > 0) {
			ans[mp[x][i].F][mp[x][i].S] = 'L';
			ans[mp[x][i + 1].F][mp[x][i + 1].S] = 'R';
		} else {
			ans[mp[x][i].F][mp[x][i].S] = 'R';
			ans[mp[x][i + 1].F][mp[x][i + 1].S] = 'L';
		}
	};

	function<void(int)> dfs = [&] (int u) {
		while(SZ(G[u])) {
			int e = G[u].back(); G[u].pop_back();
			if(es[abs(e)] == -1) continue;
			int v = es[abs(e)] ^ u;
			es[abs(e)] = -1;
			dfs(v);
			go(e);
		}
	};

	vi vis(m);
	for(int i = 0; i < m; i++) dfs(i);

	cout << "YES\n";
	for(int i = 0; i < m; i++)
		cout << ans[i] << '\n';

}