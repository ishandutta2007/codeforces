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

constant maxn = 2E5+8;

_ tc, n;
char a[maxn];

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf(" %s", a+1);
		n = strlen(a+1);
		if(n == 1) printf("Bob %lld\n", (_)a[1]-'a'+1);
		ef(!(n & 1)) {
			_ s = 0;
			for(_ i = 1; i <= n; ++i) s += (_)a[i]-'a'+1;
			printf("Alice %lld\n", s);
		} else {
			_ s = 0;
			for(_ i = 1; i <= n; ++i) s += (_)a[i]-'a'+1;
			_ ca = a[1]-'a'+1, cb = a[n]-'a'+1;
			_ vl = max(s-2*ca, s-2*cb);
			if(vl < 0) printf("Bob %lld\n", -vl);
			else printf("Alice %lld\n", vl);
		}
	}

	return 0;
}