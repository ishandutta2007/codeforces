#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
	if(a == 0)return b;
	return gcd(b % a, a);
}

int n, m;
int num[5250], bad[5250], g[5250], dp[5250],res;

int cost(int x){
	int res = 0;
	for(int i = 0;i < m;i++){
		while(x % bad[i] == 0){
			res--;
			x /= bad[i];
		}
	}
	for(int i = 2;i * i <= x;i++){
		while(x % i == 0){
			x /= i;
			res++;
		}
	}
	if(x != 1)res++;
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> num[i];
	for(int i = 0;i < m;i++)cin >> bad[i];
	fill(dp, dp + 5250, -(1 << 30));
    dp[0] = 0;
	for(int i = 1;i <= n;i++){
		dp[0] += cost(num[i]);
	}
	for(int i = 1;i <= n;i++){
		g[i] = gcd(g[i - 1], num[i]);
	}
	res = dp[0];
	for(int i = 1;i <= n;i++){
		int r = cost(g[i]);
		for(int j = 0;j < i;j++){
			dp[i] = max(dp[i], dp[j] - (i - j) * r);
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
}