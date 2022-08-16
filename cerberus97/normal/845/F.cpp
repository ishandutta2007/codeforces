/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 15, M = 260, P = (1 << N) + 10, mod = 1e9 + 7;

ll dp[M][P][2][2];
int walls[M], covered[M];
char s[M][M], t[N][M];

void transpose(int &n, int &m);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	if (n > m)
		transpose(n, m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'x')
				walls[j] |= (1 << i);

	int max_pos = n * m - 1, max_mask = (1 << n) - 1;
	dp[0][walls[0]][0][0] = 1;
	for (int pos = 0; pos <= max_pos; ++pos)
	{
		for (int mask = 0; mask <= max_mask; ++mask)
		{
			for (int f1 = 0; f1 < 2; ++f1)
			{
				for (int f2 = 0; f2 < 2; ++f2)
				{	
					dp[pos][mask][f1][f2] %= mod;
					int temp = dp[pos][mask][f1][f2];
					// if (!f1)
						// cerr << pos << ' ' << mask << ' ' << f1 << ' ' << f2 << ' ' << temp << endl;

					bool empty = (s[pos % n][pos / n] == '.'), safe = (!empty or (mask & (1 << (pos % n))) or f1);
					if (!temp)
						continue;

					if (pos % n != n - 1)
					{
						if (!f2 or safe)
							dp[pos + 1][mask][f1 and empty][f2 or !safe] += temp;

						if (empty)
							dp[pos + 1][mask | (1 << (pos % n))][true][f2] += temp;
					}

					else
					{
						if (!f2 or safe)
							dp[pos + 1][(mask & ~walls[pos / n]) | walls[pos / n + 1]][false][f2 or !safe] += temp;

						if (empty)
							dp[pos + 1][(mask & ~walls[pos / n]) | (1 << (pos % n)) | walls[pos / n + 1]][false][f2] += temp;
					}
				}
			}
		}
	}

	ll ans = 0;
	for (int mask = 0; mask <= max_mask; ++mask)
		for (int f1 = 0; f1 < 2; ++f1)
			for (int f2 = 0; f2 < 2; ++f2)
				ans += dp[max_pos + 1][mask][f1][f2];

	cout << ans % mod;
}

void transpose(int &n, int &m)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			t[j][i] = s[i][j];

	swap(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			s[i][j] = t[i][j];
}