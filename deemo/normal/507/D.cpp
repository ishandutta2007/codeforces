#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;
const int MAXK = 1e2 + 5;

int n, k, MOD;
ll d[MAXN][MAXK], c[MAXN][MAXK], e[MAXN];
ll ss[MAXN + 10];

int main(){
	cin >> n >> k >> MOD;
	if (MOD == 1){
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < k; i++)	c[0][i] = i;
	for (int j = 1; j < MAXN; j++)
		for (int i = 0; i < k; i++)	c[j][i] = (c[j - 1][i] * 10) % k;

	for (int j = 1; j < 10; j++)	d[1][j % k] = (d[1][j % k] + 1) % MOD;
	for (int i = 1; i + 1 < MAXN; i++)
		for (int j = 0; j < k; j++)
			for (int w = 0; w < 10; w++)
				d[i + 1][(j * 10 + w) % k] = (d[i + 1][(j * 10 + w) % k] + d[i][j]) % MOD;

	ss[0] = 1;
	ss[1] = 9;
	for (int i = 2; i < MAXN; i++)
		ss[i] = (ss[i - 1] * 10LL) % MOD;

	ll ans = d[1][0] * ss[n - 1] % MOD;
	e[1] = d[1][0];
	
	for (int dig = 2; dig <= n; dig++){
		ll ret = d[dig][0];
		for (int i = dig - 1; i; i--){
			for (int kk = 0; kk < k; kk++)
				if (c[i][kk] == 0)
					ret = (ret - d[dig - i][kk] * e[i] % MOD + MOD) % MOD;
		}

		e[dig] = ret;
		ans = (ans + ret * ss[n - dig]) % MOD;
	}

	cout << ans % MOD << "\n";
	return 0;
}