#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str;
int same[5010][5010];
long long dp[5010][5010];
int n;
long long res;
#define MOD 1000000007
bool ok(int x, int y){
	int p = same[y-x][x];
	if(p >= y)return false;
	return str[p] < str[p + y - x];
}

int main(){
	cin >> n;
	cin >> str;	
	dp[0][1] = 1;
	for(int i = 1;i < n;i++){
		int ans = n-1;
		for(int j = n-i-1;j >= 0;j--){
			if(str[j] != str[j+i])ans = j;
			same[i][j] = ans;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			dp[i][j+1] += dp[i][j];
			dp[i][j+1] %= MOD;
		}
		for(int j = i+1;j+j-i <= n;j++){
			if(str[j] == '0')continue;
			if(ok(i, j)){
				dp[j][j+j-i] += dp[i][j];
				dp[j][j+j-i] %= MOD;
			}
			else if(j+j-i+1 <= n){
				dp[j][j+j-i+1] += dp[i][j];
				dp[j][j+j-i+1] %= MOD;
			}
		}
	}
	
	for(int i = 0;i < n;i++){
		res += dp[i][n];
		res %= MOD;
	}
	
	cout << res << endl;
	return 0;
	
}