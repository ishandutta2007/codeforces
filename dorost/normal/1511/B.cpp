/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = 1, aa = 1, bb = 1;
	for (int i = 0; i < c - 1; i++) 
		x *= 10;
	for (int i = 0; i < a - 1; i++) 
		aa *= 10;
	for (int i = 0; i < b - 1; i++) 
		bb *= 10;
	int y = 1;
	while (y < x) {
		y *= 2;
	}
	int ax = y, bx = y;
	while (ax < aa) {
		ax *= 3;
	}
	while (bx < bb) {
		bx *= 5;
	}
	cout << ax << ' ' << bx << '\n';
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