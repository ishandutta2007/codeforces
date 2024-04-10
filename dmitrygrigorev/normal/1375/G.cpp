#include <bits/stdc++.h>
#define data jkfgfdkgdf
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

vector<pair<int, int> > dp;

void dfs(int vertex, int last) {

	pair<int, int> p = mp(0, 0);

	for (auto x : data[vertex]) {
		if (x == last) continue;
		dfs(x, vertex);
		p.first += dp[x].second;
		p.second += dp[x].first + 1;
	}

	dp[vertex] = p;

}

int ans = 1e9;

void root(int vertex, int last) {

	pair<int, int> now = dp[vertex];

	if (last != -1) {
		dp[vertex].first += dp[last].second;
		dp[vertex].second += dp[last].first + 1;
	}

	ans = min(ans, dp[vertex].first);

	for (auto x : data[vertex]) {
		if (x == last) continue;
		dp[vertex].first -= dp[x].second;
		dp[vertex].second -= dp[x].first + 1;
		root(x, vertex);
		dp[vertex].first += dp[x].second;
		dp[vertex].second += dp[x].first + 1;
	}

	dp[vertex] = now;

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	data.assign(n, {});
	dp.assign(n, mp(-1, -1));

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		data[a].push_back(b);
		data[b].push_back(a);
	}

	dfs(0, -1);

	root(0, -1);

	cout << ans;




}