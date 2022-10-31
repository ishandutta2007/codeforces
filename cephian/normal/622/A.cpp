#include <iostream>

using namespace std;

typedef long long ll;

ll n;

ll s(ll a) {
	return (a*(a-1))/2;
}

ll find(ll k) {
	--k;
	ll lo = 0;
	ll hi = 1000000000;
	while(lo < hi-1) {
		ll mid = (lo+hi)/2;
		if(s(mid) <= k) lo = mid;
		else hi = mid;
	}
	return k-s(lo)+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	cout << find(n) << endl;

	return 0;
}