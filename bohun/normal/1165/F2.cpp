#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 200005, mod = 998244353;
const ll inf = 1e18;

int n, m;
ll ile[nax];
vector <ll> v[nax];
ll mam[nax];
ll sum;

bool Fun(ll x)
{
	ll E = sum;
	for(int i = 1; n >= i; ++i)
		mam[i] = ile[i];
	ll wyd = 0;
	ll kasa = x;
	for(int i = min((ll) 200000, x); i >= 1; --i)
	{
		kasa = min(kasa, (ll) i);
		for(auto it: v[i])
		{
			if(mam[it] == 0 || kasa == 0)
				continue;
			int biore = min(kasa, mam[it]);
			mam[it] -= biore;
			E -= biore;
			kasa -= biore;
			wyd += biore;
		}	
	}
	if(x - wyd >= 2 * E)
		return 1;
	return 0;
}
	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		cin >> ile[i];
		sum += ile[i];
	}
	for(int i = 1; m >= i; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
	}
	ll lewo = 1;
	ll prawo = 1e15;
	while(prawo > lewo)
	{
		ll mid = (lewo + prawo) / 2;
		if(Fun(mid))
			prawo = mid;
		else
			lewo = mid + 1;
	}	
	cout << lewo;
		
	
	
	
	
		
		
		
	
    return 0;
}