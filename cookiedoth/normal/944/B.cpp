#include <bits/stdc++.h>
#define ll long long
#define null null

using namespace std;

const int INF = 1e9;
const int mx = 3e5;
int a[mx], n, mn, c1, c2, c3, sum, b1, b2, b3, ans = INF, bg = -INF;

int get(int d1, int d2, int d3) {
	return min(c1, d1) + min(c2, d2) + min(d3, c3);
}

int d1, d2, d3;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mn = INF;
	for (int i = 0; i < n; ++i) {
		mn = min(mn, a[i]);
		bg = max(bg, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == mn)
			c1++;
		if (a[i] == mn + 1)
			c2++;
		if (a[i] == mn + 2)
			c3++;
	}
	if (bg - mn <= 1) {
		cout << n << endl;
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
		return 0;
	}
	sum = c3 - c1;
	for (int d2 = 0; d2 <= n; ++d2) {
		if ((n - d2 - sum) % 2 == 0) {
			int d1 = (n - d2 - sum) / 2;
			int d3 = d1 + sum;
			//cout << d1 << " " << d2 << " " << d3 << endl;
			if (0 <= d1 && d1 <= n && 0 <= d3 && d3 <= n) {
				int res = get(d1, d2, d3);
				if (res < ans) {
					ans = res;
					b1 = d1;
					b2 = d2;
					b3 = d3;
				}
			}
		}
	}
	//cout << b1 << " " << b2 << " " << b3 << endl;
	cout << ans << endl;
	for (int j = 0; j < b1; ++j) {
		cout << mn << " ";
	}
	for (int j = 0; j < b2; ++j) {
		cout << mn + 1 << " ";
	}
	for (int j = 0; j < b3; ++j) {
		cout << mn + 2 << " ";
	}
	cout << endl;
}