#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;



int main()
{
	ll hp, n;
	int t[200005];
	ll mini[200005]; 
	scanf("%lld %lld", &hp, &n);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	mini[0] = 1e18;
	ll sum = 0;
	for(int i = 1; n >= i; ++i)
		{
			mini[i] = min(mini[i - 1], sum + t[i]);
			sum += t[i];
		}
	if(sum >= 0 and hp + mini[n] > 0)
		{
			cout << -1;
			return 0;
		}
	ll ans = 0;
	if(sum != 0)
	{
		ll xd = (hp + mini[n]) / -sum;
		if(xd > 5 and hp + mini[n] > 0)
		{
			ans += (ll)(xd - 3)* n;
			hp += (ll)(xd - 3) * sum;
		}
	}	
	int j = 1;
	while(hp > 0)
	{
		hp += t[j];
		j++;
		ans++;
		if(j == n + 1)
			j = 1;
	}
	cout << ans;
	return 0;
}