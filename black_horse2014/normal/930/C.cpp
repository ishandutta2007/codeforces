#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
const int INF = 1000000005;

struct WinnerTree {
	int v[N * 4];
	int n;
	
	void init(int m) {
		memset(v, 0, sizeof v);
		for (n = 1; n < m; n *= 2);
	}
	
	void build(int *a, int an) {
		int i;
		for (n = 1; n < an; n *= 2);
		for (i = 0; i < an; i++) v[n + i] = a[i];
		for (i = an; i < n; i++) v[n + i] = a[0];
		for (i = n - 1; i > 0; i--) v[i] = max(v[i * 2], v[i * 2 + 1]);
	}
	
	void up(int i, int val) {
		i += n;
		v[i] = val;
		for (i /= 2; i; i /= 2) v[i] = max(v[i * 2], v[i * 2 + 1]);
	}
	
	int get(int st, int en) {
		int rlt = 0;
		st += n, en += n;
		while (st < en) {
			if (st & 1) rlt = max(rlt, v[st]);
			if (en & 1) rlt = max(rlt, v[en - 1]);
			st = (st + 1) / 2;
			en /= 2;
		}
		return rlt;
	}
} WT;

int a[N], b[N], c[N], d[N];

void add(int x, int v) {
	for (; x < N; x += x & -x) b[x] += v;
}

int get(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += b[x];
	return ret;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d%d", &l, &r);
		add(l, 1);
		add(r + 1, -1);
	}
	for (int i = 1; i <= m; i++) a[i] = get(i);
	WT.init(m + 10);
	for (int i = 1; i <= m; i++) {
		c[i] = WT.get(0, a[i] + 1) + 1;
		WT.up(a[i], c[i]);
	}
	WT.init(m + 10);
	for (int i = m; i >= 1; i--) {
		d[i] = WT.get(0, a[i] + 1) + 1;
		WT.up(a[i], d[i]);
	}
	int ans = 0;
	for (int i = 1; i <= m + 1; i++) {
		ans = max(ans, c[i - 1] + d[i]);
	}
	printf("%d\n", ans);
	return 0;
}