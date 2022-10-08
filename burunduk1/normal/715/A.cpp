/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	ll x = 2;
	for (ll k = 1; k <= n; k++) {
		ll t = x / k;
		cout << k * (k + 1) * (k + 1) - t << "\n";
		x = k * (k + 1);
	}
}