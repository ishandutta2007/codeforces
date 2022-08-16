/*
Hanit Banga
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

const int N = 3e5 + 5;
const ll INF = 1e15;

ll a[N], b[N];
set <pll> events, start_points;

int main()
{
	fast_cin();
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		events.insert({a[i], i});
		events.insert({b[i]+1, -i});
	}

	int open = 0;
	ll best = 0, l = 0, r = 0;
	pll ans = {l, r}, cur_start;
	for (auto &i : events)
	{
		if (i.second < 0)
		{
			if (open >= k)
			{
				r = i.first;
				if (r - l > best) 
				{
					best = r - l;
					ans = {l, r};
				}
			}

			--open;
			pll dl = {a[-i.second], -i.second};
			if (dl <= cur_start and open >= k)
			{
				cur_start = *(start_points.upper_bound(cur_start));
				l = cur_start.first;
			}
			start_points.erase(dl);
		}

		else
		{
			++open;
			start_points.insert(i);
			if (open == k)
			{
				l = i.first;
				cur_start = i;
			}
		}
	}

	cout << best << '\n';
	int ctr = 0;

	for (int i = 1; ctr < k; ++i)
	{
		if (!best or (a[i] <= ans.first and b[i] >= ans.second-1))
		{
			++ctr;
			cout << i << ' ';
		}
	}
}