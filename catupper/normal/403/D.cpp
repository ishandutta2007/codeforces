#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
#define MOD (1000000007)
typedef long long Int;

Int ans[1050][1050];
Int comb[1050][1050];
Int fact[1050];
Int dp[1050][1050];
void init(){
	fact[0] = 1;
	dp[0][0] = 1;
	for(int i = 0;i < 1050;i++){
		if(i){
			fact[i] = fact[i - 1] * i;
			fact[i] %= MOD;
		}
		for(int j = 0;j <= i;j++){
			if(i == j || j == 0)comb[i][j] = 1;
			else{
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
				comb[i][j] %= MOD;
			}
		}
	}
	for(int i = 1;i < 1050;i++){
		for(int j = i * (i + 1) / 2;j < 1050;j++){
			for(int k = 1;k * i <= j;k++){
				dp[i][j] += dp[i - 1][j - k * i];				
				dp[i][j] %= MOD;
			}
		}
	}
}

Int p(int a, int b){
	return comb[a + b - 1][a];
}

int main(){
	int t, k, n;
	init();
	for(int k = 1;k < 50;k++){
		for(int n =k * (k - 1) / 2; n<= 1000;n++){
			Int res = 0;
			for(int i = k * (k - 1) / 2;i <= n - k;i++){
				res += dp[k][i + k] * p(n - k - i, k + 1) % MOD;
				res %= MOD;
			}	
			ans[k][n] = res * fact[k] % MOD;
		} 
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		printf("%lld\n", ans[k][n]);
	}
	return 0;
}