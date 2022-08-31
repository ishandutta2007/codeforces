/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int a[N], b[N], c[N];
vector <int> ind[N];
vector <pii> pr;
bool rem[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		ind[a[i]].pb(i);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!ind[i].empty())
			pr.pb({-(*ind[i].rbegin()), i});
	}

	sort(pr.begin(), pr.end());

	int q;
	cin >> q;

	while (q--)
	{
		int k;
		cin >> k;

		int del = 0;

		for (int i = 0; i < k; ++i)
		{
			cin >> c[i];
			rem[c[i]] = true;
			del += ind[c[i]].size();
		}

		if (del == n)
		{

			for (int i = 0; i < k; ++i)
			rem[c[i]] = false;
			cout << "0 0\n";
			continue;
		}

		int winner;

		for (auto i : pr)
		{
			if (!rem[i.second])
			{
				winner = i.second;
				break;
			}
		}

		int m = ind[winner].size(), l = 1, r = m-1;

		while (l <= r)
		{
			int mid = (l+r)/2, total = ind[winner][mid] - ind[winner][mid-1] - 1, u = ind[winner][mid-1]+1, v = ind[winner][mid]-1;

			for (int i = 0; i < k; ++i)
			{
				if (!ind[c[i]].empty())
					total -= upper_bound(ind[c[i]].begin(), ind[c[i]].end(), v) - lower_bound(ind[c[i]].begin(), ind[c[i]].end(), u);
			}

			int totalRight;
			mid = (l+r)/2, totalRight = n - ind[winner][mid], u = ind[winner][mid]+1, v = n;

			for (int i = 0; i < k; ++i)
			{
				if (!ind[c[i]].empty())
					totalRight -= upper_bound(ind[c[i]].begin(), ind[c[i]].end(), v) - lower_bound(ind[c[i]].begin(), ind[c[i]].end(), u);
			}

			totalRight -= (m - mid - 1);

			if (totalRight > 0)
			{
				l = mid+1;
			}

			else if (total > 0)
			{
				l = mid+1;
				break;
			}

			else
			{
				r = mid-1;
			}
		}

		cout << winner << ' ' << b[ind[winner][l-1]] << endl;

		for (int i = 0; i < k; ++i)
			rem[c[i]] = false;
	}
}