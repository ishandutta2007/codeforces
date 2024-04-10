#include <bits/stdc++.h>
using namespace std;

int a[1100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, c; scanf("%d%d%d", &n, &m, &c);
	int tot = n;
	while (m--) {
		int x; scanf("%d", &x);
		if (x <= c/2) {
			bool found = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] == 0 || a[j] > x) {
					if (!a[j]) tot--;
					found = 1;
					cout << j << endl;
					a[j] = x;
					break;
				}
			}
			if (!found) {
				if (!a[n]) tot--;
				cout << n << endl, a[n] = x;
			}
			if (!tot) return 0;
		} else {
			bool found = 0;
			for (int j = n; j > 0; j--) {
				if (a[j] < x) {
					if (!a[j]) tot--;
					found = 1;
					cout << j << endl;
					a[j] = x;
					break;
				}
			}
			if (!found) {
				if (!a[1]) tot--;
				cout << 1 << endl, a[1] = x;
			}
			if (!tot) return 0;
		}
	}
	return 0;
}