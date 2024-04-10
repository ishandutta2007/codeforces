#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, a[maxn][maxn*maxn], x, y, xs, ys;

int main() {

	memset(a, -4, sizeof a);
	a[0][0] = 0;

	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld", &x, &y);
		xs += x;
		ys += y;
		for(_ j = i; j >= 1; --j) for(_ k = x; k <= xs; ++k) a[j][k] = max(a[j][k], a[j-1][k-x]+y);
	}
	for(_ i = 1; i <= n; ++i) {
		_ s = 0;
		for(_ j = 0; j <= xs; ++j) {
			s = max(s, min(j<<1, ys+a[i][j]));
//			printf("i = %lld, j = %lld, a[i][j] = %lld, ms updated to %lld\n", i, j, a[i][j], min(j<<1, ys+a[i][j]));
		}
		printf("%lld", s>>1);
		if(s & 1) printf(".5");
		putchar(32);
	}
	putchar(10);

	return 0;
}