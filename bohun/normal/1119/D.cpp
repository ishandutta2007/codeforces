#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
vector <ll> v, dif;
ll n, a, b;
ll pref[100005];
int main()
{
	scanf("%lld", &n);
	for(int i = 1; n >= i; ++i)
	{
		scanf("%lld", &a);
		v.pb(a);
	}
	sort(v.begin(), v.end());
	for(int i = 1; ss(v) > i; ++i)
		dif.pb(v[i] - v[i - 1]);
	sort(dif.begin(), dif.end());
	for(int i = 0; ss(dif) > i; ++i)
		pref[i] = (i > 0 ? pref[i - 1] : 0) + dif[i];
	pref[ss(dif)] = pref[ss(dif) - 1];
	int q;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%lld %lld", &a, &b);
		ll len = b - a + 1;
		ll ans = 0;
		int e = upper_bound(dif.begin(), dif.end(), len - 1) - dif.begin();
		if(e - 1 >= 0)
			ans += pref[e - 1];
		printf("%lld\n", ans + max(1LL * 0, (n - e) * len));	
	}
		
		
	
			
	return 0;
}