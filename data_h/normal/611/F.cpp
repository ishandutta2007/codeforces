#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 5e5 + 10;
const int MOD = 1e9 + 7;

int n, h, w;
char dir[N];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	} else if (a < 0) {
		a += MOD;
	}
}

int sum(int n) {
	return 1LL * (1 + n) * n / 2 % MOD;
}

int power(int a, int b) {
	int ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			ret = 1LL * ret * a % MOD;
		}
		a = 1LL * a * a % MOD;
	}
	return ret;
}

int sum2(int n) {
	return 1LL * n * (n + 1) % MOD * (2 * n + 1) % MOD * power(6, MOD - 2) % MOD;
}

int extra(int i, int first, int t, int delta) {
	// (first - delta) * n + (first - 2delta) * 2n + (first - 3delta) * 3n + ... + (first - tdelta) * tn
	if (delta) {
		t = min(t, first / delta);
	}
	int res = 1LL * first * n % MOD * sum(t) % MOD;
	add(res, -1LL * delta * n % MOD * sum2(t) % MOD);
	add(res, -1LL * (first - delta + first - 1LL * t * delta) * t / 2 % MOD * (n - i) % MOD);
	return res;
}

int go(int n, int h, int w) {
	int l = 1, r = w, d = 1, u = h;
	int res = 0;
	int dx = 0, dy = 0;
	for (int i = 1; i <= n && l <= r && d <= u; i++) {
		add(res, 1LL * (r - l + 1) * (u - d + 1) % MOD);
		if (dir[i] == 'U') {
			dy++;
			if (u + dy > h) {
				u--;
			}
		} else if (dir[i] == 'D') {
			dy--;
			if (d + dy < 1) {
				d++;
			}
		} else if (dir[i] == 'L') {
			dx--;
			if (l + dx < 1) {
				l++;
			}
		} else if (dir[i] == 'R') {
			dx++;
			if (r + dx > w) {
				r--;
			}
		}
	}

	if (l > r || d > u) {
		return res;
	}

	if (dx == 0 && dy == 0) {
		return -1;
	}
/*
cout << "l = " << l << " r = " << r << endl;
cout << "d = " << d << " u = " << u << endl;
*/
	int bak_dx = abs(dx), bak_dy = abs(dy);
	for (int i = 1; i <= n && l <= r && d <= u; i++) {
		add(res, 1LL * (r - l + 1) * (u - d + 1) % MOD);
		if (dir[i] == 'U') {
			dy++;
			if (u + dy > h) {
				u--;
				add(res, extra(i, (r - l + 1), (u - d + 1) / bak_dy, bak_dx));
			}
		} else if (dir[i] == 'D') {
			dy--;
			if (d + dy < 1) {
				d++;
				add(res, extra(i, (r - l + 1), (u - d + 1) / bak_dy, bak_dx));
			}
		} else if (dir[i] == 'L') {
			dx--;
			if (l + dx < 1) {
				l++;
				add(res, extra(i, (u - d + 1), (r - l + 1) / bak_dx, bak_dy));
			}
		} else if (dir[i] == 'R') {
			dx++;
			if (r + dx > w) {
				r--;
				add(res, extra(i, (u - d + 1), (r - l + 1) / bak_dx, bak_dy));
			}
		}
	}

	return res;
}

int main() {
	scanf("%d %d %d", &n, &h, &w);
	scanf("%s", dir + 1);
	cout << go(n, h, w) << endl;
	return 0;
}