#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
typedef long long ll;
using namespace std;
 
int n, k, sh;
const int N = 3e5+5;
int a[N];
ll INF = 1LL<<55;
const int M = 5005;
ll dp[M][M];
 
int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1);
	int large = n%k;
	int small = k - large;
	int len = n/k;
	for(int i = 0; i <= large; ++i) {
		for(int j = 0; j <= small; ++j) {
			dp[i][j] = 1LL<<60;
			if(i == 0 && j == 0) {
				dp[i][j] = 0;
			}
			int cur = i * (len + 1) + j * (len);
			if(i != 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + a[cur] - a[cur - len]);
			}
			if(j != 0) {
				dp[i][j] = min(dp[i][j], dp[i][j-1] + a[cur] - a[cur - len+1]);
			}
		}
	}
	cout << dp[large][small] << '\n';
}