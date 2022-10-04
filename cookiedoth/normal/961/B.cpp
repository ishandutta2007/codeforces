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

const int mx = 3e5;
int n, k;
ll a[mx], p[mx], pref[mx];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i - 1] * (1 - p[i - 1]);
	}
	ll ans = 0;
	for (int i = k; i <= n; ++i) {
		ans = max(ans, pref[i] - pref[i - k]);
	}
	for (int i = 0; i < n; ++i) {
		if (p[i] == 1)
			ans += a[i];
	}
	cout << ans << endl;
}