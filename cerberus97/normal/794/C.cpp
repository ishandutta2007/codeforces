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
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 5;

char ans[N] = {0};
vector <char> a, b;

int main()
{
	string s, t;
	cin >> s >> t;
	for (auto i : s)
		a.pb(i);

	for (auto i : t)
		b.pb(i);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int turn = 0, n = s.length(), l = 0, r = n - 1, la = 0, ra = (n - 1) / 2, lb = (n + 1) / 2, rb = n - 1;
	for (int i = n; i > 0; --i)
	{
		char a_min = a[la], a_max = a[ra], b_min = b[lb], b_max = b[rb];
		if (!turn)
		{
			if (a_min < b_max)
			{
				ans[l++] = a_min;
				++la;
			}

			else
			{
				ans[r--] = a_max;
				--ra;
			}
		}

		else
		{
			if (a_min < b_max)
			{
				ans[l++] = b_max;
				--rb;
			}

			else
			{
				ans[r--] = b_min;
				++lb;
			}
		}

		turn = 1 - turn;
	}

	cout << ans;
}