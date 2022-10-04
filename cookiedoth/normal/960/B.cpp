/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL
#define int long long

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 5000;
int n, k1, k2, a[mx], b[mx], c[mx];

signed main() {
	cin >> n >> k1 >> k2;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		c[i] = abs(a[i] - b[i]);
	}
	int k = k1 + k2;
	for (int i = 0; i < k; ++i) {
		int pos_max = 0;
		for (int j = 1; j < n; ++j) {
			if (c[j] > c[pos_max])
				pos_max = j;
		}
		if (c[pos_max] == 0)
			c[pos_max] = 1;
		else
			c[pos_max]--;
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += (c[i] * c[i]);
	}
	cout << res << endl;
}