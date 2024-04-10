/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 502;
string st[2 * N], pt[2 * N], a[N][N];

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = "";
		}
	}
	for (int i = 0; i < t.size(); i++) {
		st[i] = pt[i] = "";
	}
	for (int i = 0; i < n; i++) {
		string sa = "";
		for (int j = i; j < n; j++) {
			sa += s[j];
			a[i][j] = sa;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		string sa = "";
		for (int j = i; j >= 0; j--) {
			sa += s[j];
			a[i][j] = sa;
		}
	}
	pt[0] = "";
	pt[0] += t[0];
	for (int i = 1; i < t.size(); i++) {
		pt[i] = pt[i - 1] + t[i];
	}
	st[(int)t.size() - 1] = "";
	st[(int)t.size() - 1] += t[(int)t.size() - 1];
	for (int i = (int)t.size() - 2; i >= 0; i--) {
		st[i] = t[i] + st[i + 1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sz = j - i;
			if (sz >= t.size())
				continue;
			if(a[i][j] == t) {
				cout << "YES ";
				return;
			}
			if (a[i][j] == pt[sz]) {
				sz++;
				if (j - ((int)t.size() - sz) >= 0) {
//					cout << j - 1 << ' ' << j - ((int)t.size() - sz) << endl;
//					cout << sz << endl;
//					cout << i << ' ' << j << ' ' << st[(int)sz] << ' ' << a[j - 1][j - ((int)t.size() - sz)] << endl;
					if (a[j - 1][j - ((int)t.size() - sz)] == st[(int)sz]) {
						cout << "YES ";
						return;
					}
				}
			}
		}
	}
	cout << "NO ";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}