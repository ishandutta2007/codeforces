/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, M = log2(N) + 5;

int a[N], table[N][M];
ll dp[N];

void buildTable(int n);
int queryTable(int l, int r);

int main()
{	
	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a[i];
		--a[i];
	}

	ll ans = 0;
	a[n-1] = n-1;
	dp[n-1] = 0;
	buildTable(n);
	for (int i = n-2; i >= 0; --i)
	{
		int j = queryTable(i+1, a[i]);
		dp[i] = dp[j] + (n-1-i) - (a[i]-j);
		ans += dp[i];
	}

	cout << ans;
}

void buildTable(int n)
{
	int mxJ = log2(n), p2 = 1;
	for (int j = 0; j <= mxJ; ++j, p2 *= 2)
	{
		for (int i = 0; i + p2 <= n; ++i)
		{
			if (!j)
				table[i][j] = i;

			else if (a[table[i][j-1]] > a[table[i+p2/2][j-1]])
				table[i][j] = table[i][j-1];

			else
				table[i][j] = table[i+p2/2][j-1];
		}
	}
}

int queryTable(int l, int r)
{
	int lg = log2(r-l+1), p2 = (1<<lg);

	if (a[table[l][lg]] > a[table[r-p2+1][lg]])
		return table[l][lg];

	else
		return table[r-p2+1][lg];
}