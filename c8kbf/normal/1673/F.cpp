#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 32+8;

_ n, m, a[maxn][maxn], x;
_p pl[maxn*maxn];

void cl(_ x, _ y, _ t);
void cr(_ x, _ y, _ t);
_ vl(_ x, _ y);
int main() {

	cr(1, 16, 1LL<<9);
	cl(1, 16, 1LL<<8);

	cr(1, 8, 1LL<<7);
	cl(1, 8, 1LL<<6);
	cr(25, 32, 1LL<<7);
	cl(25, 32, 1LL<<6);

	cr(1, 4, 1LL<<5);
	cl(1, 4, 1LL<<4);
	cr(29, 32, 1LL<<5);
	cl(29, 32, 1LL<<4);
	cr(13, 20, 1LL<<5);
	cl(13, 20, 1LL<<4);

	cr(3, 6, 1LL<<3);
	cl(3, 6, 1LL<<2);
	cr(11, 14, 1LL<<3);
	cl(11, 14, 1LL<<2);
	cr(19, 22, 1LL<<3);
	cl(19, 22, 1LL<<2);
	cr(27, 30, 1LL<<3);
	cl(27, 30, 1LL<<2);

	cr(2, 3, 2);
	cl(2, 3, 1);
	cr(6, 7, 2);
	cl(6, 7, 1);
	cr(10, 11, 2);
	cl(10, 11, 1);
	cr(14, 15, 2);
	cl(14, 15, 1);
	cr(18, 19, 2);
	cl(18, 19, 1);
	cr(22, 23, 2);
	cl(22, 23, 1);
	cr(26, 27, 2);
	cl(26, 27, 1);
	cr(30, 31, 2);
	cl(30, 31, 1);

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n-1; ++j) {
		_ ta = vl(i, j), tb = vl(i, j+1);
		printf("%lld ", ta^tb);
	}
	for(_ i = 1; i <= n-1; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) {
		_ ta = vl(i, j), tb = vl(i+1, j);
		printf("%lld ", ta^tb);
	}
	fflush(stdout);
	for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) pl[vl(i, j)] = mp(i, j);
	_ l = vl(1, 1);
	for(; m--; ) {
		scanf("%lld", &x);
		l ^= x;
		printf("%lld %lld\n", pl[l].first, pl[l].second);
		fflush(stdout);
	}

	return 0;
}

_ vl(_ x, _ y) {
	return a[x][y];
}

void cr(_ x, _ y, _ t) {
	for(_ i = x; i <= y; ++i) for(_ j = 1; j <= 32; ++j) a[i][j] ^= t;
	return;
}

void cl(_ x, _ y, _ t) {
	for(_ i = 1; i <= 32; ++i) for(_ j = x; j <= y; ++j) a[i][j] ^= t;
	return;
}