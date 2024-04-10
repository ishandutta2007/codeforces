#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

typedef vector<int> vec;
typedef vector<vec> mat;

const int mod = 998244353;

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

mat mul(mat &A, mat &B)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = (C[i][j] + (ll)A[i][k] * B[k][j]) % mod;
	return C;
}

mat pow_(mat A, int b)
{
	mat X = eye(A.size());
	for (; b > 0; b >>= 1)
	{
		if (b & 1) X = mul(X, A);
		A = mul(A, A);
	}
	return X;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	mat M(3 * n, vec(3 * n));
	vector<vector<int>> adj(n);
	for (int u, v; m--; )
	{
		cin >> u >> v;
		--u, --v;
		for (int it = 2; it--; swap(u, v))
		{
			adj[u].push_back(v);
			M[v][n + u] += 1;
			M[v][2 * n + v] += -1;

			M[n + v][n + u] += 1;
			M[n + v][2 * n + v] += -1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		M[n + i][2 * n + i] += 1;
		M[2 * n + i][n + i] += 1;
	}

	// ll ans = 0;
	// for (int r = 0; r < n; ++r)
	// {
	// 	vector<vector<int>> dp(k + 2, vector<int>(n));
	// 	dp[0][r] = 1;
	// 	for (auto v : adj[r])
	// 		dp[1][v] = 1;

	// 	for (int j = 1; j < k; ++j)
	// 		for (int u = 0; u < n; ++u)
	// 			for (auto v : adj[u])
	// 			{
	// 				int uu = u, vv = v, sg = +1;
	// 				for (int z = j; z >= 0; --z)
	// 				{
	// 					dp[j + 1][v] = (dp[j + 1][v] + sg * dp[z][uu]) % mod;
	// 					swap(uu, vv);
	// 					sg = -sg;
	// 				}
	// 			}
	// 	ans = (ans + dp[k][r]) % mod;
	// }
	// cout << ans << "\n";


	debug(M);
	// mat G(2 * n, vec(1));
	// G[0][]
	// debug(mul(M, ))

	M = pow_(M, k);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + (ll)M[i][i] + M[i][n + i]) % mod;

	ans = (ans + mod) % mod;
	cout << ans << "\n";

	return 0;
}