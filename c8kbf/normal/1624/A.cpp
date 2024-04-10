#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 50+8;

_ tc, a[maxn], mx, n;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		mx = *max_element(a+1, a+1+n);
		_ mn = *min_element(a+1, a+1+n);
		printf("%lld\n", mx-mn);
	}

	return 0;
}