#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<19;

long long a[MAXN], s[MAXN], dp[MAXN], add[MAXN], ans[MAXN];

void renew(int u, long long x) {
	dp[u] += x, add[u] += x;
}

void down(int u) {
	if (!add[u]) return;
	renew(u + u, add[u]);
	renew(u + u + 1, add[u]);
	add[u] = 0;
}

void up(int u) {
	dp[u] = max(dp[u + u], dp[u + u + 1]);
}

void modify(int u, int l, int r, int ll, int rr, long long x) {
	if (ll <= l && r <= rr) {
		renew(u, x);
		return;
	}
	int mid = l + r >> 1;
	down(u);
	if (ll <= mid) modify(u + u, l, mid, ll, rr, x);
	if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr, x);
	up(u);
}

long long query(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return dp[u];
	int mid = l + r >> 1;
	long long ret = 0;
	down(u);
	if (ll <= mid) ret = max(ret, query(u + u, l, mid, ll, rr));
	if (mid < rr) ret = max(ret, query(u + u + 1, mid + 1, r, ll, rr));
	return ret;
}

int main() {
	int n; long long C; scanf("%d%lld", &n, &C);
	for (int i = 1; i <= 2*n-1; i++) scanf("%lld", &a[i]), a[i] = min(C, a[i]);
	for (int i = 1; i <= 2*n-1; i++) s[i] = s[i-1] + a[i];
	long long cur = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (s[2*i-1] - s[2*j-2] > C) j++, cur = max(cur, ans[j-2] + C);
		modify(1, 0, n, 0, i-1, a[2*i-1]);
		if (i > 1) modify(1, 0, n, 0, i-2, a[2*i-2]);
		ans[i] = max(query(1, 0, n, j-1, i-1), cur);
		modify(1, 0, n, i, i, ans[i]);
	}
	cout << ans[n] << endl;
	return 0;
}