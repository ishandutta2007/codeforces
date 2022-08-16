#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main()
{
	fast_cin();
	ll r; cin >> r;
	for (ll x = 1; x <= r; ++x) {
		ll temp = r - x * x - x - 1;
		if (temp <= 0) {
			break;
		} else if (temp % (2 * x) == 0) {
			cout << x << ' ' << temp / (2 * x) << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}