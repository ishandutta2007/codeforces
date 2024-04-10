#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
vector < int > val;
ll pref[1505];
vector < pair < int, int > > v[4000000], res;
map < int, int > m;
int main()
{
	int n, t[1505];
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> t[i], pref[i] = pref[i - 1] + t[i];
	for(int i = 1; n >= i; ++i)
		for(int j = i; n >= j; ++j)
			val.pb(pref[j] - pref[i - 1]);
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for(int i = 0; ss(val) > i; ++i)
		m[val[i]] = i;
	for(int i = 1; n >= i; ++i)
		for(int j = i; n >= j; ++j)
			{
				int val = pref[j] - pref[i - 1];
				v[m[val]].pb({j, i});
			}
	int ans = 0;
	for(int i = 0; 4000000 > i; ++i)
	{
		int opt = 0;
		vector < pair < int, int > > xd;
		sort(v[i].begin(), v[i].end());
		int last = 0;
		for(auto it: v[i])
			{
				if(it.second > last)
					{
						last = it.first;
						opt++;
						xd.pb({it.second, it.first});
					}
			}
		if(opt > ans)
			{
				ans = opt;
				res = xd;
			}
	}
	cout << ans << endl;
	for(auto it: res)
		cout << it.fi << " " << it.se << endl;
			
	return 0;
}