/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	int n;
	string s;
	cin >> n >> s;
	set <pair <int, int>> st;
	for (int i = 0; i < n; i++) {
		int x = i;
		st.insert({x, x});
		i++;
		while (i < n && s[i] != s[x]) {
			st.insert({x, i});
			i++;
		}
		i = x;
	}
	for (int i = n - 1; i >= 0; i--) {
		int x = i;
		st.insert({x, x});
		i--;
		while (i >= 0 && s[i] != s[x]) {
			st.insert({i, x});
			i--;
		}
		i = x;
	}
	/* for (auto [x, y] : st) {
		cout << x << ' ' << y << '\n';
	} */
	cout << (n * (n + 1) / 2) - (int)st.size();
}