/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 1000 * 10001;
int a[N], c[M];
vector <int> divs[M];
bool f[M];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = c[a[i]];
	}
	set <int> st;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (st.count(a[i])) {
			ans++;
			st.clear();
		}
		st.insert(a[i]);
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i < M; i++) {
		c[i] = i;
	}
	for (int i = 2; i < M; i++) {
		if (f[i])
			continue;
		for (int j = i; j < M; j += i) {
			f[j] = true;
			int x = c[j], y = 0;
			while (x % i == 0) {
				x /= i;
				y++;
			}
			if (y % 2)
				x *= i;
			c[j] = x;
		}
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}