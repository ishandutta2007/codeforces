#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n);
		for(int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int f;
		cin >> f;
		vector <int> h(f);
		for(int i = 0; i < f; i++) {
			cin >> h[i];
			--h[i];
		}
		int k;
		cin >> k;
		vector <int> p(k);
		for(int i = 0; i < k; i++) {
			cin >> p[i];
			--p[i];
		}
		vector <int> dist(n, -1);
		queue <int> q;
		dist[0] = 0;
		q.push(0);
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			for(auto next : adj[curr]) {
				if(dist[next] == -1) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}
		vector <int> mask(n, 0);
		for(int i = 0; i < k; i++) {
			mask[h[p[i]]] += 1<<i;
		}
		vector<vector<bool>> dp(n, vector<bool>(1<<k, false));
		dp[0][0] = true;
		queue<pair<int, int>> qq;
		qq.push({0, 0});
		while(!qq.empty()) {
			auto [node, x] = qq.front();
			qq.pop();
			for(auto next : adj[node]) {
				if(dist[next] == dist[node] + 1) {
					if(!dp[next][x|mask[next]])qq.push({next, x|mask[next]});
					dp[next][x|mask[next]] = true;
				}
			}
		}
		vector <int> friends(n, 0);
		for(auto i : h) friends[i]++;
		for(auto i : p) friends[h[i]]--;
		vector<bool> ans(1<<k, false);
		ans[0] = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < friends[i]; j++) {
				// v.push_back(dp[i]);
				vector<bool> nv(1<<k, false);
				for(int a = 0; a < (1<<k); a++) {
					for(int b = 0; b < (1<<k); b++) {
						if(ans[a] && dp[i][b]) {
							nv[a|b] = true;
						}
					}
				}
				ans = nv;
			}
		}
		int o = 0;
		for(int i = 0; i < (1<<k); i++) {
			if(ans[i]) {
				o = max(o, __builtin_popcount(i));
			}
		}
		cout << k - o << '\n';
	}
	
	return 0;
}