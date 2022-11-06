/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

ll sqr( ll x ) { return x * x; }

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	ll r, d, n, x, y, s, cnt = 0;
	cin >> r >> d >> n;
	while (n--) {
		cin >> x >> y >> s;
		cnt += (s <= r) && (x * x + y * y <= sqr(r - s)) && (x * x + y * y >= sqr(r - d + s));
	}
	cout << cnt << endl;
}