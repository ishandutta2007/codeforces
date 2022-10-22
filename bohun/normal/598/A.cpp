#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll ans = (ll) n * (n + 1) / 2;
		int pot = 1;
		while(pot <= n)
		{
			ans -= 2 * pot;
			pot *= 2;
		}
		cout << ans << endl;
	}
	
	
	return 0;
}