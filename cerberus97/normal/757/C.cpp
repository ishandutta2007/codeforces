/*
Hanit Banga
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, M = 1e6 + 5, mod = 1e9 + 7;

int group[M] = {0}, ctr[M] = {0};
ll fact[M];
vector <pair <pii, int>> temp;
map <int, int> mp;

int main()
{
	int n, m, g = 1;
	cin >> n >> m;

	fact[0] = 1;

	for (int i = 1; i < M; ++i)
		fact[i] = (i * fact[i-1]) % mod;

	for (int i = 0; i < n; ++i)
	{
		mp.clear();
		temp.clear();
		int x;
		cin >> x;

		for (int j = 0; j < x; ++j)
		{
			int y;
			cin >> y;
			mp[y]++;
		}

		for (auto &j : mp)
			temp.pb({{group[j.first], j.second}, j.first});

		sort(temp.begin(), temp.end());
		group[temp[0].second] = g;
		int sz = temp.size();

		for (int j = 1; j < sz; ++j)
		{
			if (temp[j].first != temp[j-1].first)
				++g;

			group[temp[j].second] = g;
		}

		++g;
	}

	for (int i = 1; i <= m; ++i)
		ctr[group[i]]++;
	
	ll ans = 1;

	for (int i = 0; i < M; ++i)
		ans = (ans * fact[ctr[i]]) % mod;

	cout << ans;
}