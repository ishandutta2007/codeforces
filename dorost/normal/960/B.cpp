/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N], b[N], mp[N * N * 2];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k1, k2, k;
	cin >> n >> k1 >> k2;
	k = k1 + k2;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set <int> st;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		a[i] = abs(b[i] - a[i]);
		st.insert(a[i]);
		mp[a[i]]++;
	}
	while(k) {
		int x = *st.rbegin();
		if (x == 0) {
			k--;
			mp[0]--;
			if (mp[0] == 0)
				st.erase(0);
			mp[1]++;
			st.insert(1);
		} else {
			k--;
			mp[x]--;
			if (mp[x] == 0)
				st.erase(x);
			mp[x - 1]++;
			st.insert(x - 1);
		}
	}
	ll ans = 0;
	for (auto x : st) {
		ans += ((ll)x * (ll)x) * mp[x];
	}
	cout << ans;
}