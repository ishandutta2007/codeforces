	#include <bits/stdc++.h>
	#define ll long long 
	#define pb push_back
	#define ld long double
	#define ss(v) (int)v.size()
	#define fi first
	#define se second
	using namespace std;
	ll a, b;
	int main()
	{
		scanf("%lld %lld", &a, &b);
		vector <ll> div, A;
		ll n = a + b;
		ll c = a;
		for(ll i = 2; n >= i * i; ++i)
			{
				if(n % i == 0)
					{
						div.pb(i);
						div.pb((a + b) / i);
					}
			}
		if(n > 1)
			div.pb(n);
		for(ll i = 2; c >= i * i; ++i)
			{
				if(a % i == 0)
					{
						A.pb(i);
						if(i * i != a)
							A.pb(a / i);
					}
			}
		ll ans = 1e18;
		div.pb(1);
		div.pb(a + b);
		A.pb(1);
		A.pb(a);
		sort(A.begin(), A.end());
		for(auto it: div)
		{ 
			ll drugi = (a + b) / it;
			vector <ll> :: iterator i = upper_bound(A.begin(), A.end(), it);
			--i;
			if(i == A.end())
				continue;
			ll d = a / *i;
			if(d <= drugi)
				ans = min(ans, 2 * (it + drugi));
		}
		A.clear();
		c = b;
		for(ll i = 2; c >= i * i; ++i)
			{
				if(b % i == 0)
					{
						A.pb(i);
						if(i * i != b)
							A.pb(b / i);
					}
			}
		A.pb(1);
		A.pb(b);
		sort(A.begin(), A.end());
		for(auto it: div)
		{
			ll drugi = (a + b) / it;
			vector <ll> :: iterator i = upper_bound(A.begin(), A.end(), it);
			--i;
			if(i == A.end())
				continue;
			ll d = b / *i;
			if(d <= drugi)
				ans = min(ans, 2 * (it + drugi));
		}
		cout << ans;
		
				
		return 0;
	}