#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
Int n, x, cnt[108000], dp[2][108000], res;

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x;
		cnt[x] += x;
	}
	
	for(int i = 1;i <= 100000;i++){
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = dp[0][i - 1] + cnt[i];
		res = max(res, dp[0][i]);
		res = max(res, dp[1][i]);
	}
	cout << res << endl;
	return 0;
}