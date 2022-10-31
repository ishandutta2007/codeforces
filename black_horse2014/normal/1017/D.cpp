//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1<<12;

int w[15];
int cnt[N], cost[N];
vector<pair<int, int> > ans[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < m; i++) {
		char s[15]; cin >> s;
		int now = 0;
		for (int j = 0; j < n; j++) now |= (s[j] - '0') << j;
		cnt[now]++;
	}
	for (int i = 0; i < 1 << n; i++) {
		cost[i] = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) continue;
			cost[i] += w[j];
		}
	}
	for (int i = 0; i < 1 << n; i++) {
		vector<pair<int, int> > t;
		for (int j = 0; j < 1 << n; j++) {
			t.emplace_back(cost[i ^ j], cnt[j]);
		}
		sort(t.begin(), t.end());
		for (auto cur : t) {
			if (cur.first > 100) break;
			if (!ans[i].empty() && cur.first == ans[i].back().first) ans[i].back().second += cur.second;
			else ans[i].push_back(cur);
		}
		for (int j = 1; j < ans[i].size(); j++) ans[i][j].second += ans[i][j - 1].second;
	}
	while (q--) {
		char s[15]; int k;
		cin >> s >> k;
		int now = 0;
		for (int j = 0; j < n; j++) now |= (s[j] - '0') << j;
		int cur = lower_bound(ans[now].begin(), ans[now].end(), make_pair(k+1, 0)) - ans[now].begin() - 1;
		int ret;
		if (cur < 0) ret = 0;
		else ret = ans[now][cur].second;
		printf("%d\n", ret);
	}
	return 0;
}