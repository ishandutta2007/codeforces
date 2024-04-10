/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int p[N];

int ask(int x) {
	cout << "? " << x << endl;
	int y;
	cin >> y;
	return y;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		p[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] != 0)
			continue;
		int x = ask(i);
		int y = x;
		while (true) {
			int a = ask(i);
			p[x] = a;
			if (a == y) {
				break;
			}
			x = a;
		}
	}
	cout << "!";
	for (int i = 1; i <= n; i++) {
		cout << ' ' << p[i];
	}
	cout << endl;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}