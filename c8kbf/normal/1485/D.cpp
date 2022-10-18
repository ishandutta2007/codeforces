#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E2+8;

_ n, m, x;

int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= m; ++j) {
		scanf("%lld", &x);
		if((i+j)&1) printf("720720 ");
		else printf("%lld ", 720720+x*x*x*x);
	}

	return 0;
}