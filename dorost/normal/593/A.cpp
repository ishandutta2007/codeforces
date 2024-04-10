/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
string s[N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int mx = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < i; j++) {
			int a = 0;
			for (int k = 0; k < n; k++) {
				bool f = true;
				for (int l = 0; l < s[k].size(); l++) {
					if (s[k][l] != ('a' + i) && s[k][l] != ('a' + j)) {
						f = false;
					}
				}
				a += (f ? s[k].size() : 0);
			}
			mx = max(mx, a);
		}
	}
	cout << mx;
}