#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], dp[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++){
			if (i == 0)
				dp[i] = 0;
			else if (i == n - 1)
				dp[i] = dp[i - 1] + (a[i - 1] > a[i - 2] && a[i - 1] > a[i]);
			else
				dp[i] = dp[i - 1] + (a[i - 1] > a[i - 2] && a[i - 1] > a[i]);
//				cout << dp[i] << ' ';
		}
//		cout << '\n';
		int mx = -1, ans = 0, x = 0;
		for  (int i = 0; i <= n - k; i++){
//			cout << dp[i] << endl;
			if (mx < dp[i + k - 1] - dp[i + 1] + 1){
				mx = dp[i + k - 1] - dp[i + 1] + 1;
				ans = i + 1;
			}
//			cout << dp[i + k - 1] - dp[i] + 1 << ' ';
		}
//		cout << '\n';
		cout << mx << ' ' << ans << endl;
	}
}