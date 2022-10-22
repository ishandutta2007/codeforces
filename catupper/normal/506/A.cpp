#include<iostream>
#include<algorithm>

using namespace std;
#define INF (1 << 30)
int res;
int dp[32400][600];
int n,d,x,base;
int cnt[32400];
int main(){
	cin >> n >> d;
	for(int i = 0;i < n;i++){
		cin >> x;
		cnt[x]++;
	}
	for(int i = 0;i <= 30001;i++)
		for(int j = 0;j < 600;j++)
			dp[i][j] = -INF;
	base = max(1, d - 300);
	dp[d][d-base] = 0;
	for(int i = 0;i <= 30001;i++){
		for(int j = 0;j < 600;j++){
			dp[i][j] += cnt[i];
			res = max(res, dp[i][j]);
			if(i + j - 1 + base <= 30001 && j-1 >= 0){
				dp[i+j-1+base][j-1] = max(dp[i+j-1+base][j-1], dp[i][j]);
			}
			if(i + j + base <= 30001){
				dp[i+j+base][j] = max(dp[i+j+base][j], dp[i][j]);
			}
			if(i + j + 1 + base <= 30001 && j+1 < 600){
				dp[i+j+1+base][j+1] = max(dp[i+j+1+base][j+1], dp[i][j]);
			}
		}
	}
	cout << res << endl;
	return 0;
}