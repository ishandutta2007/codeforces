#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 2e5+5;
vector<int> G[N];
bool seen[N];
int n, m, a, b;

int get_non(int v, int bad) {
	if(seen[v]) return 0;
	seen[v] = true;
	int ans = 1;
	for(int u : G[v]) {
		int ret = get_non(u, bad);
		if(ret == -1 || ans == -1) {
			ans = -1;
		} else
			ans += ret;
	}
	if(v == bad) return -1;
	return ans;
}

ll get_avoiding(int a, int b) {
	fill(seen, seen+n+1, false);
	seen[a] = true;
	ll ans = 0;
	for(int u : G[a]) {
		int ret = get_non(u, b);
		ans += max(ret, 0);
	}
	return ans;
}

void solve() {
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; ++i) G[i].clear();
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	const ll A = get_avoiding(a, b);
	const ll B = get_avoiding(b, a);
	cout << A * B << '\n';
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}


}