// Problem: C. Strange Function
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.ml/contest/1542/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
const int mod = 1e9 + 7;
signed main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int tmp = 1;
		int ans = 0;
		for (int i = 2; tmp <= n; i++) {
			//tmp*k % i !=0
			int aa = __gcd(tmp, i);
			int x = tmp / aa, y = i / aa;
			//x*k % y!=0
			ans += ((n/aa / x) - (n/aa / x / y)) % mod * i % mod;
			ans %= mod;
			//printf("%d %d\n",i,((n / x) - (n / x / y)) % mod * i % mod);
			tmp *= i / __gcd(i, tmp);
		}
		cout << ans << endl;
	}
}