/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
map <int, int> mp;

int solve(int x, int n) {
	if (x >= n)
		return 0;
	if (mp[x] != 0)
		return mp[x];
	set <int> st;
	for (char c : to_string(x)) {
		st.insert(c - '0');
	}
	st.erase(0);
	st.erase(1);
	int mn = 100;
	for (int i : st)
		mn = min(mn, solve(x * i, n) + 1);
	return mp[x] = mn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, x;
	cin >> n >> x;
	n = pow(10, n - 1);
	int ans = solve(x, n);
	cout << (ans == 100 ? -1 : ans) << '\n';
}