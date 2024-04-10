#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


const int N = (int)2e5 + 7;
int n;
vector<int> g[N];
ll score[N];
ll c[N];
ll e[N];
ll dp[N];
ll sol;

void build(int a) {
	sol += c[a] * score[a];
	if (!g[a].empty()) {
		int dim = (int)g[a].size();
		for (auto& b : g[a]) {
			c[b] = c[a] / dim;
			build(b);
		}
		e[a] = c[a] % dim;
	}
}

void dfs(int a) {
	if (!g[a].empty()) {
		int dim = (int)g[a].size();
		vector<ll> guys;
		for (auto& b : g[a]) {
			dfs(b);
			guys.push_back(dp[b]);
		}
		sort(guys.rbegin(), guys.rend());
		for (int j = 0; j < e[a]; j++) {
			sol += guys[j];;
		}
		dp[a] = guys[e[a]] + score[a];
	}
	else {
		dp[a] = score[a];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> n >> k;
		sol = 0;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			c[i] = 0;
			e[i] = 0;
			dp[i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			int pri;
			cin >> pri;
			g[pri].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			cin >> score[i];
		}
		c[1] = k;
		build(1);
		dfs(1);
		cout << sol << "\n";
	}
	return 0;
}