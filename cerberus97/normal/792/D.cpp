/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

ll root;
stack <int> temp;

void move(ll &i, ll &l, ll &r, char c);

int main()
{
	ll n; int q;
	cin >> n >> q;
	root = (n + 1) / 2;
	ll pos = root, l = 1, r = n;
	while (q--)
	{
		while (pos != root)
			move(pos, l, r, 'U');

		ll u; string s;
		cin >> u >> s;
		while (pos != u)
		{
			if (u < pos)
				move(pos, l, r, 'L');
			else
				move(pos, l, r, 'R');
		}

		for (auto &i : s)
			move(pos, l, r, i);

		cout << pos << endl;		
	}
}

void move(ll &i, ll &l, ll &r, char c)
{
	if (c == 'U')
	{
		if (i != root)
		{
			int dir = temp.top();
			temp.pop();
			if (dir == -1)
			{
				i = l - 1;
				l = 2*l - r - 2;
			}

			else
			{
				i = r + 1;
				r = 2*r - l + 2;
			}
		}

		return;
	}

	if (l == r)
		return;

	if (c == 'L')
	{
		temp.push(1);
		r = (r + l - 2) / 2;
		i = (l + r) / 2;
		return;
	}

	if (c == 'R')
	{
		temp.push(-1);
		l = (r + l + 2) / 2;
		i = (l + r) / 2;
	}
}