#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll n;
	cin >> n;
	ll s = 0;
	for (ll x, i = 0; i < n; ++i)
		cin >> x, s += x;

	ll l = (s - n * (n-1) / 2) / n + 1;
	s = l * n + n * (n-1) / 2 - s;
	for (int i = 0; i < n; ++i)
		cout << l + i - (n-i <= s) << " \n"[i+1==n];

	return 0;
}