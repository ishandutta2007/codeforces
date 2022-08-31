/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 105, mod = 1e9 + 7;

ll a[N];

int solve(int n, ll k);
void powMatrix(ll mat[N][N], int n, ll k);
void mulMatrix(ll m1[N][N], ll m2[N][N], ll res[N][N], int n, int m, int k);
void copyMatrix(ll m1[N][N], ll m2[N][N], int n, int m);

int main()
{
	int n;
	ll k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	cout << solve(n, k);
}

int solve(int n, ll k)
{
	ll b[N][N] = {0};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
			{
				b[i][j] = 1;
				b[j][i] = 1;
			}
		}
	}

	ll c[N][N], res[N][N];
	for (int i = 1; i <= n; ++i)
		c[i][1] = 1;

	powMatrix(b, n, k-1);
	mulMatrix(b, c, res, n, n, 1);

	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += res[i][1];

	return ans % mod;
}

void powMatrix(ll mat[N][N], int n, ll k)
{
	ll res[N][N] = {0}, temp[N][N];
	for (int i = 1; i <= n; ++i)
		res[i][i] = 1;

	while (k)
	{
		if (k % 2)
		{
			mulMatrix(res, mat, temp, n, n, n);
			copyMatrix(res, temp, n, n);
		}

		k /= 2;
		mulMatrix(mat, mat, temp, n, n, n);
		copyMatrix(mat, temp, n, n);
	}

	copyMatrix(mat, res, n, n);
}

void mulMatrix(ll m1[N][N], ll m2[N][N], ll res[N][N], int n, int m, int p)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= p; ++j)
		{
			res[i][j] = 0;
			for (int k = 1; k <= m; ++k)
				res[i][j] = (res[i][j] + (m1[i][k]*m2[k][j])) % mod;
		}
	}
}

void copyMatrix(ll m1[N][N], ll m2[N][N], int n, int m)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			m1[i][j] = m2[i][j];
}