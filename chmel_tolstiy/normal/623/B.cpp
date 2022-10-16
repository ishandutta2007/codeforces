#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

long long X, Y;
int n;
int a[1 << 20];

int b[1 << 20];
long long c[1 << 20][2][2];

void update(long long& x, long long a) {
	x = min(x, a);
}

void solve() {
	cin >> n >> X >> Y;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	vector<int> d;
	for (int i = 1; i * i <= a[0] + 1; ++i) {
		if (a[0] % i == 0) {
			d.push_back(i);
			d.push_back(a[0] / i);
		}
		if ((a[0] - 1) % i == 0) {
			d.push_back(i);
			d.push_back((a[0] - 1) / i);
		}
		if ((a[0] + 1) % i == 0) {
			d.push_back(i);
			d.push_back((a[0] + 1) / i);
		}
	}

	for (int i = 1; i * i <= a[n - 1] + 1; ++i) {
		if (a[n - 1] % i == 0) {
			d.push_back(i);
			d.push_back(a[n - 1] / i);
		}
		if ((a[n - 1] - 1) % i == 0) {
			d.push_back(i);
			d.push_back((a[n - 1] - 1) / i);
		}
		if ((a[n - 1] + 1) % i == 0) {
			d.push_back(i);
			d.push_back((a[n - 1] + 1) / i);
		}
	}

	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end()) - d.begin());

	for (int i = 0; i < d.size(); ++i) if (d[i] > 1) {
		for (int j = i + 1; j < d.size(); ++j) if (d[j] % d[i] == 0) d[j] = 0;
	}

	long long ans = (n - 1) * X;

	for (int id = 0; id < d.size(); ++id) {
		int z = d[id];
		if (z <= 1) continue;

		for (int i = 0; i < n; ++i) {
			b[i] = a[i] % z;
			if (b[i] == z - 1) b[i] = 1;
		}

		memset(c, 0x7f, sizeof c);
		if (b[0] <= 1) {
			c[0][0][0] = Y * b[0];
			c[0][0][1] = X;
		}
		if (b[0] > 1) {
			c[0][0][1] = X;
		}

		for (int i = 1; i < n; ++i) {
			if (c[i-1][0][0] < ans) {
				update(c[i][0][1], c[i-1][0][0] + X);
				if (b[i] <= 1) {
					update(c[i][0][0], c[i-1][0][0] + Y * b[i]);
				}
			}

			if (c[i-1][0][1] < ans) {
				update(c[i][0][1], c[i-1][0][1] + X);
				if (b[i] <= 1) {
					update(c[i][1][0], c[i-1][0][1] + Y * b[i]);
				}
			}

			if (c[i-1][1][0] < ans) {
				if (b[i] <= 1) {
					update(c[i][1][0], c[i-1][1][0] + Y * b[i]);
				}
			}
		}

		ans = min(ans, c[n-1][1][0]);
		ans = min(ans, c[n-1][0][1]);
		ans = min(ans, c[n-1][0][0]);
	}

	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}