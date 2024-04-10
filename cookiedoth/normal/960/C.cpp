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

const ll INF = 2e9;
ll x, d, kek = 1;
const ll lg = 40;
vector<ll> c, ans;

signed main() {
	cin >> x >> d;
	for (ll i = 0; i < lg; ++i) {
		c.push_back((1LL << i) - 1);
	}
	for (int i = c.size() - 1; i >= 1; --i) {
		while (x >= c[i]) {
			for (int j = 0; j < i; ++j) {
				ans.push_back(kek);
			}
			kek += INF;
			x -= c[i];

		}
	}
	int n = ans.size();
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}