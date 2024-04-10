#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

double dp[5002][2];
double mdp[5002][2];
double p[5002], ttp[5002];
int t[5002];
double res;
int n, T;

int main(){
	cin >> n >> T;
	for(int i = 0;i < n;i++){
		cin >> p[i] >> t[i];
		p[i] /= 100;
		ttp[i] = pow(1-p[i], t[i]);
	}
	p[n] = 0;
	p[n+1] = 0;
	ttp[n] = ttp[n + 1] = 1;
	t[n] = 5002;
	t[n+1] = 5002;
	n++;
	dp[0][0] = 1;
	mdp[t[0]][0] += ttp[0];
	dp[t[0]][1] += ttp[0];
	
	for(int jj = 0;jj < n;jj++){
		for(int i = 0;i <= T;i++){
			int j = jj%2;
			dp[i][j] -= mdp[i][j];
			dp[i+1][j^1] += dp[i][j] * p[jj];
			if(i + t[jj]+1 < 5002){
				mdp[i+t[jj]+1][j] += dp[i+1][j]*ttp[jj];
				dp[i+t[jj]+1][j^1] += dp[i+1][j]*ttp[jj];
			}			
			dp[i+1][j] += dp[i][j] * (1-p[jj]);
			if(i == T)res += jj * dp[T][j];
			mdp[i][j] = dp[i][j] = 0;
		}                          
	}
	printf("%.10lf\n", res);
	return 0;
}