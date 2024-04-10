#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 24;

int n, k;
int a[max_n], b[3];
ll sum[1 << max_n];
ll dp[1 << max_n];

void init(){
	for (int i = 1; i < (1 << n); i++)
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1){
				sum[i] = sum[i ^ (1 << j)] + a[j];
				break;
			}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> b[i];
	init();
	

	for (int i = 1; i < (1 << n); i++){
		bool fl = 0;
		for (int j = 0; j < k; j++)
			fl |= (b[j] == sum[i]);
		if (fl)	continue;
		if (__builtin_popcount(i) == 1)	
			dp[i] = 1;
		else
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)	dp[i] = ((ll)dp[i] + dp[i ^ (1 << j)]);
		dp[i] %= MOD;
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
}