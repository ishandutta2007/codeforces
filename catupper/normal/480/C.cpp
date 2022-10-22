#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long Int;
#define MOD 1000000007

Int n, a, b, k, res;
Int dp[5400][5400];

int main(){
	cin >> n >> a >> b >> k;
	dp[0][a] = 1;
	for(int i = 0;i < k;i++){
		dp[i][b-1] = dp[i][b+1] = 0LL;
		for(Int j = 1;j <= n;j++){
			if(j == b)continue;
			Int lim = abs(b - j) - 1;
			dp[i + 1][max(1LL, j - lim)] += dp[i][j];
			dp[i + 1][min(n, j + lim) + 1] -= dp[i][j];
		}
		for(Int j = 2;j <= n;j++){
			dp[i + 1][j] += dp[i + 1][j - 1];
			dp[i + 1][j] %= MOD;
		}
		for(Int j = 1;j <= n;j++){
			dp[i + 1][j] -= dp[i][j] - MOD;
			dp[i + 1][j] %= MOD;
		}
	}
	for(int i = 1;i <= n;i++)res += dp[k][i], res %= MOD;
	if(res < 0)res += MOD;
	cout << res%MOD << endl;
	return 0;
}