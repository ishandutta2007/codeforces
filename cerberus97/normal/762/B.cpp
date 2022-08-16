/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 5;

pair <int, string> mouse[N];

int main()
{
	int a, b, c, m;
	cin >> a >> b >> c >> m;	

	for (int i = 0; i < m; ++i)
		cin >> mouse[i].first >> mouse[i].second;

	ll cost = 0, pc = 0;
	sort(mouse, mouse + m);
	for (int i = 0; i < m; ++i)
	{
		if (mouse[i].second[0] == 'P')
		{
			if (b > 0)
			{
				--b;
				++pc;
				cost += mouse[i].first;
			}

			else if (c > 0)
			{
				--c;
				++pc;
				cost += mouse[i].first;
			}
		}

		else if (a > 0)
		{
			--a;
			++pc;
			cost += mouse[i].first;
		}

		else if (c > 0)
		{
			--c;
			++pc;
			cost += mouse[i].first;
		}
	}

	cout << pc << ' ' << cost;
}