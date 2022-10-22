/*	* In the name of GOD
 * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], dp[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			dp[i] = 0;
		}
		int mx = 0, an = 0;
		for (int i = n; i >= 1; i--){
			for (int j = 2; j <= n / i; j++){
				if (a[i * j] > a[i]){
					dp[i] = max(dp[i], dp[i * j] + 1);
				}
			}
		}
		for (int i = 0; i < n; i++){
			mx = max(mx, dp[i]);
		}
		cout << mx + 1 << endl;
	}
}