#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e5 + 47;
vector<int> g[N];
vector<int> p, dp, bamboo, res;

void precalc(int u) {
	for (auto& to : g[u]) {
		precalc(to);
		dp[u] = max(dp[u], dp[to] + 1);
	}
	sort(g[u].begin(), g[u].end(), [](int i, int j) {
		return dp[i] < dp[j];
	});
}

void dfs(int u) {
	bamboo.push_back(u);
	for (auto& to : g[u]) dfs(to);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	p.resize(n, -1);
	dp.resize(n, 1);
	for (int i = 1; i < n; ++i) {
		int pr;
		cin >> pr;
		g[pr].push_back(i);
		p[i] = pr;
	}
	precalc(0);
	dfs(0);

	vector<int> st;
	st.push_back(-1);
	for (auto& i : bamboo) {
		while (st.back() != p[i]) {
			st.pop_back();
			res.push_back(i);
		}
		st.push_back(i);
	}

	for (auto& i : bamboo) cout << i << ' ';
	cout << endl << res.size() << endl;
	for (auto& i : res) cout << i << ' ';
}