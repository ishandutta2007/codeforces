#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int NMAX = 50050, KMAX = 505;

vector<vector<int>> edges;
int dp[NMAX][KMAX];
int amt[NMAX];
int N, K;

int dfs(int u, int par, ll& ans) {
	ll even = 0;
	for(int i=0;i<edges[u].size();++i) {
		if(edges[u][i] == par) continue;
		dfs(edges[u][i], u, ans);
		int v = edges[u][i];
		for(int j=0;j<K;++j) {
			dp[u][j+1] += dp[v][j];
		}
		if(K%2==0 && K >= 2) {
			even -= (ll) dp[v][(K-2)/2]*dp[v][(K-2)/2];
		}
		for(int i=0;i<(K-1)/2;++i) {
			ans -= (ll) dp[v][i]*dp[v][K-2-i];
		}
	}
	dp[u][0] = 1;
	if(K%2 == 0) {
		even += (ll) dp[u][K/2]*dp[u][K/2];
	}
	even /= 2;
	for(int i=0;i<(K+1)/2;++i)
	{
		ans += (ll) dp[u][i]*dp[u][K-i];
		//cerr << " ans += (ll) dp[" << u << "][" << i << "]*dp[u][" << K-i << "]; " << (ll) dp[u][i] << "*" << dp[u][K-i] << endl;
	}
	ans += even;

	dp[u][0] = 1;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	cin >> K;
	edges.resize(N+1);
	for(int i=0;i<N-1;++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	ll ans = 0;
	dfs(1, -1, ans);
	cout << ans;

	return 0;
}