/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include "map"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e3 + 10, M = 1e3 + 10;

map <string, int> mp;
bool type[N], v[N], ans1[M], ans2[M];
string v1[N], v2[N];
int op[N];

int main()
{
	fast_cin();
	int n, m;
	cin >> n >> m;

	int p = 1;
	mp["?"] = 0;
	type[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		string var, temp, num;
		cin >> var >> temp >> num;
		mp[var] = p;

		if (num[0] == '0' or num[0] == '1')
		{
			type[p] = 0;
			v1[p] = num;
		}

		else
		{
			string o, num2;
			cin >> o >> num2;
			type[p] = 1;
			v1[p] = num;
			v2[p] = num2;
			
			if (o[0] == 'A')
				op[p] = 0;

			else if (o[0] == 'O')
				op[p] = 1;

			else
				op[p] = 2;
		}

		++p;
	}

	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout << type[i] << endl;
	// 	cout << v1[i] << endl;
	// 	if (type[i] == 1)
	// 		cout << op[i] << ' ' << v2[i] << endl;
	// }

	for (int i = 0; i < m; ++i)
	{
		int mx1 = N, mx2 = -1;
		for (int j = 0; j < 2; ++j)
		{
			v[0] = j;
			int ctr = 0;
			for (int k = 1; k <= n; ++k)
			{
				if (type[k] == 0)
					v[k] = v1[k][i] - '0';

				else
				{
					int p1 = mp[v1[k]], p2 = mp[v2[k]];
					bool b1 = v[p1], b2 = v[p2];

					if (op[k] == 0)
						v[k] = b1 & b2;
					else if (op[k] == 1)
						v[k] = b1 | b2;
					else
						v[k] = b1 ^ b2;
				}

				if (v[k])
					++ctr;
			}

			if (ctr < mx1)
			{
				mx1 = ctr;
				ans1[i] = j;
			}

			if (ctr > mx2)
			{
				mx2 = ctr;
				ans2[i] = j;
			}
		}
	}

	for (int i = 0; i < m; ++i)
		cout << ans1[i];

	cout << endl;
	for (int i = 0; i < m; ++i)
		cout << ans2[i];
}