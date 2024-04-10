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

const int INF = 1e9 + 7, M = 998244353;

int cnt[5003], inv[5003], dp[5003][5003];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		cnt[t]++;
	}
	inv[1] = 1;
	for(int i=2;i<=n;i++) {
		inv[i] = 1LL * (M-M/i) * inv[M % i] % M; 
		assert(i*1ll*inv[i]%M==1);
	}
	dp[0][0]=1;
	int ans = 0;
	for(int i=1;i<=n;i++) {
		dp[i][0]=1;
		for(int j=1;j<=n;j++) {
			dp[i][j] = (dp[i-1][j] + 1LL * dp[i-1][j-1] * cnt[i] % M * inv[n-j+1] % M) % M;
		}
		for(int j=0;j<n;j++) {
			ans = (ans + 1LL * dp[i-1][j] * cnt[i] % M * (cnt[i] - 1) % M * inv[n-j] % M * inv[n-j-1] % M) % M; 
		}
	}
	cout << ans << endl; 
}