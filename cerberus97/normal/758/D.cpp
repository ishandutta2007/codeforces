/*
Hanit Banga
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int K = 65;
const ll INF = 2e18, MAX = 1e18;

char k[K];
bool seen[K][K] = {0};
ll dp[K][K];

ll solve(int i, int j, ll base);

int main()
{
	k[0] = '0';
	ll n;
	cin >> n >> (k + 1);
	int len = strlen(k) - 1;

	if (len < 2)
	{
		cout << (k + 1);
		return 0;
	}

	for (int i = 1; i < K; ++i)
	{
		if (solve(len, i, n) <= MAX)
		{
			cout << solve(len, i, n);
			break;
		}
	}
}

ll solve(int i, int j, ll base)
{
	if (!i and !j)
		return 0;

	if (!i or !j)
		return INF;

	if (seen[i][j])
		return dp[i][j];

	seen[i][j] = true;
	dp[i][j] = INF;
	ll num = 0, mul = 1;

	for (int p = i; p >= 1; --p)
	{
		if (mul < base and p != i)
			mul *= 10;

		if (k[p] != '0' and mul >= base)
			break;

		num += mul * (k[p] - '0');
		if (num >= base)
			break;

		if (k[p] == '0' and i - p + 1 > 1)
			continue;

		if (solve(p - 1, j - 1, base) >= INF)
			continue;

		if (double(solve(p - 1, j - 1, base)) * base > MAX)
			continue;

		dp[i][j] = min(dp[i][j], num + base * solve(p - 1, j - 1, base));
	}

	return dp[i][j];
}