#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int a[100005], n;
bool ok(ll k) {
	ll left = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] > k) return false;
		left += k - a[i];
	}
	return left >= k;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll lo = 0, hi = 2000000000;
	while(lo < hi-1) {
		ll mid = (hi+lo)/2;
		// cout << mid << " -> " << ok(mid) << endl;
		if(ok(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << "\n";
	return 0;
}