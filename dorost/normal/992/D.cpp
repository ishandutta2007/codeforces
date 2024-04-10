/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, K = 130;
const ll INF = LLONG_MAX / 2;
vector <int> a;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			if (a.empty() || a.back() >= 0)
				a.push_back(-1);
			else {
				a.back()--;
			}
		} else {
			a.push_back(x);
		}
	}
	n = a.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0)
			continue;
		ll p = 1, s = 0;
		for (int j = i; j < min(n, i + K); j++) {
			if (a[j] > 0) {
				s += a[j];
				if (p >= INF / a[j]) {
					break;
				}
				p *= a[j];
				if (p == s * k) {
					ans++;
				}
			} else {
				int x = -a[j];
				if (p % k == 0) {
					if (p / k > s && p / k <= s + x) {
						ans++;
					}
				}
				s += x;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0)
			continue;
		int x = -a[i];
		for (int l = 0; l < x; l++) {
			a[i] = l - x;
			ll p = 1, s = 0;
			for (int j = i; j < min(n, i + K); j++) {
				if (a[j] > 0) {
					s += a[j];
					if (p >= INF / a[j]) {
						break;
					}
					p *= a[j];
					if (p == s * k) {
						ans++;
					}
				} else {
					int x = -a[j];
					if (p % k == 0) {
						if (p / k > s && p / k <= s + x) {
							ans++;
						}
					}
					s += x;
				}
			}
			a[i] = -x;
		}
	}
	cout << ans;
}