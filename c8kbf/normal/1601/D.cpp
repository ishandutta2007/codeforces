
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef double _D;
typedef const long long constant;

constant maxn = 5E5+8;

_ n, m, s;
_p a[maxn];

bool cmp(_p x, _p y);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].first, &a[i].second);
	sort(a+1, a+1+n, cmp);
	for(_ i = 1; i <= n; ++i) if(m <= a[i].first) {
		++s;
		m = max(m, a[i].second);
	}
	printf("%lld\n", s);

	return 0;
}

bool cmp(_p x, _p y) {
	if(max(x.first, x.second) == max(y.first, y.second)) return x.first < y.first;
	return max(x.first, x.second) < max(y.first, y.second);
}