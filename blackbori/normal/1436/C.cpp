#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll C[1010][1010], F[1010];
ll n, k, p, a, x, y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i, j, l, r, m;

	cin >> n >> k >> p;

	for(C[0][0] = i = 1; i <= n; i ++){
		for(C[i][0] = j = 1; j <= i; j ++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	for(F[0] = i = 1; i <= n; i ++){
		F[i] = F[i - 1] * i % mod;
	}

	for(l = 0, r = n; l < r; ){
		m = (l + r) / 2;
		if(p < m) x ++, r = m;
		else if(p >= m) y ++, l = m + 1;
	}
	y --;

	a = C[n - k][x] * C[k - 1][y] % mod * F[x] % mod * F[y] % mod * F[n - 1 - x - y] % mod;

	cout << a << "\n";

	return 0;
}