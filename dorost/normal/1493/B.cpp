/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int r, o;

int rev(int x) {
	if (x == 0 || x == 1 || x == 8)
		return x;
	if (x == 2)
		return 5;
	if (x == 5)
		return 2;
}

bool f(int x) {
	if (x == 3 || x == 4 || x == 6 || x == 7 || x == 9) {
		return false;
	} else {
		return true;
	}
}


bool c(int x, int y) {
	int b = x % 10, a = x / 10, d = y % 10, c = y / 10;
	if (!f(a) || !f(b) || !f(c) || !f(d))
		return false;
	int h = rev(d), j = rev(c), k = rev(b), l = rev(a);
	if (h * 10 + j < r && k * 10 + l < o) {
		return true;
	} else
		return false;
}

void solve() {
	int h, w;
	string s;
	cin >> h >> w >> s;
	r = h;
	o = w;
	string a;
	a += s[0];
	a += s[1];
	string b;
	b += s[3];
	b += s[4];
	int x = stoi(a), y = stoi(b);
	for (int i = 0; i < 10005; i++) {
		if (c(x, y)) {
			if (x < 10)
				cout << '0';
			cout << x << ':';
			if (y < 10)
				cout << '0';
			cout << y << '\n';
			return;
		}
		y++;
		if (y == w) {
			y = 0;
			x++;
		}
		if (x == h) {
			x = 0;
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}