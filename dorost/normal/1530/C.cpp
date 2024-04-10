/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	int xx = n - n / 4;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	reverse(a, a + n);
	reverse(b, b + n);
	int x = 0, y = 0;
	for (int i = 0; i < xx; i++) {
		x += a[i];
		y += b[i];
	}
	map <int, int> mp;
	set <int> st;
	for (int i = 0; i < xx; i++) {
		mp[a[i]]++;
		st.insert(a[i]);
	}
	map <int, int> m;
	set <int> s;
	for(int i = xx; i < n; i++) {
		m[b[i]]++;
		s.insert(b[i]);
	}
	int an = n;
	int ans = 0;
	while (y > x) {
		an++;
		if (an % 4 == 0) {
			int x1 = *st.begin();
			mp[x1]--;
			if (mp[x1] == 0) {
				st.erase(x1);
			}
			mp[100]++;
			st.insert(100);
			x -= x1;
			x += 100;
		} else {
			mp[100]++;
			st.insert(100);
			x += 100;
			if (s.size() != 0) {
				int x1 = *s.rbegin();
				m[x1]--;
				if (m[x1] == 0)
					s.erase(x1);
				y += x1;
			}
		}
		ans++;
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