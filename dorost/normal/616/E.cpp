/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 3162534, M = 1000 * 1000 * 1000 + 7;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, ans = 0;
	cin >> n >> m;
	if (m > n) {
		int wef = (m - n);
		wef %= M;
		wef += M;
		wef %= M;
		wef *= (n % M);
		wef %= M;
		m = n;
		ans = wef;
	}
	int mnr;
	for (int i = 1; i <= N; i++) {
		int r = n / i;
		int l = n / (i + 1) + 1;
		mnr = l - 1;
		r = min(r, m);
		l = max(l, 1LL);
		if (l > r) 
			continue;
		int sz = (r - l) + 1;
		sz %= M;
		int x = (n % M) * sz;
		x %= M;
		int nr = r % M, nr2 = (r + 1 + M) % M;
		int nl = l % M, nl2 = (l - 1 + M) % M;
		int rwef = (nr * (nr2));
		rwef %= M;
		int lwef = (nl * (nl2));
		lwef %= M;
		int c = rwef * 500000004;
		c %= M;
		c -= lwef * 500000004;
		c %= M;
		c += M;
		c %= M;
		c *= i;
		c %= M;
		x -= c;
		x %= M;
		x += M;
		x %= M;
		ans += x;
		ans %= M;
	}
	int mnl = 1;
	mnr = min(mnr, m);
	for (int i = mnl; i <= mnr; i++) {
		ans += (n % i);
		ans %= M;
	}
	cout << ans << endl;
}