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

const int N = 1e3 + 5;

char a[N][N];
int r[N], c[N];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '*')
			{
				++total;
				r[i]++;
				c[j]++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (r[i] + c[j] - (a[i][j] == '*') == total)
			{
				cout << "YES\n" << i+1 << ' ' << j+1;
				return 0;
			}
		}
	}

	cout << "NO";
}