#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, m, a[maxn], x, g = -1;

_ gcd(_ a, _ b);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a+1, a+1+n);
	for(_ i = 1; i <= n-1; ++i) g = gcd(g, a[i+1]-a[i]);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld", &x);
		printf("%lld ", gcd(g, a[1]+x));
	}
	putchar(10);

	return 0;
}

_ gcd(_ a, _ b) {
	if(!~a) return b;
	if(!b) return a;
	return gcd(b, a%b);
}