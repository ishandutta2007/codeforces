#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E3+8;

_ tc, n, m, a[maxn][maxn], x, y, z, b[maxn][maxn];
char ch, cx, cy, cz;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		x = y = z = 0;
		cx = 'x';
		cy = 'y';
		cz = 'z';
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) scanf("%lld", &a[i][j]);
		for(; m--; ) {
			scanf(" %c", &ch);
			if(ch == 'R') ++y;
			ef(ch == 'L') --y;
			ef(ch == 'D') ++x;
			ef(ch == 'U') --x;
			ef(ch == 'I') {
				swap(y, z);
				swap(cy, cz);
			} else {
				swap(x, z);
				swap(cx, cz);
			}
		}
//		printf("x = %lld, y = %lld, z = %lld, cx = %c, cy = %c, cz = %c\n", x, y, z, cx, cy, cz);
		for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
			_ tx = x;
			if(cx == 'x') tx += i;
			ef(cx == 'y') tx += j;
			else tx += a[i][j];
			tx = (tx%n+n)%n;
			if(!tx) tx = n;
			_ ty = y;
			if(cy == 'x') ty += i;
			ef(cy == 'y') ty += j;
			else ty += a[i][j];
			ty = (ty%n+n)%n;
			if(!ty) ty = n;
			_ vl = z;
			if(cz == 'x') vl += i;
			ef(cz == 'y') vl += j;
			else vl += a[i][j];
			vl = (vl%n+n)%n;
			if(!vl) vl = n;
			b[tx][ty] = vl;
//			printf("tx = %lld, ty = %lld, vl = %lld\n", tx, ty, vl);
		}
		for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) printf("%lld ", b[i][j]);
		putchar(10);
	}

	return 0;
}