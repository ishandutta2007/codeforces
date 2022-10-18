

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E5+8;
constant lg = 40;

_ n, a[maxn], t[lg][maxn], l[maxn];

_ qr(_ x, _ y);
_ gcd(_ a, _ b);
int main() {

	scanf("%lld", &n);
	for(_ i = 2; i <= n; ++i) l[i] = l[i>>1]+1;
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = 1; i <= n; ++i) t[0][i] = a[i];
	for(_ i = 1; i <= l[n]; ++i) for(_ j = 1; j+(1LL<<i)-1 <= n; ++j) t[i][j] = gcd(t[i-1][j], t[i-1][j+(1LL<<(i-1))]);

//	printf("qr = %lld\n", qr(2, 3));
//	exit(0);

	_ s = 0, p = 1;
	for(_ i = 1; i <= n; ++i) {
		for(; p < i && qr(p, i) < i-p+1; ) ++p;
		if(qr(p, i) == i-p+1) {
			++s;
			p = i+1;
		}
		printf("%lld ", s);
	}
	putchar(10);

	return 0;
}

_ gcd(_ a, _ b) {
	return !b ? a : gcd(b, a%b);
}

_ qr(_ x, _ y) {
//	printf("x = %lld, y = %lld\n", x, y);
	_ c = l[y-x+1];
//	printf("returned t[%lld][%lld] = %lld, t[%lld][%lld] = %lld\n", c, x, t[c][x], c, y-(1LL<<c)+1, t[c][y-(1LL<<c)+1]);
	return gcd(t[c][x], t[c][y-(1LL<<c)+1]);
}