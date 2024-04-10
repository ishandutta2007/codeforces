/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 51;
int a[N];
bool f[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[i] = true;
	}
	for (int i = n; i >= 1; i--) {
		bool h = false;
		for (int j = 0; j < n; j++) {
			if (f[j]) {
				int x = a[j];
				while (x > i)
					x /= 2;
				if (x == i) {
					f[j] = false;
					h = true;
					break;
				}
			}
		}
		if (!h) {
			cout << "NO ";
			return;
		}
	}
	cout << "YES ";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}