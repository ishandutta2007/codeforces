/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int k[4] = {2, 3, 4, 7};
	for (int i = 0; i < 4; i++) {
		int kk = k[i];
		for (int j = 0; j <= n - kk; j++) {
			int a = 0, b = 0, c = 0;
			for (int l = j; l < j + kk; l++) {
				if (s[l] == 'a')
					a++;
				else if (s[l] == 'b')
					b++;
				else
					c++;
			}
			if (a > b && a > c) {
				cout << kk << ' ';
				return;
			}
		}
	}
	cout << -1 << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}