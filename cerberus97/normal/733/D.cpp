#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef set <pll, greater <pll> > s;

const int N = 1e5 + 5, INF = 2147483647;

map <pll, s> m;

ll a[N][3];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];

		sort(a[i], a[i] + 3);

		for (int j = 0; j < 3; ++j)
		{
			for (int k = j+1; k < 3; ++k)
			{
				ll temp = a[i][3-j-k];
				pll key = {a[i][j], a[i][k]};

				m[key].insert({temp, i});
			}
		}
	}

	ll ans = 0, k, k1, k2;

	for (int i = 0; i < n; ++i)
	{
		ll temp = a[i][0];
		pll key = {a[i][1],a[i][2]};

		if (temp > ans)
		{
			ans = temp;
			k = 1;
			k1 = i+1;
		}

		if (m.find(key) != m.end())
		{
			for (auto &j : m[key])
			{
				if (j.second != i)
				{
					temp += j.first;

					ll cur = min(temp, min(a[i][1], a[i][2]));

					if (cur > ans)
					{
						ans = cur;
						k = 2;
						k1 = i+1;
						k2 = j.second+1;
					}

					break;
				}
			}
		}
	}

	cout << k << '\n' << k1;

	if (k == 2)
		cout << ' ' << k2;
}