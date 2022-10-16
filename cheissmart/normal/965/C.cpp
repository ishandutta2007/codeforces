#include <iostream>
#define ll long long

using namespace std;

ll n, k, m, d;

long long p(long long x) {
	return (n / x + k - 1) / k;
}

int main()
{
	cin >> n >> k >> m >> d;
	ll ans = 0;
	for (ll v = 1; v <= d; v++) {
		ll l = 1, r = m, mid;
		while(l <= r) {
			mid = (l + r) / 2;
	//	cerr << l << ' ' << r << ' '<< mid << ':' << p(mid) << endl;
			if (p(mid) < v) r = mid - 1;
			else l = mid + 1;
		}
		if (r > 0 && p(r) == v)
			ans = max(ans, v * r);
	}
	cout << ans << endl;
}