#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
 
#define ll long long 
 
using namespace std;
 
ll g[1003];
ll d[1003];
ll f[1003];
int n1, n2, n3;
 
 
int main()
{
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1; i++)
		cin >> g[i];
	for (int i = 0; i < n2; i++)
		cin >> d[i];
	for (int i = 0; i < n3; i++)
		cin >> f[i];
 
	sort(g, g + n1);
	sort(d, d + n2);
	sort(f, f + n3);
 
	ll ans = 0;
 
	for (int i = 0; i < n1; i++)
	{
		ll mx = g[i] * 2;
		ll k1 = upper_bound(d, d + n2, mx) - upper_bound(d, d + n2, g[i]);
		ll k2 = upper_bound(f, f + n3, mx) - upper_bound(f, f + n3, g[i]);
 
		ans += k1*(k1 - 1) / 2 * k2*(k2 - 1)*(k2 - 2) / 6;
	}
 
	for (int i = 0; i < n2; i++)
	{
		ll mx = d[i] * 2;
		ll k1 = upper_bound(g, g + n1, mx) - upper_bound(g, g + n1, d[i]);
		ll k2 = upper_bound(d, d + n2, mx) - upper_bound(d, d + n2, d[i]);
		ll k3 = upper_bound(f, f + n3, mx) - upper_bound(f, f + n3, d[i]);
 
		ans += k1 * k2 * k3 * (k3 - 1)*(k3 - 2) / 6;
 
	}
 
	for (int i = 0; i < n3; i++)
	{
		ll mx = f[i] * 2;
		ll k1 = upper_bound(g, g + n1, mx) - upper_bound(g, g + n1, f[i]);
		ll k2 = upper_bound(d, d + n2, mx) - upper_bound(d, d + n2, f[i]);
		ll k3 = upper_bound(f, f + n3, mx) - upper_bound(f, f + n3, f[i]);
 
		ans += k1 * k2 * (k2 - 1) / 2 * k3*(k3 - 1) / 2;
 
	}
	cout << ans << endl;
}