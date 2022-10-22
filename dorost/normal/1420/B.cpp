/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, L = 32;
int a[N], cnt[L];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < L; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		vector <int> b;
		int x = a[i];
		while (x) {
			b.push_back(x % 2);
			x /= 2;
		}
		for (int j = b.size() - 1; j < b.size(); j++) {
			if (b[j]) {
				cnt[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < L; i++) {
		ans += (cnt[i] * (cnt[i] - 1) / 2);
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}