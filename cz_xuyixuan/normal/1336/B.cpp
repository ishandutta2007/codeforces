#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, k, tot, pre[MAXN][3], suf[MAXN][3];
pair <int, int> a[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m), read(k), tot = 0;
		for (int i = 1; i <= n; i++) {
			int x; read(x);
			a[++tot] = make_pair(x, 0);
		}
		for (int i = 1; i <= m; i++) {
			int x; read(x);
			a[++tot] = make_pair(x, 1);
		}
		for (int i = 1; i <= k; i++) {
			int x; read(x);
			a[++tot] = make_pair(x, 2);
		}
		sort(a + 1, a + tot + 1);
		for (int i = 0; i <= tot + 1; i++) {
			memset(pre[i], 0, sizeof(pre[i]));
			memset(suf[i], 0, sizeof(suf[i]));
		}
		for (int i = 1; i <= tot; i++) {
			memcpy(pre[i], pre[i - 1], sizeof(pre[i - 1]));
			pre[i][a[i].second] = a[i].first;
		}
		for (int i = tot; i >= 1; i--) {
			memcpy(suf[i], suf[i + 1], sizeof(suf[i + 1]));
			suf[i][a[i].second] = a[i].first;
		}
		ll ans = LLONG_MAX;
		for (int i = 1; i <= tot; i++) {
			for (int j = 0; j <= 2; j++)
			for (int k = 0; k <= 2; k++)
				if (a[i].second != j && a[i].second != k && j != k) {
					int x = a[i].first, y = pre[i][j], z = suf[i][k];
					if (y == 0 || z == 0) continue;
					chkmin(ans, 1ll * (x - y) * (x - y) + 1ll * (x - z) * (x - z) + 1ll * (z - y) * (z - y));
				}
		}
		printf("%lld\n", ans);
	}
	return 0;
}