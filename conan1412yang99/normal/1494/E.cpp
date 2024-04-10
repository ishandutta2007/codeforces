#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

map<pi, int> mp[N];
map<int, int> G[N];
// map<pi, int> es[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	ll edge_cnt = 0, good_cnt = 0; //, tt = 0;
	while(m--) {
		char op;
		cin >> op;
		if(op == '+') {
			int u, v;
			char c;
			cin >> u >> v >> c;
			int cc = c - 'a' + 1;
			G[u][v] = cc;
			if(G[v][u]) { // edge
				edge_cnt++;
				if(G[u][v] == G[v][u]) {
					good_cnt++;
				}
				// int a = G[u][v], b = G[v][u];
				// tt += es[v][{b, a}];
				// tt += es[u][{a, b}];
				// es[u][{a, b}]++;
				// es[v][{b, a}]++;
			}
		} else if(op == '-') {
			int u, v;
			cin >> u >> v;
			int cc = G[u][v];
			assert(cc);
			if(G[v][u]) { // edge
				edge_cnt--;
				if(G[u][v] == G[v][u]) {
					good_cnt--;
				}
				// int a = G[u][v], b = G[v][u];
				// es[u][{a, b}]--;
				// es[v][{b, a}]--;
				// tt -= es[v][{b, a}];
				// tt -= es[u][{a, b}];
			}
			G[u][v] = 0;
		} else {
			int k;
			cin >> k;
			if(k % 2 == 1) {
				cout << (edge_cnt ? "YES" : "NO") << '\n';
			} else {
				if(good_cnt) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}

}