/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000001;
bool f[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)  {
		int x;
		cin >> x;
		f[x] = true;
	}
	for (int i = 1; i < N; i++) {
		if (f[i])
			continue;
		int gcd = 0;
		for (int j = i * 2; j < N; j += i) {
			if (f[j])
				gcd = __gcd(gcd, j / i);
		}
		if (gcd == 1)
			ans++;
	}
	cout << ans;
}