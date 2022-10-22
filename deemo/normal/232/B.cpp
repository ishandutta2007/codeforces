#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 100 + 2;

ll n, m, k, c[MAXN][MAXN], d[2][MAXN][MAXN], e[MAXN][MAXN * MAXN];

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;	
}

int main(){
	cin >> n >> m >> k;
	c[0][0] = 1;
	for (int i = 1; i < MAXN; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}
	
	ll a = m/n;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			d[0][i][j] = pw(c[i][j], a)
				, d[1][i][j] = pw(c[i][j], a + 1);

	e[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k && j <= i * n; j++)
			for (int b = 0; b + j <= k && b <= n; b++)
				e[i + 1][j + b] = (e[i + 1][j + b] + e[i][j] * (i < m % n?d[1][n][b]:d[0][n][b])) % MOD;
	
	cout << e[n][k] << "\n";
	return 0;
}