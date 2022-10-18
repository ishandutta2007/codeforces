#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8;

_ tc, n;
char a[maxn];

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld %s", &n, a+1);
		_ lz = -1, s = 0;
		for(_ i = 1; i <= n; ++i) if(a[i] == '0') {
			if(!~lz) lz = i;
			else {
				_ df = i-lz-1;
				s += max(0LL, 2-df);
			}
			lz = i;
		}
		printf("%lld\n", s);
	}

	return 0;
}