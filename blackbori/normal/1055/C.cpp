#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l1, r1, l2, r2, t1, t2, g;
ll ans;

ll gcd(ll a, ll b)
{
	for(; a; swap(a, b)) b %= a;
	
	return b;
}

ll intv(ll x1, ll y1, ll x2, ll y2)
{
	return max(0ll, min(y1, y2) - max(x1, x2) + 1);
}

int main()
{
	ll s, k;
	
	scanf("%lld%lld%lld", &l1, &r1, &t1);
	scanf("%lld%lld%lld", &l2, &r2, &t2);
	
	g = gcd(t1, t2);
	
	r1 -= l1; l2 -= l1; r2 -= l1; l1 = 0;
	
	s = l2 / g;
	for(k=s-10; k<=s+10; k++){
		ans = max(ans, intv(l1, r1, l2 - g * k, r2 - g * k));
	}
	
	l1 -= r1; l2 -= r1; r2 -= r1; r1 = 0;
	
	s = r2 / g;
	for(k=s-10; k<=s+10; k++){
		ans = max(ans, intv(l1, r1, l2 - g * k, r2 - g * k));
	}
	
	printf("%lld\n", ans);
	
	return 0;
}