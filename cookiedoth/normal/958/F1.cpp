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

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 300;
int n, m, a[mx], k[mx], c[mx];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; ++i) {
		cin >> k[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int x = 0; x < m; ++x) {
				c[x] = 0;
			}
			for (int x = i; x <= j; ++x) {
				c[a[x]]++;
			}
			int kek = 1;
			for (int x = 0; x < m; ++x) {
				if (c[x] != k[x])
					kek = 0;
			}
			if (kek == 1)
				ans = 1;
		}
	}
	if (ans == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}