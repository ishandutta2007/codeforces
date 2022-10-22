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

int n;
ll a[nax], b[nax];
ll ans = 0;
multiset <ll> s;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; n >= i; ++i)
		cin >> b[i];
	sort(b + 1, b + n + 1);
	for(ll i = 1; n >= i; ++i)
	{
		s.insert((ll) i * (n - i + 1) * a[i]);
	}
	for(ll i = 1; n >= i; ++i)
	{
		ans = (ans + (ll) b[i] * (*--s.end() % mod)) % mod;
		s.erase(--s.end());
	}
	cout << ans;
		
		
	
    return 0;
}