/*
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 21, M = (1<<N);
const double eps = 1e-7;

double dp[M], p[N], ans[N] = {0};
bool seen[M] = {0};

double solve(int state, int n);

int main()
{
	int n, k;
	cin >> n >> k;

	int zero = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		if (p[i] < eps)
			++zero;
	}

	if (n - zero < k)
		k = n - zero;

	int states = (1<<n);
	for (int j = 0; j < states; ++j) 
	{
		if (__builtin_popcount(j) == k)
		{
			for (int i = 0; i < n; ++i)
			{
				if (j & (1<<i))
					ans[i] += solve(j, n);
			}	
		}
	}

	for (int i = 0; i < n; ++i)
		cout << fixed << setprecision(7) << ans[i] << ' ';
}

double solve(int state, int n)
{
	if (!state)
		return 1.0;

	if (seen[state])
		return dp[state];

	seen[state] = true;
	double sum = 0;
	for (int i = 0; i < n; ++i)
		if (state & (1<<i))
			sum += p[i];

	for (int i = 0; i < n; ++i)
	{
		if (state & (1<<i))
		{
			if (p[i] < eps)
			{
				dp[state] = 0;
				break;
			}
			dp[state] += (p[i] * solve(state & (~(1<<i)), n)) / (1 - sum + p[i]);
		}
	}
	
	return dp[state];
}