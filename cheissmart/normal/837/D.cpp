#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[202], b[202], dp[2][202][6000];

int main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		ll t;
		cin >> t;
		while(t && t % 2 == 0) {
			a[i]++;
			t /= 2;
		}
		while(t && t % 5 == 0) {
			b[i]++;
			t /= 5;
		}
	}
	for(int i=0;i<202;i++)
		for(int j=0;j<6000;j++)
			dp[0][i][j] = dp[1][i][j] = -INF;
	dp[0][0][0] = 0;
	dp[0][1][b[0]] = a[0];
	for(int i=1;i<n;i++) {
		dp[i%2][0][0] = 0;
		for(int j=1;j<=i+1;j++) {
			for(int l=0;l<6000;l++) {
				dp[i%2][j][l] = dp[(i-1)%2][j][l];
				if(l>=b[i]) dp[i%2][j][l] = max(dp[i%2][j][l], dp[(i-1)%2][j-1][l-b[i]]+a[i]);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<6000;i++)
		ans = max(ans, min(i, dp[(n-1)%2][k][i]));
	cout << ans << endl;
}