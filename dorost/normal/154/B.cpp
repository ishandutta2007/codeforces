/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
bool on[N];
set <int> st[N];

int32_t main() {
	int n, q;
	cin >> n >> q;
	while (q--) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '+') {
			if (on[x]) {
				cout << "Already on\n";
			} else {
				vector <int> v;
				for (int i = 2; i * i <= x; i++) {
					if (x % i == 0)
						v.push_back(i);
					if (i * i != x && x % i == 0) {
						v.push_back(x / i);
					}
				}
				v.push_back(x);
				bool f = true;
				for (auto xx : v) {
					if (!st[xx].empty()) {
						f = false;
						cout << "Conflict with " << *st[xx].begin() << '\n';
						break;
					}
				}
				if (f) {
					for (auto xx : v) {
						st[xx].insert(x);
					}
					on[x] = true;
					cout << "Success\n";
				}
			}
		} else {
			if (on[x] == false) {
				cout << "Already off\n";
			} else {
				vector <int> v;
				for (int i = 2; i * i <= x; i++) {
					if (x % i == 0)
						v.push_back(i);
					if (i * i != x && x % i == 0) {
						v.push_back(x / i);
					}
				}
				v.push_back(x);
				for (auto xx : v) {
					st[xx].erase(x);
				}
				on[x] = false;
				cout << "Success\n";
			}
		}
	}
}