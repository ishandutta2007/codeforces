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

const int N = 60;

int a[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];

	bool ans = true;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] == 1)
				continue;

			ans = false;
			for (int s = 1; s <= n; ++s)
			{
				for (int t = 1; t <= n; ++t)
				{
					if (a[i][s] + a[t][j] == a[i][j])
					{
						ans = true;
						break;
					}
				}

				if (ans)
					break;
			}

			if (!ans)
				break;
		}

		if (!ans)
			break;
	}

	if (ans)
		cout << "Yes";
	else
		cout << "No";
}