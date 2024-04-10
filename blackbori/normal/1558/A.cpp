#include <bits/stdc++.h>

using namespace std;

int C[202020];

void tc() {
	int a, b, x, y, m, i, s, l, r;
	cin >> a >> b; m = a + b;
	fill(C, C + m + 1, 0);

	x = (m + 1) / 2; y = m / 2;
	l = max(0, x - a) + max(0, y - b);
	r = min(x, b) + min(y, a);
	for (i = l; i <= r; i += 2) C[i] = 1;

	x = m / 2; y = (m + 1) / 2;
	l = max(0, x - a) + max(0, y - b);
	r = min(x, b) + min(y, a);
	for (i = l; i <= r; i += 2) C[i] = 1;

	for (i = s = 0; i <= m; i++) {
		if (C[i]) s++;
	}
	cout << s << "\n";
	for (i = 0; i <= m; i++) {
		if (C[i]) cout << i << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}