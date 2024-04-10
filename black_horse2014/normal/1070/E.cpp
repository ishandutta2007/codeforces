#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[220000];

long long s[220000];
long long d[220000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int N, M; long long T; cin >> N >> M >> T;
		for (int i = 1; i <= N; i++) cin >> a[i].first, a[i].second = i;
		sort(a + 1, a + N + 1);
		memset(d, 0, sizeof(long long) * (N + 1));
		memset(s, 0, sizeof(long long) * (N + 1));
		auto add = [&](int u, int x) {
			for (; u <= N; u += u & -u) d[u]++, s[u] += x;
		};
		auto get = [&](long long *d, int u) {
			long long ret = 0;
			for (; u; u -= u & -u) ret += d[u];
			return ret;
		};
		auto get_low = [&](long long *s, long long T) {
			int ret = 0;
			for (int k = 17; k >= 0; k--) {
				if (ret + (1<<k) > N) continue;
				if (s[ret + (1<<k)] > T) continue;
				ret += 1<<k;
				T -= s[ret];
			}
			return ret;
		};
		int ans = 0, ret = 1;
		for (int i = 1, j; i <= N; i = j) {
			for (j = i; j <= N && a[j].first == a[i].first; j++) add(a[j].second, a[j].first);
			int pos = get_low(s, T / 2);
			int cnt = get(d, pos) / M * M;
			pos = get_low(d, cnt);
			long long sum = get(s, pos);
			cnt = min(get(d, get_low(s, T - sum)), (long long)cnt + M);
			if (cnt > ans) {
				ans = cnt;
				ret = a[i].first;
			}
		}
		cout << ans << ' ' << ret << endl;
	}
	return 0;
}