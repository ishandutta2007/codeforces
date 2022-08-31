/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

bool d[N], v[N], seen[N] = {0};
vector <int> s[N], ds[N];

bool solve(int cur, bool v);

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> d[i];

	for (int i = 1; i <= m; ++i)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; ++j)
		{
			int p;
			cin >> p;
			s[i].pb(p);
			ds[p].pb(i);
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		if (!seen[i])
		{
			if (!solve(i, 0))
			{
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
}

bool solve(int cur, bool val)
{
	seen[cur] = true;
	v[cur] = val;
	bool ans = true;
	for (auto &i : s[cur])
	{
		int s1 = ds[i][0], s2 = ds[i][1];
		if (s1 != cur)
			swap(s1, s2);

		if (!seen[s2])
			ans = (ans and (solve(s2, (!d[i]) ^ v[s1])));

		else if ((v[s1] ^ v[s2]) == d[i])
			ans = false;
	}

	return ans;

}