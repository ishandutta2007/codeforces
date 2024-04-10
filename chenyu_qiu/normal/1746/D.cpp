#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, p[N], s[N];
vector<int> e[N];

map<long long, long long> dp;
long long dfs(int u, int k) {
	if (k == 0) {
		return 0;
	}

	if (e[u].empty()) {
		return 1ll * k * s[u];
	}

	long long id = 1ll * k * n + u;
	if (dp.count(id)) {
		return dp[id];
	}
	
	long long res = 1ll * k * s[u];
	vector<long long> x;
	int t = e[u].size();
	int rest = k % t;
	x.reserve(t);

	for (auto v : e[u]) {
		long long cur = dfs(v, k / t);
		res += cur;
		if (rest) {
			x.push_back(dfs(v, k / t + 1) - cur);
		}
	}

	sort(x.begin(), x.end(), greater<int>());
	for (int i = 0; i < rest; ++i) {
		res += x[i];
	}

	return dp[id] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int t;
    cin >> t;

    while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
		}
		for (int i = 2; i <= n; ++i) {
			cin >> p[i];
			e[p[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
		}
		
		dp.clear();
		cout << dfs(1, k) << "\n";
	}
	
	return 0;
}