/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
	ll n, h, l, r, m;
	cin >> n >> h;
	if (h > 2e9 || h * (h + 1) >= 2 * n) {
		l = 0, r = min((ll)2e9, h);
		while (r - l > 1) {
			m = (l + r) / 2;
			if (m * (m + 1) >= 2 * n)
				r = m;
			else
				l = m;
		}
		cout << r << endl;
	} else {
		l = h, r = 3e9;
		while (r - l > 1) {
			m = (l + r) / 2;
			ll x, p = (h - 1) + (m - (h - 1) + 1) / 2;
			if ((m - (h - 1)) & 1) {
				x = p * (p + 1) + p * (p - 1) - h * (h - 1);
			} else {
				x = p * (p + 1) + p * (p + 1) - h * (h - 1);
			}
			// printf("%lld --> p = %lld, x = %lld, odd = %lld\n", m, p, x, (m - (h - 1)) & 1);
			if (x >= 2 * n)
				r = m;
			else
				l = m;
		}
		cout << r << endl;
	}
}