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

const int N = 1e5 + 5, M = 1e6 + 5;

int c[N], ctr[M] = {0};
set <pii> s;

int main()
{
	int n, a;
	cin >> n >> a;
	for (int i = 1; i <= min(a + 1, 1000000); ++i)
		s.insert({0, i});

	s.erase({0, a});
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		if (c[i] != a)
		{
			if (ctr[c[i]] >= ctr[a])
			{
				s.erase({ctr[c[i]], c[i]});
				s.insert({++ctr[c[i]], c[i]});
			}
		}

		else
		{
			++ctr[a];
			while (!s.empty() and s.begin()->first < ctr[a])
				s.erase(s.begin());
		}
	}

	if (s.empty())
		cout << -1;
	else
		cout << s.begin()->second;
}