/*
Hanit Banga
Problem: 
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

struct group
{
	bool isPal;
	priority_queue <int> forw, back;
}g[N];

int a[N];
string s[N], t[N];
map <string, int> m;

int main()
{
	int k, n, groups = 0;
	cin >> k >> n;

	for (int i = 0; i < k; ++i)
	{
		cin >> s[i] >> a[i];
		t[i] = s[i];
		reverse(t[i].begin(), t[i].end());

		if (m.find(s[i]) != m.end())
		{
			int temp = m[s[i]];
			g[temp].forw.push(a[i]);
		}

		else if (m.find(t[i]) != m.end())
		{
			int temp = m[t[i]];
			g[temp].back.push(a[i]);
		}

		else
		{
			m[s[i]] = groups;

			if (s[i] == t[i])
				g[groups].isPal = true;

			else
				g[groups].isPal = false;

			g[groups].forw.push(a[i]);
			++groups;
		}
	}

	ll ans = 0;
	int centreBest = 0;

	for (int i = 0; i < groups; ++i)
	{
		if (!g[i].isPal)
		{
			while (!g[i].forw.empty() and !g[i].back.empty())
			{
				if (g[i].forw.top() + g[i].back.top() >= 0)
				{
					ans += g[i].forw.top() + g[i].back.top();
					g[i].forw.pop();
					g[i].back.pop();
				}

				else
					break;
			}
		}

		else
		{
			while (!g[i].forw.empty())
			{
				if (g[i].forw.size() == 1)
				{
					centreBest = max(centreBest, g[i].forw.top());
					break;
				}

				int x = g[i].forw.top();
				g[i].forw.pop();
				int y = g[i].forw.top();
				g[i].forw.pop();

				if (x + y >= 0)
				{
					ans += x+y;
					centreBest = max(centreBest, -y);
				}

				else
				{
					centreBest = max(centreBest, x);
					break;
				}
			}
		}
	}

	cout << ans+centreBest;
}