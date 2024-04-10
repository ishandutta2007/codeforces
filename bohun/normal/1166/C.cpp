#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int inf = 1e9, nax = 500005;

int n, t[nax];
int d;
vector <int> dod, uj;
ll ans = 0;

map <ll, ll> m[2];

int daj(int x, int y)
{
	return ceil((double) x / y);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		if(t[i] >= 0)
			dod.pb(t[i]), m[0][t[i]]++;
		else
			uj.pb(-t[i]), m[1][-t[i]]++;
		
	}
	sort(dod.begin(), dod.end());
	sort(uj.begin(), uj.end());
	for(int i = 0; ss(dod) > i; ++i)
	{
		int poz = (upper_bound(dod.begin(), dod.end(), dod[i]) - dod.begin()) - (lower_bound(dod.begin(), dod.end(), daj(dod[i] , 2)) - dod.begin());
		ans += max(0, poz);
	}
	for(int i = 0; ss(uj) > i; ++i)
	{
		int poz = (upper_bound(uj.begin(), uj.end(), uj[i]) - uj.begin()) - (lower_bound(uj.begin(), uj.end(), daj(uj[i] , 2)) - uj.begin());
		ans += max(0, poz);
	}
	for(int i = 0; ss(uj) > i; ++i)
	{
		int poz = (upper_bound(dod.begin(), dod.end(), uj[i]) - dod.begin()) - (lower_bound(dod.begin(), dod.end(), daj(uj[i] , 2)) - dod.begin());
		ans += max(0, poz);
	}
	for(int i = 0; ss(dod) > i; ++i)
	{
		int poz = (upper_bound(uj.begin(), uj.end(), dod[i]) - uj.begin()) - (lower_bound(uj.begin(), uj.end(), daj(dod[i] , 2)) - uj.begin());
		ans += max(0, poz);
	}
	
	for(auto it: m[0])
		ans -= (it.se) * (it.se - 1 ) / 2;
	for(auto it: m[1])
		ans -= (it.se) * (it.se - 1 ) / 2;
	
	for(auto it: m[0])
	{
		ans -= it.se * (m[1][it.fi]);
	}
	
	cout << ans - n;
	
		
	
	
	
	
		
		
		
	
    return 0;
}