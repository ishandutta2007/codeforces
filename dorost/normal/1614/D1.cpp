/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 5000001;
int a[M];
ll dp[M];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				a[i]++;
				if (i * i != x) 
					a[x / i]++;
			}
		}
	}
	for (int i = M - 1; i >= 1; i--) {
		dp[i] = (ll)a[i] * (ll)i;
		for (int j = i * 2; j < M; j += i) {
			dp[i] = max(dp[i], dp[j] + (ll)i * (ll)(a[i] - a[j]));
		}
	}
	cout << dp[1];
}