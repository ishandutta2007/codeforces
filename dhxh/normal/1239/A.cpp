#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n, m, t;

long long f[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n >> m;
	
	f[1][0] = 2;
	
	for(i=2;i<=max(n, m);i++){
		f[i][1] = f[i - 1][0];
		f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mod;
	}
	
	long long ans = (f[n][0] + f[n][1] - 2 + mod) % mod + (f[m][0] + f[m][1]) % mod;
	ans %= mod;
	
	cout << ans << endl;
	
	return 0;
}