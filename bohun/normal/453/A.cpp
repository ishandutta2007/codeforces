#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m;
long double ans = 0;
long double pot(long double a, int b)
{
	long double r = 1.0;
	while(b)
	{
		if(b & 1)
			r = (ld) r * a ;
		a = (ld) a * a;
		b /= 2;
	}
	return r;
}
int main()
{
	cin >> m >> n;
	for(int i = 1; m >= i; ++i)
		ans += (pot((ld) i / m, n) - pot((ld) (i - 1) / (m), n)) * i;
	printf("%.10Lf", ans); 
	return 0;
}