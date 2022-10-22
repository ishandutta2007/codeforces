/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
vector <int> v;

void solve() {
	int l, r;
	cin >> l >> r;
	cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << ' ';
}

int32_t main() {
	v.push_back(1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL);
	for (int i = 0; i < 18; i++) {
		string s = "000000000000000000";
		for (int a = 1; a < 10; a++) {
			s[i] = a + '0';
			v.push_back(stoll(s));
		}
	}
	for (int i = 0; i < 18; i++) {
		for (int j = i + 1; j < 18; j++) {
			string s = "000000000000000000";
			for (int a = 1; a < 10; a++) {
				for (int b = 1; b < 10; b++) {
					s[i] = a + '0';
					s[j] = b + '0';
					v.push_back(stoll(s));
				}
			}
		}
	}
	for (int i = 0; i < 18; i++) {
		for (int j = i + 1; j < 18; j++) {
			for (int k = j + 1; k < 18; k++) {
				string s = "000000000000000000";
				for (int a = 1; a < 10; a++) {
					for (int b = 1; b < 10; b++) {
						for (int c = 1; c < 10; c++) {
							s[i] = a + '0';
							s[j] = b + '0';
							s[k] = c + '0';
							v.push_back(stoll(s));
						}
					}
				}
			}
		}
	}
	sort(v.begin(), v.end());
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}