#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define MOD 1000000007

Int dp[2160][2160], n, k;

int main(){

	for(int i = 1;i < 2159;i++){
		for(int j = 1;j < 2160;j++){
			if(i == 1)dp[i][j] = 1;
			for(int k = j;k <= 2160;k += j){
				dp[i + 1][k] += dp[i][j];
				dp[i + 1][k] %= MOD;
			}
		}
	}

	cin >> n >> k;
	Int res = 0;
	for(int i = 1;i <= n;i++){
		res += dp[k][i];
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}