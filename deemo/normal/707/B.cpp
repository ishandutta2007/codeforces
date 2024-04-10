#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, k, x[MAXN], mark[MAXN];
vector<pair<int, int>>	adj[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	if (k == n || k == 0){
		cout << "-1\n";
		return 0;
	}
	while (m--){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for (int i = 0; i < k; i++)
		cin >> x[i], x[i]--, mark[x[i]] = 1;
	int ans = 2e9;
	for (int i = 0; i < k; i++)
		for (auto e:adj[x[i]])
			if (!mark[e.first])
				ans = min(ans, e.second);
	if (ans > 1e9)
		ans = -1;
	cout << ans << "\n";
	return 0;
}