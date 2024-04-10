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

const int INF = 1e9;
const int mx = 2e5 + 228;
int n, m, a[mx], k[mx], c[mx], more, sum;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; ++i) {
		cin >> k[i];
		sum += k[i];
		if (k[i] == 0)
			more++;
	}
	int ans = INF, r = -1;
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			int color = a[i - 1];
			if (c[color] == k[color])
				more--;
			c[color]--;
		}
		while (r < n - 1 && more < m) {
			int color = a[r + 1];
			if (c[color] == k[color] - 1)
				more++;
			c[color]++;
			r++;
		}
		if (more == m) {
			/*cout << "i = " << i << endl;
			cout << "r = " << r << endl;
			cout << "c" << endl;
			for (int i = 0; i < m; ++i) {
				cout << c[i] << " ";
			}
			cout << endl;*/
			int d = (r - i + 1);
			ans = min(ans, d - sum);
		}
	}
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
}