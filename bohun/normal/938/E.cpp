#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
const int nax = 1e6 + 5;
int t[nax];
int n;
ll ans = 0;
const int mod = 1e9 + 7;
int sil = 1;
int potmod(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return res;
} 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 2; n >= i; ++i)
		sil = 1ll * sil * i % mod;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
	}
	sort(t + 1, t + n + 1);
	int w = 0;
	for(int i = n; i >= 1; --i)
	{
		int ile = 1;
		while(t[i] == t[i-1] and i > 1)
			{
				i--;
				ile++;
			}
		if(t[i] == t[n])
			{
				w += ile;
				continue;
			}
		ans = (ans + (ll)sil * ile % mod * potmod(ile + w, mod - 2) % mod * t[i] % mod) % mod;
		w += ile;
	}
	cout << ans;
		
	
}