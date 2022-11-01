#include <iostream>
#define mod 998244353
using namespace std;
long long f[1003][2003][2];
int main(){
	int n, k;
	cin >> n >> k;
	f[1][1][1] = f[1][2][0] = 2;
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j <= k; ++ j){
			f[i + 1][j][1] = (f[i + 1][j][1] + f[i][j][1]) % mod;
			f[i + 1][j + 1][1] = (f[i + 1][j + 1][1] + f[i][j][1]) % mod;
			f[i + 1][j + 1][0] = (f[i + 1][j + 1][0] + 2 * f[i][j][1]) % mod;

			f[i + 1][j + 2][0] = (f[i + 1][j + 2][0] + f[i][j][0]) % mod;
			f[i + 1][j][0] = (f[i + 1][j][0] + f[i][j][0]) % mod;
			f[i + 1][j][1] = (f[i + 1][j][1] + 2 * f[i][j][0]) % mod;
		}
	cout << (f[n][k][0] + f[n][k][1]) % mod << endl;
}