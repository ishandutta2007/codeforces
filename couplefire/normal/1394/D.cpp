#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
        int n;
        cin >> n;
	vector<int> t(n), h(n);
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < n; i++)
		cin >> h[i];
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<bool> vis(n);
	vector<array<ll, 2>> dp(n);
	function<void(int)> dfs = [&](int v) {
                vis[v] = true;
		int hv = h[v];		
		int in = 0;
		int out = 0;
		vector<ll> dif;
		bool has_up = false;
		ll score = 0;
		for (auto w: g[v]) {
			if (h[w] != hv) {
				if (h[w] > hv)
					out++;
				else
					in++;
				continue;
			}
			if (vis[w]) {
				has_up = true;
				continue; 
			}
			dfs(w);
			score += dp[w][0];
			dif.push_back(dp[w][1] - dp[w][0]);
		}
		sort(dif.begin(), dif.end());
		ll tv = t[v];
		in += dif.size();
		if (!has_up) {
		        dp[v][0] = score + max(in, out) * tv;
			for (int i = 0; i < dif.size(); i++) {
				in--; out++;
				score += dif[i];
				dp[v][0] = min(dp[v][0], score + max(in, out) * tv);
			}			
		} else {
		        dp[v][0] = score + max(in, out + 1) * tv;
		        dp[v][1] = score + max(in + 1, out) * tv;
			for (int i = 0; i < dif.size(); i++) {
				in--; out++;
				score += dif[i];
				dp[v][0] = min(dp[v][0], score + max(in, out + 1) * tv);
				dp[v][1] = min(dp[v][1], score + max(in + 1, out) * tv);
			}			
		}
		
	};
	ll res = 0;
	for (int i = 0; i < n; i++) {
	        if (!vis[i]) {
			dfs(i);
//			cout << "dfs[" << i << "] = " << dp[i][0] << endl; 
			res += dp[i][0];
		}
	} 
	cout << res << endl;
	return 0;
}