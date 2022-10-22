/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int k[N], h[N];

void solve() {
	int n;
	cin >> n;
	vector <pair <int, int>> w;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		w.push_back(make_pair(k[i] - h[i] + 1, 1));
		w.push_back(make_pair(k[i] + 1, -1));
	}
	sort(w.begin(), w.end());
	ll ans = 0, x = 0, t = 0;
	int j = 0;
	for (int i = 0; i < (int)w.size() - 1; i++) {
		if (i != (int)w.size() - 1 && w[i].F == w[i + 1].F) {
			t += w[i].S;
			if (t <= 0)
				x = 0;
			continue;
		}
		t += w[i].S;
		if (t <= 0)
			x = 0;
		if (t >= 1) {
			ll d = w[i + 1].F - w[i].F;
			ans += x * d + ((d) * (d + 1) / 2);
			x += d;
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}