/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5, M = 26, inf = 1e5, mod = 1e9 + 7;

int a[M], s[N];
bool valid[N][N] = {0};
ll f[N], g[N];

int main()
{
	int n; string t;
	cin >> n >> t;

	for (int i = 0; i < n; ++i)
		s[i] = t[i] - 'a';

	for (int i = 0; i < M; ++i)
		cin >> a[i];

	int max_valid = 0;
	for (int i = 0; i < n; ++i)
	{
		int allowed_len = inf;
		for (int j = i; j < n; ++j)
		{
			if (j - i + 1 > a[s[j]] or j - i + 1 > allowed_len)
				break;

			valid[i][j] = true;
			allowed_len = min(allowed_len, a[s[j]]);
			max_valid = max(max_valid, j - i + 1);
		}
	}

	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		f[i] = valid[0][i];
		g[i] = valid[0][i] ? 1 : inf;
		for (int j = i - 1; j >= 0; --j)
		{
			if (!valid[j + 1][i])
				break;

			f[i] = (f[i] + f[j]) % mod;
			g[i] = min(g[i], g[j] + 1);
		}
	}

	cout << f[n - 1] << '\n' << max_valid << '\n' << g[n - 1] << '\n';
}