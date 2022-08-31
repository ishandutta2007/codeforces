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

const int N = 55, INF = 1e5;

string s[N];
int dp[N][2][2][2];
bool seen[N][2][2][2] = {0};

int solve(int n, int m, bool d, bool l, bool sp);

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	cout << solve(n, m, 1, 1, 1);
}

int solve(int n, int m, bool d, bool l, bool sp)
{
	if (!d and !l and !sp)
		return 0;

	if (!n)
		return INF;

	if (seen[n][d][l][sp])
		return dp[n][d][l][sp];

	int ans = INF;
	for (int i = 0; i < m; ++i)
	{
		int temp = min(i, m - i);
		if (isdigit(s[n][i]))
			ans = min(ans, temp + solve(n - 1, m, 0, l, sp));

		else if (isalpha(s[n][i]))
			ans = min(ans, temp + solve(n - 1, m, d, 0, sp));

		else
			ans = min(ans, temp + solve(n - 1, m, d, l, 0));
	}

	seen[n][d][l][sp] = true;
	dp[n][d][l][sp] = ans;
	return ans;
}