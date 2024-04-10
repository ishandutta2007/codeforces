#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int n, a[N], m, b[N];
int tree[N << 2];

void build(int x, int l, int r) {
	if (l > r) return ;
	tree[x] = b[l];
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}

int ask(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return tree[x];
	if (r < ql || qr < l) return 0;
	int mid = (l + r) / 2;
	return max(ask(x << 1, l, mid, ql, qr), ask(x << 1 | 1, mid + 1, r, ql, qr));
}

int ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) b[i] = min(a[i], a[i + 1]);
	build(1, 1, n - 1);
	for (int k = 0; k <= n - 2; k++) {
		m = n - k;
		if (m & 1) {
			ans[k] = ask(1, 1, n - 1, m / 2, k + m / 2 + 1);
		} else {
		}
	}

	for (int i = 1; i < n; i++) b[i] = max(a[i], a[i + 1]);
	build(1, 1, n - 1);
	for (int k = 0; k <= n - 2; k++) {
		m = n - k;
		if (m & 1) {
		} else {
			ans[k] = ask(1, 1, n - 1, m / 2, k + m / 2);
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[n - 1] = max(ans[n - 1], a[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
}