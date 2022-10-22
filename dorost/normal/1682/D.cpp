/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	int sum = 0;
	string s;
	cin >> s;
	set <pair <int, int>> st;
	set <int> st2;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			sum ++;
		st.insert({1 - (s[i] - '0'), i});
		st2.insert(i);
		s[i] -= '0';
	}
	if (sum % 2 || sum == 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	while ((int)st.size() >= 2) {
		pair <int, int> x = *st.begin();
		assert(x.F == 0);
		st.erase(x);
		st2.erase(x.S);
		auto nxt = st2.lower_bound(x.S);
		auto lst = st2.lower_bound(x.S);
		if (lst == st2.begin()) 
			lst = st2.end();
		lst--;
		if (nxt == st2.end())
			nxt = st2.begin();
		int ls = (*lst);
		int nx = (*nxt);
		if (s[nx] == 1) {
			st.erase({1 - s[ls], ls});
			s[ls] = (1 - s[ls]);
			st.insert({1 - s[ls], ls});
			cout << x.S + 1 << ' ' << ls + 1 << '\n';
		} else {
			st.erase({1 - s[nx], nx});
			s[nx] = (1 - s[nx]);
			st.insert({1 - s[nx], nx});
			cout << x.S + 1 << ' ' << nx + 1 << '\n';
		}
	}
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