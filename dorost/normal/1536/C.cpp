/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 501234;
pair <int, int> ps[N];
int ans[N];

void solve() {
	int n;
	string s;
	cin >> n >> s;
	map <pair <int, int>, int> mp;
	for (int i = 0; i < n; i++) {
		ans[i] = 0;
		if (i == 0) {
			ps[i] = (s[0] == 'K' ? make_pair(1, 0) : make_pair(0, 1));
		} else {
			ps[i] = (s[i] == 'K' ? make_pair(ps[i - 1].F + 1, ps[i - 1].S) : make_pair(ps[i - 1].F, ps[i - 1].S + 1));
		}
	}
	for (int i = 0; i < n; i++) {
		int x = __gcd(ps[i].F, ps[i].S);
		ps[i].F /= x;
		ps[i].S /= x;
	}
	ans[0] = 1;
	mp[ps[0]] = 1;
	cout << 1 << ' ';
	for (int i = 1; i < n; i++) {
		ans[i] = mp[ps[i]] + 1;
		mp[ps[i]]++;
		cout << ans[i] << ' ';
	}
	cout << '\n';
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