#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

int T;
ll n, m, x1, y1, x2, y2, x3, x4, y3, y4, s;

ll calc(ll n, ll m) {
	ll s = 0;
	s += (n + 1) / 2 * (m / 2);
	s += n / 2 * ((m + 1) / 2);
	return s;
}

ll c(ll x1, ll y1, ll x2, ll y2) {
	return calc(x2, y2)	- calc(x1 - 1, y2) - calc(x2, y1 - 1) + calc(x1 - 1, y1 - 1);
}

int main() {
//	freopen("cc.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%I64d %I64d", &n, &m);
		scanf("%I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2);
		scanf("%I64d %I64d %I64d %I64d", &x3, &y3, &x4, &y4);
		s = calc(n, m);
		s -= c(x1, y1, x2, y2);
		s += (x4 - x3 + 1) * (y4 - y3 + 1) - c(x3, y3, x4, y4);
		if(max(x1, x3) <= min(x2, x4) && max(y1, y3) <= min(y2, y4))
			s += c(max(x1, x3) ,max(y1, y3),min(x2, x4),min(y2, y4));
		printf("%I64d %I64d\n", n * m - s, s);
	}
}