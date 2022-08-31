#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

int ctr[N];

int main()
{
	fast_cin();
	int n; cin >> n;
	string y; cin >> y;
	for (int i = 0; i < n; ++i) {
		++ctr[__gcd(n, i)];
	}
	int ans = 0;
	for (int d = 1; d <= n; ++d) {
		if (n % d == 0) {
			bool ok = true;
			for (int i = 0; i < d; ++i) {
				int parity = 0, p = i;
				while (true) {
					parity ^= (y[p]-'0');
					p = (p + d) % n;
					if (p == i) {
						break;
					}
				}
				if (parity) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans += ctr[d];
			}
		}
	}
	cout << ans << endl;
}