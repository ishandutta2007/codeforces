#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define MOD 1000000007

typedef long long Int;

Int c[4001][4001];
Int dp[4001][4001];
Int sums[4001];



bool init(){
	for(int i = 0;i < 4001;i++){
		for(int j = 0;j < 4001;j++){
			if(i == 0 || j == 0)c[i][j] = 1;
			else if(i == j)c[i][j] = 1;
			else{
				c[i][j] = c[i-1][j-1] + c[i-1][j];
				c[i][j] %= MOD;
			}
			if(i == 0 || i < j)continue;
			if(j == 1)dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * j) % MOD;
		}
	}
	for(int i = 0;i <= 4000;i++)
		for(int j = 1;j <= i;j++)
			sums[i] = (sums[i] + dp[i][j]) % MOD;
}
           
Int n, res;

int hoge(int n){
	res = 0;
	for(int i = 0;i < n;i++){
		res += c[n][i] * sums[i];
		res %= MOD;
	}
	cout << (res+1)%MOD << endl;
}

int main(){
	int n;
	init();
	cin >> n;
	hoge(n);
	return 0;
}