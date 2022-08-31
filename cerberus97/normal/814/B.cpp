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

const int N = 1e3 + 5;

int a[N], b[N], p[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	for (int i = 0; i < n; ++i)
	{
		bool seen[N] = {0}, ans = true;
		int ctr = 0;
		for (int j = 0; j < n; ++j)
		{
			if (j != i)
			{
				if (seen[a[j]])
				{
					ans = false;
					break;
				}

				p[j] = a[j];
				if (a[j] == b[j])
					++ctr;

				seen[a[j]] = true;
			}
		}

		for (int j = 1; j <= n; ++j)
		{
			if (!seen[j])
			{
				p[i] = j;
				if (p[i] == b[i])
					++ctr;
			}
		}

		if (ans and ctr == n - 1)
		{
			for (int j = 0; j < n; ++j)
				cout << p[j] << ' ';

			break;
		}
	}
}