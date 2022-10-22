#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
ll t[505];
map <ll, int> m, m2;
ll liczba[505];
bool done[505];
vector <ll> v[505];
const int mod = 998244353;
ll daj(ll a, int b)
{
	ll ans = 1;
	for(int i = 1; b >= i; ++i)
		ans *= a;
	return ans;
}
bool jest(int id, ll val)
{
	for(auto it: v[id])
		if(it == val)
			return 1;
	return 0;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
		scanf("%lld", &t[i]);
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 4; j >= 2; --j)
			{
				if(done[i])
					break;
				ll X = pow(t[i], 1.0 / j);
				for(int k = X - 5; X + 5 >= k; ++k)
				{
					if(k <= 0)
						continue;
					if(daj(k, j) == t[i])
					{
						done[i] = 1;
						m[k] += j;
						liczba[i] = k;
						break;
					}
				}
			}
	}
	for(int i = 1; n >= i; ++i)
	{
		if(done[i] == 0)
		{
			for(int j = 1; n >= j; ++j)
			{
				if(i == j)
					continue;
				ll d = __gcd(t[i], t[j]);
				if(d != t[i] && jest(i, d) == 0 and d > 1)
				{
					v[i].pb(d);
					v[i].pb(t[i] / d);
					m[d]++;
					m[t[i] / d]++;
				}
			}
		}
	}
	ll res = 1;
	for(auto it: m)
		res = (ll) res * (it.se + 1) % mod;
	for(int i = 1; n >= i; ++i)
	{
		if(ss(v[i]) == 0 && done[i] == 0)
			m2[t[i]]++;
	}
	for(auto it: m2)
		res = (ll) res * (it.se + 1) * (it.se + 1) % mod;
	cout << res;
	
		
	return 0;
}