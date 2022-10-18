

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ tc, x, y;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld %lld", &x, &y);
		_ p = -1, c = 0;
		for(_ i = 45; i >= 0; --i) {
			bool a = !!(x & (1LL<<i)), b = !!(y & (1LL<<i));
			if(!a && b) {
				p = i;
				++c;
			} ef(!b && a) break;
		}
		_ msk = (1LL<<p)-1;
//		printf("p = %lld, msk = %lld\n", p, msk);
		_ sa = (1LL<<p)-(msk&x)+(c > 1 || !!(msk&y)), sb = abs((msk&x)-(msk&y))+1;
//		printf("sa = %lld, sb = %lld\n", sa, sb);
		printf("%lld\n", min(sa, sb));
	}

	return 0;
}