#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
ll n, s;
bool ff(ll x)
{
	ll X = x;
	ll sum = 0;
	while(x)
	{
		sum += x % 10;
		x /= 10;
	}
	return X - sum >= s;
}
int main()
{	
	scanf("%lld %lld", &n, &s);
	ll lewo = 1;
	ll prawo = n;
	while(prawo > lewo)
	{
		ll mid = (lewo + prawo) / 2;
		if(ff(mid) == 1)
			prawo = mid;
		else
			lewo = mid + 1;
	}
	if(ff(lewo) == 0)
		cout << 0;
	else
		cout << n - lewo + 1;
	return 0;
}