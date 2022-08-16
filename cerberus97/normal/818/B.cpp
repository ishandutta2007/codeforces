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

const int N = 110;

int a[N], l[N];
bool seen[N] = {0}, used[N] = {0};

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> l[i];

	bool ans = true;
	for (int i = 1; i < m; ++i)
	{
		int temp = l[i + 1] - l[i];
		if (l[i + 1] <= l[i])
			temp += n;

		if (seen[l[i]])
		{
			if (a[l[i]] != temp)
			{
				ans = false;
				break;
			}
		}

		else if (used[temp])
		{
			ans = false;
			break;
		}

		else
		{
			seen[l[i]] = true;
			used[temp] = true;
			a[l[i]] = temp;
		}
	}

	int cur = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
		{
			while (used[cur])
				++cur;

			a[i] = cur++;
		}
	}

	if (!ans)
		cout << -1;

	else
	{
		for (int i = 1; i <= n; ++i)
			cout << a[i] << ' ';
	}
}