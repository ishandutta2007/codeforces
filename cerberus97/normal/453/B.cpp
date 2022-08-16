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
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10, MX = 60, S = (1 << 17) + 10, inf = 1e5;

int a[N], b[N], prime[MX + 10], mask[MX + 10], dp[N][S], best[N][S], P;
bool seen[N][S];

bool is_prime(int i);
int f(int i, int m);

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	P = 0;
	for (int i = 2; i <= MX; ++i)
		if (is_prime(i))
			prime[P++] = i;

	for (int i = 1; i <= MX; ++i)
	{
		mask[i] = 0;
		for (int j = 0; j < P; ++j)
			if (i % prime[j] == 0)
				mask[i] |= (1 << j);
	}

	int m = (1 << P) - 1;
	f(n, m);
	for (int i = n; i >= 1; --i)
	{
		b[i] = best[i][m];
		m ^= mask[b[i]];
	}

	for (int i = 1; i <= n; ++i)
		cout << b[i] << ' ';
}

bool is_prime(int i)
{
	for (int j = 2; j * j <= i; ++j)
		if (i % j == 0)
			return false;

	return true;
}

int f(int i, int m)
{
	if (!i)
		return 0;

	if (seen[i][m])
		return dp[i][m];

	seen[i][m] = true;
	dp[i][m] = inf;
	for (int j = 1; j <= MX; ++j)
	{
		if ((mask[j] | m) == m)
		{
			int temp = abs(a[i] - j) + f(i - 1, m ^ mask[j]);
			if (temp < dp[i][m])
			{
				dp[i][m] = temp;
				best[i][m] = j;
			}
		}
	}

	return dp[i][m];
}