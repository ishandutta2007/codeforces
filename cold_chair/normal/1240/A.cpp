#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int T, n;
ll p[N], s[N];
ll x, a, y, b, k, c;

int gcd(int x, int y) { return !y ? x : gcd(y, x % y);}

int pd(int m) {
	int t1 = m / c, t2 = m / a - t1, t3 = m / b - t1;
	ll ans = 0;
	ans = s[t1] * (x + y);
	ans += (s[t1 + t2] - s[t1]) * x;
	ans += (s[t1 + t2 + t3] - s[t1 + t2]) * y;
	return ans >= k;
}

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) scanf("%I64d", &p[i]);
		sort(p + 1, p + n + 1);
		reverse(p + 1, p + n + 1);
		fo(i, 1, n) s[i] = s[i - 1] + p[i] / 100;
		scanf("%I64d %I64d %I64d %I64d %I64d", &x, &a, &y, &b, &k);
		c = a * b / gcd(a, b);
		if(x < y) swap(x, y), swap(a, b);
		int as = -1;
		for(int l = 1, r = n; l <= r; ) {
			int m = l + r >> 1;
			if(pd(m)) as = m, r = m - 1; else l = m + 1;
		}
		pp("%d\n", as);
	}
}