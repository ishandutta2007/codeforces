#include <bits/stdc++.h>
using namespace std;

const int N = 255000;

vector<pair<int, int> > adj[N];
vector<int> e[N];
int sz[N], cnt[N];
long long dp[N][2], gsum[N], sum[N];
multiset<long long> f[N], g[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
    long long ans = 0;
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		ans += w;
	}
    for (int i = 1; i <= n; i++) sz[i] = adj[i].size();
    set<int> a;
    for (int i = 1; i <= n; i++) {
        a.insert(i);
		sort(adj[i].begin(), adj[i].end(), [&](pair<int, int> a, pair<int, int> b) { return sz[a.first] > sz[b.first];});
        e[sz[i]].push_back(i);
    }
    cout << ans << '\n';
    for (int L = 1; L < n; L++) {
        for (int j : e[L]) a.erase(j);
        auto adjust = [&](int u, int t) {
        	assert(f[u].size() >= t || g[u].empty());
            while (f[u].size() > t) {
                auto it = --f[u].end();
                long long y = *it;
                if (y <= 0) break;
                g[u].insert(y);
                gsum[u] += y;
                f[u].erase(it);
            }
        };
        auto add = [&](int u, long long x) {
        	sum[u] += x;
			if (!g[u].empty() && *g[u].begin() <= x) {
                g[u].insert(x);
                gsum[u] += x;
            } else {
                f[u].insert(x);
            }
        };
        auto del = [&](int u, long long x) {
        	sum[u] -= x;
			if (!g[u].empty() && *g[u].begin() <= x) {
                g[u].erase(g[u].find(x));
                gsum[u] -= x;
            } else {
                f[u].erase(f[u].find(x));
                if (!g[u].empty()) {
                    auto it = g[u].begin();
                    long long y = *it;
                    f[u].insert(y);
                    gsum[u] -= y;
                    g[u].erase(it);
                }
            }
        };
        function<void(int, int)> dfs = [&](int u, int p) {
            cnt[u] = L;
            while (!adj[u].empty()) {
                auto t = adj[u].back();
                int v = t.first, w = t.second;
                if (sz[v] <= L) {
					add(u, w);
					adj[u].pop_back();
                } else {
                    break;
                }
            }
            long long ret = 0;
            for (auto t : adj[u]) {
                int v = t.first, w = t.second;
                if (v == p) continue;
                dfs(v, u);
                ret += dp[v][0];
                add(u, dp[v][1] + w - dp[v][0]);
            }
            adjust(u, sz[u] - cnt[u]);
            dp[u][0] = ret + sum[u] - gsum[u];
            adjust(u, sz[u] - cnt[u] - 1);
            dp[u][1] = ret + sum[u] - gsum[u];
            for (auto t : adj[u]) {
                int v = t.first, w = t.second;
                if (v == p) continue;
                del(u, dp[v][1] + w - dp[v][0]);
            }
        };
        ans = 0;
        for (int u : a) {
            if (cnt[u] < L) {
				dfs(u, 0);
                ans += dp[u][0];
            }
        }
        cout << ans << '\n';
    }
	return 0;
}