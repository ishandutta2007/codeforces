/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, SQ = 2000;
bool is_prime[N * 5];
int a[N * 2], cnt[N * 2][2];

void solve() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < n * 2; i++) {
		a[i] = 0;
		cnt[i][0] = 0;
		cnt[i][1] = 0;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < e; i++) {
		vector <pair <int, int>> v;
		int s = -1;
		for (int j = i; j < n + e; j += e) {
			cnt[j][0] = 1;
			cnt[j][1] = 1;
		}
		for (int j = i; j < n + e; j += e) {
			if ((j >= n || a[j] != 1) && s != -1) {
				cnt[j - e][1] = (j - s) / e + 1;
				cnt[s][0] = (j - s) / e + 1;
				s = -1;
			} else if (s == -1 && a[j] == 1) {
				s = j;
			}
		}
		for (int j = i; j < n; j += e) {
			if (is_prime[a[j]]) {
				ll x = 1;
				if (j >= e) {
					x *= cnt[j - e][1];
				}
				if (j + e < n) {
					x *= cnt[j + e][0];
				}
				ans += x - 1;
			}
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 0; i < N * 5; i++)
		is_prime[i] = true;
	is_prime[1] = false;
	for (int i = 2; i < SQ; i++) {
		if (is_prime[i] == false)
			continue;
		for (int j = i * i; j < N * 5; j += i) {
			is_prime[j] = false;
		}
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}