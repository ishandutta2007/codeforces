#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

const int maxn = 2e5 + 3;

using namespace std;

long long mod = 1e9 + 7;

long long n, l, r;

long long a[3];

long long f[maxn][3];

int main(){
	int i, j, k;
	
	cin >> n >> l >> r;
	
	a[0] = a[1] = a[2] = (r - l + 1) / 3;
	
	a[l % 3] += ((r - l + 1) % 3 > 0);
	a[(l + 1) % 3] += ((r - l + 1) % 3 > 1);
	
	f[0][0] = 1;
	
	for(i=1;i<=n;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				f[i][(j + k) % 3] = (f[i][(j + k) % 3] + f[i - 1][j] * a[k]) % mod;
			}
		}
	}
	
	cout << f[n][0] << endl;
	
	return 0;
}