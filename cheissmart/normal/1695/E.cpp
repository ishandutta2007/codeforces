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

const int INF = 1e9 + 7, N = 6e5 + 7;

V<pi> G[N];

bool vis[N], vise[N];

vi cycle;

void dfs(int u) {
	cycle.PB(u);
	vis[u] = true;
	for(auto[v, i]:G[u]) if(!vise[i]) {
		vise[i] = true;
		if(!vis[v]) {
			dfs(v);
		} else {
			cycle.PB(v);
		}
		cycle.PB(u);
	}
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		G[x].EB(y, i);
		G[y].EB(x, i);
	}
	vi he, be;
	string a, b, c, d;

	for(int i = 1; i <= 2 * n; i++) if(!vis[i]) {
		cycle.clear();
		dfs(i);
		cycle.pop_back();
		assert(SZ(cycle) % 2 == 0);
		int k = SZ(cycle) / 2;
		if(k == 0) continue;
		if(k == 1) {
			cout << -1 << '\n';
			return 0;
		}

		for(int j = 0; j < k; j++)
			he.PB(cycle[j]);
		for(int j = k * 2 - 1; j >= k; j--)
			be.PB(cycle[j]);

		if(k & 1) {
			a += 'U', b += 'D';
			for(int j = 0; j < k / 2; j++) {
				a += "LR", b += "LR";
				c += "LR", d += "LR";
			}
			c += 'U', d += 'D';
		} else {
			a += 'U', b += 'D';
			for(int j = 0; j < k / 2 - 1; j++)
				a += "LR", b += "LR";
			a += 'U', b += 'D';

			for(int j = 0; j < k / 2; j++)
				c += "LR", d += "LR";
		}	
	}

	cout << 2 << " " <<	SZ(he) << "\n\n";
	for(int i:he) cout << i << " "; cout << "\n";
	for(int i:be) cout << i << " "; cout << "\n\n";
	cout << a << "\n" << b << "\n\n" << c << "\n" << d << "\n";

}