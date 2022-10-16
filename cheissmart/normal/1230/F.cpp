#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N];
int in[N], out[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u, v);
		G[u].PB(v); // v -> u
		in[u]++, out[v]++;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += (ll) in[i] * out[i];
	cout << ans << endl;
	int q;
	cin >> q;
	while(q--) {
		int u;
		cin >> u;
		ans -= (ll) in[u] * out[u];
		in[u] = 0, out[u] += G[u].size();
		for(int v:G[u]) {
			ans -= (ll) in[v] * out[v];
			G[v].PB(u);
			out[v]--, in[v]++;
			ans += (ll) in[v] * out[v];
		}
		G[u].clear();
		cout << ans << endl;
	}
	
}