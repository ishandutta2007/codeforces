#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<int> cost;

int dfs(int vertex, int last, int d) {
	int cnt = 1;
	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		cnt += dfs(to, vertex, d+1);
	}

	cost.push_back(d - (cnt-1));
	return cnt;

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	data.assign(n, {});
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}


	dfs(0, -1, 0);
	sort(all(cost), greater<int>());

	ll ans = 0;
	for (int i = 0; i < k; ++i) ans += cost[i];
	cout << ans;


}