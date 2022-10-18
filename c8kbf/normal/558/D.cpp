#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

_ n, m, l, r, x, cl, cr, y;
vector<_p> g, a;

int main() {

	scanf("%lld%lld", &n, &m);
	l = 1LL<<(n-1);
	r = (1LL<<n)-1;
	for(; m--; ) {
		scanf("%lld%lld%lld%lld", &x, &cl, &cr, &y);
		for(; x < n; ++x) {
			cl <<= 1;
			cr <<= 1;
			cr |= 1;
		}
		if(y) {
			l = max(l, cl);
			r = min(r, cr);
		} else g.push_back(mp(cl, cr));
	}
	if(l > r) {
		puts("Game cheated!");
		exit(0);
	}
	for(_p i : g) {
		i.first = max(i.first, l);
		i.second = min(i.second, r);
		if(i.first <= i.second) a.push_back(i);
	}
	sort(a.begin(), a.end());
//	printf("rg at %lld, %lld\n", l, r);
	_ s = -1, p = 0;
	for(; l <= r; ) {
//		printf("l updated to %lld\n", l);
		if(p == (_)a.size() || l < a[p].first) {
			if(~s) {
				puts("Data not sufficient!");
				exit(0);
			}
			s = l;
			++l;
		} else {
			l = max(l, a[p].second+1);
			++p;
		}
	}
//	printf("rg finished at %lld, %lld\n", l, r);
	if(!~s) puts("Game cheated!");
	else printf("%lld\n", s);

	return 0;
}