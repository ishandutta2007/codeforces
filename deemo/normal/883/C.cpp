
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

ll solve(ll f, ll tot, ll t0, ll a1, ll t1, ll p1, ll a2, ll t2, ll p2){
	long long res = 1e18 + 1;
	for(int i = 0; i <= (tot + t2 - 1)/t2; i++)
	{
		ll k = min(i * a2, f);
		ll x = f - k;
		ll t = tot - k * t2;
		if(t < 0)
			continue;
		ll p = p2 * i;
		if(x <= 0)
		{
			if(t >= 0)
				res = min(res, p);
			continue;
		}
		ll a = x;
		if(t1 < t0)
			if(t < x * t1)
				continue;
			else
				a = (t - x * t1)/(t0 - t1);
		a = min(a, x);
		t -= a * t0 + (x - a) * t1;
		p += (x - a + a1 - 1)/a1 * p1;
		if(t >= 0)
			res = min(res, p);
	}
	return res;
}

int main()
{
	ll f, tot, t0, a1, t1, p1, a2, t2, p2;
	cin >> f >> tot >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	ll res = min(solve(f, tot, t0, a1, t1, p1, a2, t2, p2), solve(f, tot, t0, a2, t2, p2, a1, t1, p1));
	if(res < 1e18)
		cout << res << endl;
	else
		cout << "-1\n";
	return 0;
}