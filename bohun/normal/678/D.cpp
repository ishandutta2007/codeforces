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
const int nax = 100005, mod = 1e9 + 7;
const ll inf = 1e18;
ll pt(ll a, ll b)
{
	ll res = 1; while(b){ if(b & 1){res = (ll) res * a % mod;} a = (ll) a * a % mod; b /= 2;} return res;
}	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll a, b, n, x;
	cin >> a >> b >> n >> x;
	a %= mod;
	b %= mod;
	x %= mod;
	ll ans = 0;
	ans += (ll) pt(a, n) * x % mod;
	if(a == 1)
	{
		ans += b * (n % mod) % mod;
	}
	else
	ans += (ll) ((pt(a, n) - 1) % mod) * (pt(a - 1, mod - 2) % mod) % mod * b % mod;
	cout << ans % mod;
	
	
			
	
		
		
    return 0;
}