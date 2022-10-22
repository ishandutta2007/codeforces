/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 202;
string s[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	vector <pair <int, int>> v = {{n - 1, n - 2}, {n - 2, n - 1}}, v2 = {{n - 2, n - 2}, {n - 1, n - 3}, {n - 3, n - 1}};
	if ((s[v[0].F][v[0].S] == '0') + (s[v[1].F][v[1].S] == '0') + (s[v2[0].F][v2[0].S] == '1') + (s[v2[1].F][v2[1].S] == '1') + (s[v2[2].F][v2[2].S] == '1') <= 2) {
		cout << (s[v[0].F][v[0].S] == '0') + (s[v[1].F][v[1].S] == '0') + (s[v2[0].F][v2[0].S] == '1') + (s[v2[1].F][v2[1].S] == '1') + (s[v2[2].F][v2[2].S] == '1') << '\n';
		if (s[v[0].F][v[0].S] == '0') 
			cout << v[0].F + 1 << ' ' << v[0].S + 1 << '\n';
		if (s[v[1].F][v[1].S] == '0')
			cout << v[1].F + 1 << ' ' << v[1].S + 1 << '\n';
		if (s[v2[0].F][v2[0].S] == '1')
			cout << v2[0].F + 1 << ' ' << v2[0].S + 1 << '\n';
		if (s[v2[1].F][v2[1].S] == '1')
			cout << v2[1].F + 1 << ' ' << v2[1].S + 1 << '\n';
		if (s[v2[2].F][v2[2].S] == '1')
			cout << v2[2].F + 1 << ' ' << v2[2].S + 1 << '\n';
	} else {
		cout << (s[v[0].F][v[0].S] == '1') + (s[v[1].F][v[1].S] == '1') + (s[v2[0].F][v2[0].S] == '0') + (s[v2[1].F][v2[1].S] == '0') + (s[v2[2].F][v2[2].S] == '0') << '\n';
		if (s[v[0].F][v[0].S] == '1') 
			cout << v[0].F + 1 << ' ' << v[0].S + 1 << '\n';
		if (s[v[1].F][v[1].S] == '1')
			cout << v[1].F + 1 << ' ' << v[1].S + 1 << '\n';
		if (s[v2[0].F][v2[0].S] == '0')
			cout << v2[0].F + 1 << ' ' << v2[0].S + 1 << '\n';
		if (s[v2[1].F][v2[1].S] == '0')
			cout << v2[1].F + 1 << ' ' << v2[1].S + 1 << '\n';
		if (s[v2[2].F][v2[2].S] == '0')
			cout << v2[2].F + 1 << ' ' << v2[2].S + 1 << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}