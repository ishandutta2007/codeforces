#include <bits/stdc++.h>

using namespace std;

int C[202020];

void tc() {
	int n, l, r, i, c;
	int a, x0, y0, x1, y1;

	cin >> n >> l >> r;
	fill(C, C + n + 1, 0);
	for (i = 1; i <= n; i++) {
		cin >> c;
		if (i <= l) C[c]++;
		else C[c]--;
	}

	a = 0; x0 = y0 = x1 = y1 = 0;
	for (i = 1; i <= n; i++) {
		if (C[i] > 0) {
			x1 += C[i] / 2;
			x0 += C[i];
		}
		if (C[i] < 0) {
			y1 += -C[i] / 2;
			y0 += -C[i];
		}
	}

	if (x0 < y0) swap(x0, y0), swap(x1, y1);

	if (x0 - y0 <= x1 + x1) {
		cout << (x0 + y0) / 2 << "\n";
	}
	else {
		x0 -= x1 + x1;
		cout << x0 + x1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}