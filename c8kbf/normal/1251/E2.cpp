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

constant maxn = 2E5+8;

_ tc, n, c, s;
_p a[maxn];
priority_queue<_, v_, greater<_> > q;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		c = 0;
		for(; !q.empty(); ) q.pop();
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld%lld", &a[i].first, &a[i].second);
			c += a[i].second;
		}
		s = c;
		sort(a+1, a+1+n, greater<_p>());
		for(_ i = 1; i <= n; ++i) {
			q.push(a[i].second);
			c -= a[i].second;
			if(a[i].first > n-(_)q.size()) {
				c += q.top();
				q.pop();
			}
			s = min(s, c);
		}
		printf("%lld\n", s);
	}

	return 0;
}