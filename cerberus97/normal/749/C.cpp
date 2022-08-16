/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

string s;
bool removed[N] = {0};
set <int> ind_r, ind_d;

int main()
{
	int n;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'R')
			ind_r.insert(i);

		else
			ind_d.insert(i);
	}

	while (!ind_r.empty() and !ind_d.empty())
	{
		for (int i = 0; i < n; ++i)
		{
			if (removed[i])
				continue;

			if (s[i] == 'R')
			{
				auto j = ind_d.upper_bound(i);

				if (j == ind_d.end())
					j = ind_d.begin();

				if (j != ind_d.end())
				{
					removed[*j] = true;
					ind_d.erase(j);
				}

				else
					break;
			}

			else
			{
				auto j = ind_r.upper_bound(i);

				if (j == ind_r.end())
					j = ind_r.begin();

				if (j != ind_r.end())
				{
					removed[*j] = true;
					ind_r.erase(j);
				}

				else
					break;
			}
		}
	}

	if (!ind_r.empty())
		cout << 'R';

	else
		cout << 'D';	
}