#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
const int M = 1e9+7;
vector<int> T[N];
map<ll,int> dp[N];
ll b[N];

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

// (gcd --> amount) in store
int dfs(int v, int p) {
	int ans = 0;
	if(p != -1) {
		for(const auto& x : dp[p]) {
			ll g = gcd(x.first, b[v]);
			dp[v][g] = (dp[v][g] + x.second) % M;
		}
	}
	dp[v][b[v]] = (dp[v][b[v]] + 1) % M;
	for(const auto& x : dp[v])
		ans = (ans + x.first * x.second) % M;
	for(int u : T[v]) {
		if(u == p) continue;
		ans = (ans + dfs(u, v)) % M;
	}
	dp[v].clear();
	return ans;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> b[i];

	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	cout << dfs(0, -1) << '\n';
}