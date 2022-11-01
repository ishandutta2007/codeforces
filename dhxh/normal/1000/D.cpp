#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;

long long mod = 998244353;

long long n, m;

long long a[maxn];

long long f[maxn][maxn];

long long ans;

int main(){
	int i, j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			f[i][j] = (f[i - 1][j] + f[i - 1][j + 1]) % mod;
		}
		if(a[i] > 0 and i + a[i] <= n){
			f[i][a[i]] = (f[i][a[i]] + f[i - 1][0] + 1) % mod;
		}
	}
	
	cout << f[n][0] << endl;
	
	return 0;
}