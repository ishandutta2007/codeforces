/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
int a[N];
int l[N], r[N];
vector <pair <int, int>> v[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = -1, l[i] = 0, r[i] = 0, v[i].clear();
	set <pair <int, int>> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			l[i] = i + 1;
			r[i] = n;
		} else {
			l[i] = i / (x + 1) + 1;
			r[i] = i / x;
		}
		v[l[i]].push_back(make_pair(r[i], i));
	}
	for (int i = 1; i <= n; i++) {
		for (pair <int, int> p : v[i])
			st.insert(p);
		pair <int, int> p = (*st.begin());
		a[p.S] = i;
		st.erase(p);
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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