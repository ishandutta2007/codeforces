#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;
constant maxlg = 30;

_ tc, l, r, n, a[maxn], bt[maxn], nd[maxn];

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &l, &r);
		n = r-l+1;
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		for(_ i = 1; i <= 17; ++i) bt[i] = nd[i] = 0;
		for(_ i = 1, cr = l; i <= n; ++i, ++cr) {
			for(_ j = 1, k = 1; j <= 17; ++j, k <<= 1) {
				if(k & a[i]) ++bt[j];
				if(k & cr) ++nd[j];
			}
		}
		_ s = 0;
		for(_ i = 1, j = 1; j <= 17; ++j, i <<= 1) if(bt[j] != nd[j]) {
//			printf("j = %lld, bt[j] = %lld, nd[j] = %lld\n", j, bt[j], nd[j]);
			s ^= i;
		}
		printf("%lld\n", s);
	}

	return 0;
}