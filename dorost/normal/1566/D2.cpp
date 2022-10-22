/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 302;
pair <int, int> a[N * N];
int b[N * N];

bool cmp(pair <int, int> a, pair <int, int> b) {
	if (a.F < b.F)
		return true;
	if (a.F > b.F)
		return false;
	return a.S > b.S;
}

void solve() {
	set <pair <int, int>> st;
	int n, m;
	cin >> n >> m;
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i * m + j].F;
			a[i * m + j].S = (i * m + j);
		}
	}
	sort(a, a + n * m);
	for (int i = 0; i < n; i++) {
		st.clear();
		for (int j = 0; j < m; j++) {
			int ii = i * m + j;
//			cout << a[ii].S << ' ';
			auto aa = st.lower_bound({a[ii].S, N * N});
			while (aa != st.begin()) {
				aa--;
				if ((*aa).S == a[ii].F)
					continue;
				x++;
			}
//			cout << x << ' ';
			st.insert({a[ii].S, a[ii].F});
		}
//		cout << '\n';
	}
	cout << x << ' '; 
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}