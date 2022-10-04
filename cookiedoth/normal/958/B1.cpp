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

const int mx = 5e3;
int n, deg[mx];

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		deg[u]++;
		deg[v]++;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (deg[i] == 1) {
			ans++;
		}
	}
	cout << ans << endl;
}