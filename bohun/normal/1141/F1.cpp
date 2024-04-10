#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;


int n;
int t[55];
int ans = 0;
vector < pair < int, int > > res, v;
ll pref[55];
void go(ll x)
{
	v.clear();
	int last = 0;
	int opt = 0;
	for(int i = 1; n >= i; ++i)
		{
			for(int j = last + 1; i >= j; ++j)
				{
					if(pref[i] - pref[j - 1] == x)
						{
							opt++;
							v.pb({j, i});
							last = i;
							break;
						}
				}
		}
	if(opt > ans)
		{
			ans = opt;
			res = v;
		}
}
int main()
{
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> t[i], pref[i] = pref[i - 1] + t[i];
	for(int i = 1; n >= i; ++i)
		{
			for(int j = i; n >= j; ++j)
				go(pref[j] - pref[i - 1]);
		}
	cout << ans << endl;
	for(auto it: res)
		cout << it.first << " " << it.second << endl;
	return 0;
}