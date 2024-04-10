#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second
#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0, f = 1;
		while (n) {
			int x;
			if (f == 0) {
				if (n % 4 == 0 && n != 4) {
					x = 1;
					n -= x;
				}else if (n % 2) {
					x = 1;
					n--;
				} else {
					x = n / 2;
					n -= x;
				}
			} else {
				if (n % 4 == 0 && n != 4) {
					x = 1;
					n -= x;
				}else if (n % 2) {
					x = 1;
					n--;
				} else {
					x = n / 2;
					n -= x;
				}
			}
			if (f) {
				ans += x;
//				cout << 'f' << x << ' ' << n << '\n';
			} else {
//				cout << 's' << x << ' ' << n << '\n';
			}
			f = 1 - f;
		}
		cout << ans << '\n';
	}
}