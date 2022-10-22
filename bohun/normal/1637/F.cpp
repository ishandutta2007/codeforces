#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;
int n, h[N], mx[N];
pair<int, int> H;
ll dp[N][3];
vector<int> e[N];

void dfs(int u, int p) {
	dp[u][1] = 1e18;
	dp[u][2] = 1e18;
	int cnt = 0;
	int x = 0;
	for (auto v : e[u])
		if (v != p) {
			cnt++;
			dfs(v, u);
			dp[u][0] += dp[v][0];
			x = max(x, mx[v]);
		}

	mx[u] = max(h[u], x);
	if (x < h[u])
		dp[u][0] += h[u] - x;

	if (cnt == 0) {
		dp[u][1] = H.first;
	}
	else {
		ll s = 0;
		vector<ll> w;
		for (auto v : e[u])
			if (v != p) {
				s += dp[v][0];
				w.push_back(dp[v][1] - dp[v][0]);
			}

		sort(w.begin(), w.end());
		dp[u][1] = s + w[0];
		if (int(w.size()) > 1)
			dp[u][2] = s + w[0] + w[1];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	rep(i, 1, n) {
		cin >> h[i];
		H = max(H, {h[i], i});
	}
	rep(i, 2, n) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	dfs(H.second, 0);
	cout << min(dp[H.second][1] + H.first, dp[H.second][2]) << "\n";

	return 0;
}