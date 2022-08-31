/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	ll n, a, r, m;
	cin >> n >> a >> r >> m;
	m = min(m, a + r);
	ll sum = 0;
	vector<ll> h(n);
	for (auto& i : h) {
		cin >> i;
		sum += i;
	}
	sort(h.begin(), h.end());
	ll ans = sum * r, suff = 0;
	ll avg_lo = sum / n, avg_hi = avg_lo + 1;
	for (int i = n - 2; i >= 0; --i) {
		suff += h[i + 1];
		ll lo = h[i], hi = h[i + 1];
		ll ext = suff - hi * (n - i - 1);
		if (lo <= avg_lo) {
			ll base = sum * (r - m) + ext * m + hi * (n - i - 1) * m;
			ll coeff = n * (m - r) - (n - i - 1) * m;
			ans = min(ans, base + lo * coeff);
			ans = min(ans, base + min(hi, avg_lo) * coeff);
		}
		if (hi >= avg_hi) {
			ll base = sum * (-a) + ext * m + hi * (n - i - 1) * m;
			ll coeff = n * a - (n - i - 1) * m;
			ans = min(ans, base + hi * coeff);
			ans = min(ans, base + max(avg_hi, lo) * coeff);
		}
	}
	cout << ans << '\n';
}