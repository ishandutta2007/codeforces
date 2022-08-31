/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5;

int ch[N];
bool seen[2*N] = {0};
string s[2*N];
map <string, int> m;
pair <pii, int> p[N];
set <int> later;

int main()
{
	int n;
	cin >> n;

	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		string s1, s2, t1, t2;
		cin >> s1 >> s2;

		t1 = s1.substr(0, 3);
		t2 = s1.substr(0, 2) + s2.substr(0, 1);
		if (m.find(t1) == m.end())
		{
			m[t1] = x;
			s[x++] = t1;
		}

		if (m.find(t2) == m.end())
		{
			m[t2] = x;
			s[x++] = t2;
		}

		p[i] = {{m[t1], m[t2]}, i};
	}

	sort(p, p + n);
	p[n] = {{2*N, 2*N}, N};
	int st = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (p[i].first.first != p[i - 1].first.first)
		{
			int en = i - 1;
			if (st == en)
				later.insert(st);
			else
			{
				for (int j = st; j <= en; ++j)
				{
					if (seen[p[j].first.second])
					{
						cout << "NO\n";
						return 0;
					}

					seen[p[j].first.second] = true;
					ch[p[j].second] = p[j].first.second;
				}
			}

			st = i;
		}
	}

	int ctr = 1;
	while (ctr and !later.empty())
	{
		ctr = 0;
		set <int> r;
		for (auto &i : later)
		{
			if (seen[p[i].first.first])
			{
				if (seen[p[i].first.second])
				{
					cout << "NO\n";
					return 0;
				}

				++ctr;
				seen[p[i].first.second] = true;
				ch[p[i].second] = p[i].first.second;
				r.insert(i);
			}

			else if (seen[p[i].first.second])
			{
				++ctr;
				seen[p[i].first.first] = true;
				ch[p[i].second] = p[i].first.first;
				r.insert(i);
			}
		}

		for (auto &i : r)
			later.erase(i);
	}

	for (auto &i : later)
		ch[p[i].second] = p[i].first.first;

	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << s[ch[i]] << endl;
	
}