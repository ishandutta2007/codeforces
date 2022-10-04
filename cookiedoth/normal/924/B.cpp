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

const int mx = 2e5;
int n, e[mx], u;

int main() {
	double ans = -1;
	cin >> n >> u;
	for (int i = 0; i < n; ++i) {
		cin >> e[i];
	}
	int k = 0;
	for (int i = 0; i < n; ++i) {
		while (k < n - 1 && e[k + 1] - e[i] <= u) {
			k++;
		}
		if (k - i >= 2) {
			int j = i + 1;
			ans = max(ans, (double)(e[k] - e[j]) / (double)(e[k] - e[i]));
		}
	}
	if (ans < 0)
		cout << -1 << endl;
	else
		cout << setprecision(20) << ans << endl;
}