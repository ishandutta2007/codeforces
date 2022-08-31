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

const int N = 1e5 + 5;

int a[N][5], x[5] = {0}, s[5], ps[2][5], sum[2];
vector <pii> v[5];
vector <int> answers;

int get_score(int x, int y);
int prob_score(int pts, int t);

int main()
{
	int n, y = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		bool active = false;
		for (int j = 0; j < 5; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] != -1)
			{
				++x[j];
				active = true;
			}
		}

		if (active)
			++y;
	}

	for (int j = 0; j < 5; ++j)
		s[j] = get_score(x[j], y);

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			ps[i][j] = prob_score(s[j], a[i][j]);
			sum[i] += ps[i][j];
		}
	}

	if (sum[0] > sum[1])
	{
		cout << 0;
		return 0;
	}

	int mx = 40 * n;
	int req = sum[1] - sum[0] + 1;
	for (int i = 1; i <= mx; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (a[0][j] == -1 and a[1][j] == -1)
				continue;

			else if (a[0][j] == -1)
			{
				int nx = x[j], ny = y + i, ns = get_score(nx, ny);
				temp -= prob_score(ns - s[j], a[1][j]);
			}

			else if (a[1][j] == -1)
			{
				int nx = x[j], ny = y + i, ns = get_score(nx, ny);
				temp += prob_score(ns - s[j], a[0][j]);
			}

			else if (a[0][j] > a[1][j])
			{
				int nx = x[j] + i, ny = y + i, ns = get_score(nx, ny);
				temp += prob_score(ns - s[j], a[0][j]) - prob_score(ns - s[j], a[1][j]);
			}

			else
			{
				int nx = x[j], ny = y + i, ns = get_score(nx, ny);
				temp += prob_score(ns - s[j], a[0][j]) - prob_score(ns - s[j], a[1][j]);
			}
		}

		if (temp >= req)
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;

	// for (int j = 0; j < 5; ++j)
	// {
	// 	if (a[0][j] != -1)
	// 	{
	// 		if (a[1][j] == -1)
	// 		{
	// 			int cur = s[j] / 500;
	// 			for (int k = cur + 1; k <= 6; ++k)
	// 			{
	// 				int temp = x[j] * (1 << (k - 1)) - y;
	// 				v[j].pb({temp, prob_score(500 * k, a[0][j]) - prob_score(s[j], a[0][j])});
	// 				answers.pb(temp);
	// 			}
	// 		}

	// 		else if (a[0][j] < a[1][j])
	// 		{
	// 			int cur = s[j] / 500;
	// 			for (int k = cur + 1; k <= 6; ++k)
	// 			{
	// 				int temp = x[j] * (1 << (k - 1)) - y;
	// 				v[j].pb({temp, prob_score(500 * (k - cur), a[0][j]) - prob_score(500 * (k - cur), a[1][j])});
	// 				answers.pb(temp);
	// 			}
	// 		}

	// 		else
	// 		{
	// 			int cur = s[j] / 500;
	// 			for (int k = cur - 1; k >= 1; --k)
	// 			{
	// 				int temp = (y - (1 << k) * x[j]) / ((1 << k) - 1) + 1;
	// 				v[j].pb({temp, prob_score(500 * (k - cur), a[0][j]) - prob_score(500 * (k - cur), a[1][j])});
	// 				answers.pb(temp);
	// 			}
	// 		}
	// 	}
	// }

	// for (int j = 0; j < 5; ++j)
	// {
	// 	for (auto k : v[j])
	// 	{
	// 		cout << j << ' ' << k.first << ' ' << k.second << endl;
	// 	}
	// }

	// sort(answers.begin(), answers.end());
	// for (auto &i : answers)
	// {
	// 	int temp = 0;
	// 	for (int j = 0; j < 5; ++j)
	// 	{
	// 		int cur = 0;
	// 		for (auto &k : v[j])
	// 			if (k.first <= i)
	// 				cur = max(cur, k.second);

	// 		temp += cur;
	// 	}

	// 	if (temp >= req)
	// 	{
	// 		cout << i;
	// 		return 0;
	// 	}
	// }

	// cout << -1;
}

int get_score(int n, int y)
{
	if (2 * n > y)
		return 500;

	if (4 * n > y)
		return 1000;

	if (8 * n > y)
		return 1500;

	if (16 * n > y)
		return 2000;

	if (32 * n > y)
		return 2500;

	return 3000;
}

int prob_score(int pts, int t)
{
	if (t == -1)
		return 0;

	return pts - ((pts * t) / 250);
}