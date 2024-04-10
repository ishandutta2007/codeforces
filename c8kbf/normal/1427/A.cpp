#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 50+8;

_ n, a[maxn], tc;

int main() {
	
	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			if(!a[i]) a[i] = 88;
		}
		sort(a+1, a+1+n);
		_ c = 0;
		bool ok = true;
		for(_ i = 1; i <= n; ++i) {
			if(a[i] == 88) a[i] = 0;
			c += a[i];
			if(!c) {
				ok = false;
			}
		}
		if(ok) {
			puts("YES");
			for(_ i = 1; i <= n; ++i) printf("%lld ", a[i]);
			putchar(10);
			continue;
		}
		ok = true;
		for(_ i = 1; i <= n; ++i) if(!a[i]) a[i] = -88;
		sort(a+1, a+1+n, greater<_>());
		c = 0;
		for(_ i = 1; i <= n; ++i) {
			if(a[i] == -88) a[i] = 0;
			c += a[i];
			if(!c) {
				ok = false;
			}
		}
		if(ok) {
			puts("YES");
			for(_ i = 1; i <= n; ++i) printf("%lld ", a[i]);
			putchar(10);
		} else puts("NO");
	}
		
	return 0;
}