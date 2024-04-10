#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get(ll limit) {
	ll rad = sqrt((long double) limit);
	return (rad * (rad + 1) <= limit) + (rad * (rad + 2) <= limit) + 3 * rad - 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << get(r) - get(l - 1) << "\n";
	}
  return 0;
}