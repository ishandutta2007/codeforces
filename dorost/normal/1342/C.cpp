#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int a, b, q;
		cin >> a >> b >> q;
		int n = max(a, b), m = a * b / __gcd(a, b);
		while (q--){
			int l, r;
			cin >> l >> r;
			int ans = 0;
			l--;
			ans += ((r) / m - 1) * n;
			ans += min(n, r % m + 1);
			ans -= ((l) / m - 1) * n;
			ans -= min(n, l % m + 1);
			cout << (r - l) - ans << ' ';
		}
		cout << endl;
	}
}