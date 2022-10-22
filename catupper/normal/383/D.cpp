#include<iostream>
#include<algorithm>
using namespace std;

#define MOD 1000000007
long long dp[2][21000];

long long sum[21000], res, n, a[1050];

int main(){
	cin >> n;
	sum[10005] = 1;
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++){
		dp[(i + 1) & 1][10005]++;
		for(int j = 0;j < 21000;j++){
			dp[i & 1][j] = 0;
			if(j + a[i] < 21000)dp[i & 1][j] += dp[(i + 1) & 1][j + a[i]];
			if(j - a[i] >= 0)dp[i & 1][j] += dp[(i + 1) & 1][j -a[i]];
			dp[i & 1][j] %= MOD;
		}
		res += dp[i & 1][10005];
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}