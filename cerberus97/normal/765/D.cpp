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

const int N = 1e5 + 5;

int f[N], g[N], h[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> f[i];

	int x = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (f[f[i]] != f[i])
		{
			cout << -1;
			return 0;
		}

		if (f[i] == i)
		{
			g[i] = x;
			h[x] = i;
			++x;
		}
	}

	cout << x - 1 << endl;
	for (int i = 1; i <= n; ++i)
	{
		if (f[i] != i)
			g[i] = g[f[i]];

		cout << g[i] << ' ';
	}

	cout << endl;
	for (int i = 1; i < x; ++i)
		cout << h[i] << ' ';


}