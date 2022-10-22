#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define MOD 1000000007

string str[505];
int dp[2][500][500];
int n, m;

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> str[i];
	}	
	dp[0][0][n-1] = str[0][0] == str[n-1][m-1];
	int l = 0, r = n + m - 2;
	while(l + 2 <= r){
		l++,r--;
		int np = l%2;
		int p = np^1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				dp[np][i][j] = 0;
				if(r-j >= m || r-j < 0)continue;
				if(l-i >= m || l-i < 0)continue;
				if(str[i][l-i] != str[j][r-j])continue;
				dp[np][i][j] += dp[p][i][j];dp[np][i][j] %= MOD;
				if(i-1 >= 0)dp[np][i][j] += dp[p][i-1][j];dp[np][i][j] %= MOD;
				if(j+1 < n)dp[np][i][j] += dp[p][i][j+1];dp[np][i][j] %= MOD;
				if(i-1 >= 0 && j +1 < n)dp[np][i][j] += dp[p][i-1][j+1];dp[np][i][j] %= MOD;
			}
		}  
	}
	int res = 0;
	if(r == l){
		for(int i = 0;i < n;i++){
			if(r - i < 0)continue;
			if(l - i < 0)continue;	
			res += dp[l%2][i][i];
			res %= MOD;
		}
	}
	else{
		for(int i = 0;i < n;i++){
			if(r-i >= 0 && l-i >= 0){
				res += dp[l%2][i][i];
				res %= MOD;
			}
			if(r-(i+1) >= 0 && l-i >= 0){
				res += dp[l%2][i][i+1];
				res %= MOD;
			}
		}
	}
	cout << res << endl;
	return 0;
}