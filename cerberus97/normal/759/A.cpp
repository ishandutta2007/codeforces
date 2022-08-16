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

const int N = 2e5 + 5;

int p[N], b[N], color[N];
bool seen[N] = {0};

int dfs(int start, int col);
bool check(int start, int n);

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	bool f = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
		if (b[i])
			f = !f;
	}

	if (check(1, n))
	{
		cout << f;
		return 0;
	}

	memset(seen, 0, sizeof(seen));
	int ans = f, ctr = 0, col = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
			ctr += dfs(i, col++);
	}

	ans += ctr;
	cout << ans;
}

int dfs(int start, int col)
{
	seen[start] = true;
	color[start] = col;
	int cur = start;

	while (!seen[p[cur]])
	{
		cur = p[cur];
		seen[cur] = true;
		color[cur] = col;
	}

	if (color[p[cur]] == color[cur])
		return 1;

	return 0;
}

bool check(int start, int n)
{
	seen[start] = true;
	int ctr = 1, cur = start;

	while (!seen[p[cur]])
	{
		cur = p[cur];
		seen[cur] = true;
		++ctr;
	}

	return (ctr == n and p[cur] == start);
}