#include <iostream>
#include <cstdlib>

using namespace std;

#define type first
#define dist second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, ll> piece; 

const int N = 1e5 + 5;

piece p[3][3];

int main()
{
	ll a, b, n;
	cin >> n >> a >> b;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			p[i][j].dist = 1e10;

	for (int i = 0; i < n; ++i)
	{
		char c;
		ll x, y;
		cin >> c >> x >> y;

		if (x == a)
		{
			if (y > b)
			{
				if (y-b < p[0][1].dist)
					p[0][1] = {c, y-b};
			}

			else if (b-y < p[0][2].dist)
				p[0][2] = {c, b-y};
		}

		else if (y == b)
		{
			if (x > a)
			{
				if (x-a < p[1][0].dist)
					p[1][0] = {c, x-a};
			}

			else if (a-x < p[2][0].dist)
				p[2][0] = {c, a-x};
		}

		else if (abs(a-x) == abs(b-y))
		{
			int i = (x<a)?2:1, j = (y<b)?2:1;
			ll d = abs(a-x);

			if (d < p[i][j].dist)
				p[i][j] = {c, d};
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			// cout << i << ' ' << j << ' ' << p[i][j].type << ' ' << p[i][j].dist << endl;

			if (p[i][j].dist == 1e10)
				continue;

			if (p[i][j].type == 'Q')
			{
				cout << "YES";
				return 0;
			}

			if ((!i or !j) and (p[i][j].type == 'R'))
			{
				cout << "YES";
				return 0;
			}

			// cout << i << ' ' << j << ' ' << p[i][j].type << ' ' << p[i][j].dist << endl;

			if (i and j and (p[i][j].type == 'B'))
			{
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
}