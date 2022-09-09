#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
char ans[MAXN];
int n, m, dp[MAXN][2], home[MAXN][2];
ll t[MAXN]; pair <int, int> a[MAXN];

ll func(int s, int c) {
	return 1ll * s * c + 1ll * c * (c - 1) / 2;
}
bool check(ll s, int l, int r) {
	if (s < 0) return false;
	int ql = 0, qr = r - l + 1;
	while (ql < qr) {
		int mid = (ql + qr + 1) / 2;
		if (func(l, mid) <= s) ql = mid;
		else qr = mid - 1;
	}
	return func(l, ql) <= s && s <= func(r - ql + 1, ql);
}
void fill(ll s, int l, int r) {
	if (l > r) {
		assert(s == 0);
		return;
	}
	if (check(s, l + 1, r)) fill(s, l + 1, r);
	else {
		assert(s >= l), ans[l] = '1';
		fill(s - l, l + 1, r);
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(t[i]);
	reverse(t + 1, t + n + 1);
	for (int i = n; i >= 1; i--) {
		if (t[i] == 0) continue;
		else if (m != 0 && t[i] <= t[a[m].second]) a[m].first = i;
		else a[++m] = make_pair(i, i);
	}
	reverse(a + 1, a + m + 1);
	
	if (m == 0) {
		for (int i = 1; i <= n; i++)
			putchar('0');
		putchar('\n');
		return 0;
	}
	
	dp[m + 1][1] = n + 1;
	for (int i = m; i >= 2; i--)
	for (int j = 0; j <= 1; j++)
	for (int k = 0; k <= 1; k++) {
		if (dp[i + 1][j] == 0) continue;
		if (k == 0 && t[a[i].first] != t[a[i].second]) continue;
		ll last = t[a[i + 1].first] - 1 + j;
		for (int p = a[i].first; p > a[i - 1].second && p > dp[i][k]; p--) {
			if (k == 1 && p < a[i].first) break;
			if (k == 0 && p == a[i].first) continue;
			ll now = t[a[i].first] - 1 + k;
			if (check(now - p - last, a[i].second + 1, dp[i + 1][j] - 1)) {
				dp[i][k] = p;
				home[i][k] = j;
			}
		}
	}
	
	int Max = 0, Nax = 0;
	for (int i = a[1].first; i <= a[1].second; i++)
		if (t[i] != 0) {
			if (t[i] == t[a[1].second]) Max++;
			else Nax++;
		}
	
	for (int i = 1; i <= n; i++)
		ans[i] = '0';
	for (int j = 0; j <= 1; j++) {
		if (dp[2][j] == 0) continue;
		ll last = t[a[2].first] - 1 + j;
		for (int p = 0; p <= a[1].second; p++) {
			if (Max != 1 && t[p] == t[a[1].second]) continue;
			if (Nax != 0 && t[p] != t[a[1].second] - 1) continue;
			ll now = (t[p] == 0) ? (t[a[1].second] - 1) : t[p];
			if (check(now - last - p, a[1].second + 1, dp[2][j] - 1)) {
				ans[p] = '1', fill(now - last - p, a[1].second + 1, dp[2][j] - 1);
				int cur = j;
				for (int i = 2; i <= m; i++) {
					int nxt = home[i][cur];
					ll last = t[a[i + 1].first] - 1 + nxt;
					ll now = t[a[i].first] - 1 + cur;
					fill(now - last - dp[i][cur], a[i].second + 1, dp[i + 1][nxt] - 1);
					ans[dp[i][cur]] = '1', cur = nxt;
				}
				reverse(ans + 1, ans + n + 1);
				printf("%s\n", ans + 1);
				return 0;
			}
		}
	}
	
	assert(false);
	return 0;
}