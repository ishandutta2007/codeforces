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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, inf = 500;

int main()
{
	int n;
	cin >> n;
	int ans = 0, no_overtake_signs = 0, speed = 0;
	stack <int> speed_signs;
	speed_signs.push(inf);
	for (int i = 1; i <= n; ++i)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			cin >> speed;
			while (speed > speed_signs.top())
			{
				++ans;
				speed_signs.pop();
			}
		}

		else if (t == 2)
		{
			ans += no_overtake_signs;
			no_overtake_signs = 0;
		}

		else if (t == 3)
		{
			int s;
			cin >> s;
			if (s < speed)
				++ans;
			else
				speed_signs.push(s);
		}

		else if (t == 4)
		{
			no_overtake_signs = 0;
		}

		else if (t == 5)
		{
			while (!speed_signs.empty())
				speed_signs.pop();

			speed_signs.push(inf);
		}

		else
		{
			no_overtake_signs++;
		}
	}

	cout << ans;
}