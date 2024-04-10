/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int gcd = 0;
	int lst = 0;
	for (int i = 0; i < n; i++) {
		gcd = __gcd(gcd, a[i]);
		if (gcd == i - lst + 1) {
			lst = i + 1;
			gcd = 0;
			a[i] = 0;
		} else if (gcd < i - lst + 1) {
			int g2 = 0;
			int lst2 = lst;
			for (int j = i; j >= lst2 + 1; j--) {
				g2 = __gcd(g2, a[j]);
				if (g2 == i - j + 1) {
					gcd = 0;
					lst = i + 1;
					a[i] = 0;
					break;
				} else if (g2 < i - j + 1) {
					break;
				} else {
					gcd = g2;
					lst = j;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[i] == 0);
		cout << ans << ' ';
	}
}