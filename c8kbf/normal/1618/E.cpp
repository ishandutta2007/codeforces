#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 4E4+8;

_ n, a[maxn], sm, tc, o[maxn];

int main() {
	
	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		sm = 0;
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			sm += a[i];
		}
		if(sm % ((n*(n+1))>>1)) {
			puts("NO");
			continue;
		}
		sm /= (n*(n+1))>>1;
		bool ok = true;
		for(_ i = 1; i <= n; ++i) {
			_ t = a[i == 1 ? n : i-1]-a[i]+sm;
			if(t % n || t/n <= 0) {
				puts("NO");
				ok = false;
				break;
			}
			o[i] = t/n;
		}	
		if(!ok) continue;
		puts("YES");
		for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
		putchar(10);
	}
	
	return 0;
}