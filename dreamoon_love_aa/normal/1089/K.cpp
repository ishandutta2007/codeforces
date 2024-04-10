#include <bits/stdc++.h>
using namespace std;
struct N {
	long long mn;
	long long ad;
}t[2700020];
void bd(int x, int l, int r) {
	if (l == r - 1) {
		t[x].mn = -l;
		return;
	}
	int m = (l + r) / 2;
	bd(x * 2, l, m);
	bd(x * 2 + 1, m, r);
	t[x].mn = min(t[x * 2].mn, t[x * 2 + 1].mn);
}
void push(int x) {
	t[2 * x].ad += t[x].ad;
	t[2 * x].mn += t[x].ad;
	t[2 * x + 1].ad += t[x].ad;
	t[2 * x + 1].mn += t[x].ad;
	t[x].ad = 0;
}

long long qy(int x, int l, int r, int L, int R) {
	if (r <= L || R <= l) {
		return (long long)1e18;
	}
	if (L <= l && r <= R) {
		return t[x].mn;
	}
	push(x);
	int m = (l + r) / 2;
	return min(qy(x * 2, l, m, L, R), qy(x * 2 + 1, m, r, L, R));
}
void add(int x, int l, int r, int L, int R, int V) {
	if (r <= L || R <= l) {
		return;
	}
	if (L <= l && r <= R) {
		t[x].ad += V;
		t[x].mn += V;
		return;
	}
	push(x);
	int m = (l + r) / 2;
	add(x * 2, l, m, L, R, V);
	add(x * 2 + 1, m, r, L, R, V);
	t[x].mn = min(t[x * 2].mn, t[x * 2 + 1].mn);
}
int a[300020];
int b[300020];
int main() {
	int n;
	scanf("%d", &n);
	bd(1, 0, 1000010);
	for (int i = 1; i <= n; i++) {
		char o[3];
		scanf("%s%d", o, &a[i]);
		if (*o == '+') {
			scanf("%d", &b[i]);
			add(1, 0, 1000010, a[i], 1000010, b[i]);
		} else if (*o == '?') {
			long long ans1 = qy(1, 0, 1000010, a[i], a[i] + 1);
			long long ans2 = qy(1, 0, 1000010, 0, a[i]);
//			cerr << ans1 << ' ' << ans2 << endl;
			printf("%lld\n", ans1 - ans2 + 1);
		} else {
			add(1, 0, 1000010, a[a[i]], 1000010, -b[a[i]]);
		}
	}
	return 0;
}