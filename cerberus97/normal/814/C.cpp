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

const int N = 2000;

char s[N];

int main()
{
	int n;
	cin >> n >> s;
	int q;
	cin >> q;
	while (q--)
	{
		int m; char c;
		cin >> m >> c;
		int i = 0, j = 0, ctr = 0, ans = 0;
		if (s[i] != c)
			++ctr;

		while (j < n)
		{
			if (ctr <= m)
			{
				ans = max(ans, j - i + 1);
				++j;
				if (s[j] != c)
					++ctr;
			}

			else
			{
				if (s[i] != c)
					--ctr;

				++i;
			}
		}

		cout << ans << '\n';
	}
}