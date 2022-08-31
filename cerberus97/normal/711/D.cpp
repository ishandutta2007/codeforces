#include <iostream>

using namespace std;

const int N = (int)2e5 + 5, mod = (int)1e9 + 7;

int a[N], col[N], curCol = 0;
long long p2[N];
bool seen[N] = {0};

void init()
{
	p2[0] = 1;

	for (int i = 1; i < N; ++i)
		p2[i] = (2 * p2[i-1]) % mod;
}

long long getAns(int i)
{
	seen[i] = true;
	col[i] = curCol;

	int nodes = 1, x = i;

	while (true)
	{
		if (seen[a[x]])
		{
			if (col[a[x]] != col[x])
				return p2[nodes];

			long long inCycle = 1, temp = a[x];

			while (temp != x)
			{
				temp = a[temp];
				++inCycle;
			}

			long long ans = p2[inCycle] - 2;

			while (ans < 0)
				ans += mod;

			ans = (ans * p2[nodes - inCycle]) % mod;

			return ans;
		}

		seen[a[x]] = true;
		col[a[x]] = curCol;
		++nodes;

		x = a[x];

	}
}

int main()
{
	init();

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	long long ans = 1;

	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
		{
			ans = (ans * getAns(i)) % mod;
			++curCol;
		}
	}

	cout << ans << '\n';
}