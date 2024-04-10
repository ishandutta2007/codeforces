#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long n, k;

long long C[505][505];

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		b = b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

int main(){
	long long i, j;
	
	for(i=0;i<=500;i++){
		C[i][0] = 1;
		for(j=1;j<=i;j++){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	
	cin >> n >> k;
	
	long long ans = qpow(k, n * n);
	
	for(i=1;i<=n*2;i++){
		for(j=max(i-n,0ll);j<=min(i, n);j++){
			long long sum = 1;
			if(i & 1)sum = -1;
			long long x = i * n - j * (i - j);
			sum = sum * qpow(k - 1, x) * qpow(k, n * n - x) % mod;
			sum = sum * C[n][j] % mod * C[n][i - j] % mod;
			ans += sum;
			ans %= mod;
		}
	}
	
	cout << (ans + mod) % mod << endl;
	
	return 0;
}