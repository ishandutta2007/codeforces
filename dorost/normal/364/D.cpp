/* 	* In the name of GOD  */

#pragma GCC optimize("O3")
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1002345;
ll a[N];
int cnt[N], cnt2[N];

int32_t main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll mx = 1;
	int iter = 11;
	for (int wef = 0; wef < iter; wef++) {
		int i = rng() % n;
		vector <ll> v;
		for (int k = 1; (ll)k * (ll)k <= a[i]; k++) {
			if (a[i] % k)
				continue;
			v.push_back(k);
			if (k * k != a[i])
				v.push_back(a[i] / k);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < (int)v.size(); j++)
			cnt[j] = 0, cnt2[j] = 0;
		for (int j = 0; j < n; j++) {
			ll x = __gcd(a[i], a[j]);
			cnt[lower_bound(v.begin(), v.end(), x) - v.begin()]++;
		}
		for (int i = 0; i < (int)v.size(); i++) {
			for (int j = i; j < (int)v.size(); j++) {
				if (v[j] % v[i] == 0) {
					cnt2[i] += cnt[j];
				}
			}
		}
		for (int i = 0; i < (int)v.size(); i++) {
			if (cnt2[i] >= (n + 1) / 2) {
				mx = max(mx, v[i]);
			}
		}
	}
	cout << mx;
}