#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int n;
ll l, r, q1, q2;
const int N = 100005;
ll a[N];
ll l_sum[N], r_sum[N];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> l >> r >> q1 >> q2;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		l_sum[i] = r_sum[i] = a[i];
	}
	for(int i = 1; i < n; ++i) {
		l_sum[i] += l_sum[i-1];
		r_sum[n-i-1] += r_sum[n-i];
	}
	ll ans = (1LL << 50);
	for(int c = 0; c <= n; ++c) {
		ll tans = 0;
		if(c > 0) tans += l_sum[c-1]*l;
		if(c < n) tans += r_sum[c]*r;
		if(c > n-c) {
			tans += q1*max(2*c-n-1,0);
		} else {
			tans += q2*max(n-2*c-1,0);
		}
		ans = min(ans,tans);
	}
	cout << ans << "\n";
	return 0;
}