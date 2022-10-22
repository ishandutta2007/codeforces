/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int a, b, c, d, x;
	cin >> a >> b >> c >> d;
	x = a + b + c + d;
	bool f = (abs((a + c) - (b + d)) <= 1 && (a <= b + 1) && b <= (a + c + 1) && c <= (b + d + 1) && d <= (c + 1));
	deque <int> v;
	if (f) {
		int a1 = a, b1 = b, c1 = c, d1 = d;
		int a2 = a, b2 = b, c2 = c, d2 = d;
		for (int i = 0; i < min(a1, b1); i++) {
			v.push_back(0);
			v.push_back(1);
			a--;
			b--;
		}
		if (c2 + d2 == 0 && a2 > b2) {
			v.push_back(0);
			a--;
		}
		a1 = a, b1 = b, c1 = c, d1 = d;
		for (int i = 0; i < min(b1, c1 - 1); i++) {
			v.push_back(2);
			v.push_back(1);
			b--;
			c--;
		}
		if (c && !((a1 + a2 == 0) && d2 > c2)) {
			c--;
			v.push_back(2);
		}
		a1 = a, b1 = b, c1 = c, d1 = d;
		if (b) {
			b--;
			v.push_front(1);
		}
		a1 = a, b1 = b, c1 = c, d1 = d;
		for (int i = 0; i < min(c1, d1); i++) {
			v.push_back(3);
			v.push_back(2);
			c--;
			d--;
		}
		a1 = a, b1 = b, c1 = c, d1 = d;
		if (d && c2) 
			v.push_back(3);
		if (v.size() != x) {
			v = {};
			a = a2, b = b2, c = c2, d = d2;
			int a1 = a, b1 = b, c1 = c, d1 = d;
			for (int i = 0; i < min(a1, b1); i++) {
				v.push_back(0);
				v.push_back(1);
				a--;
				b--;
			}
			if (b) {
				b--;
				v.push_front(1);
			}
			a1 = a, b1 = b, c1 = c, d1 = d;
			for (int i = 0; i < (d2 == 0 ? min(b1, c1) : min(b1, c1 - 1)); i++) {
				v.push_back(2);
				v.push_back(1);
				b--;
				c--;
			}
			if (c) {
				c--;
				v.push_back(2);
			}
			a1 = a, b1 = b, c1 = c, d1 = d;
			a1 = a, b1 = b, c1 = c, d1 = d;
			for (int i = 0; i < min(c1, d1); i++) {
				v.push_back(3);
				v.push_back(2);
				c--;
				d--;
			}
			a1 = a, b1 = b, c1 = c, d1 = d;
			if (d && c2 || (a2 + b2 == 0)) 
				v.push_back(3);
			if (v.size() != x)
				f = false;
		}
	}
	if (f) {
		cout << "YES\n";
		for (int i = 0; i < x; i++)
			cout << v[i] << ' ';
	} else {
		cout << "NO\n";
	}
}