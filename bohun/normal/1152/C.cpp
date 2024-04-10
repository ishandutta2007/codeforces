#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;
const int nax = 1005, inf = 1000000000, mod = 1e9 + 7;
ll a, b;
ll naj = 1e18;
ll k = -1;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	if(a > b)
		swap(a, b);
	ll n = b - a;
	k = 0;
	naj = (ll) a * b / __gcd(a, b);
	for(ll i = 1; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			ll r = i - a % i;
			if(naj > (a + r) *(b + r) / __gcd(a + r, b + r))
			{
				naj = (a + r) *(b + r) / __gcd(a + r, b + r);
				k = r;
			}
			r = ((n / i) - a % (n / i));
			if(naj > (a + r) * (b + r) / __gcd(a + r, b + r))
			{
				naj = (a + r) *(b + r) / __gcd(a + r, b + r);
				k = r;
			}
		}
	}
	cout << k;
		
	return 0;
}