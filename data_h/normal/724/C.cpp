#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


int n, m, k;

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long temp = x;
    x = y;
    y = temp - a / b * y;
    return d;
}

long long test(int n, int m, int x, int y, int dx, int dy) {
	if (x < y) {
		swap(x, y);
		swap(n, m);
		swap(dx, dy);
	}
	long long a, b;
	long long d = exgcd(m, n, b, a);
	if ((x - y) % d != 0) {
		return -1;
	} else {
		b *= (x - y) / d;
		a *= (x - y) / d;
		a = -a;

		long long stepa = m / d, stepb = n / d;
		long long bb = (b % stepb + stepb) % stepb;
		a += (bb - b) / stepb * stepa;
		b = bb;
		if ((a & 1) != dx) {
			b += stepb;
			a += stepa;
		}
		if ((b & 1) != dy) {
			b += stepb;
			a += stepa;
		}
		if ((a & 1) != dx || (b & 1) != dy) {
			return -1;
		}
		assert(b * m + y == a * n + x);
		long long ret = b * m + y;
		if (ret > n / d * m) {
			return -1;
		} else {
			return ret;
		}
	}
}

long long test(int n, int m, int x, int y) {
	long long ret = -1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int xx = (i & 1) ? n - x : x;
			int yy = (j & 1) ? m - y : y;
			long long tmp = test(n, m, xx, yy, i, j);
			if (ret == -1 || (tmp != -1 && tmp < ret)) {
				ret = tmp;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%I64d\n", test(n, m, x, y));
	}
	return 0;
}