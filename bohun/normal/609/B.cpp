#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[200005];
	for(int i = 1; n >= i; ++i)
	{
		int b;
		cin >> b;
		a[b]++;
	}
	ll ans = 0;
	for(int i = 1; m >= i; ++i)
	{
		ans += (ll) a[i] * (n - a[i]);
	}
	cout << ans / 2;
	
	return 0;
}