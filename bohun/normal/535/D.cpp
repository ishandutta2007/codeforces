#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 1000005, mod = 1e9 + 7;
const ll inf = 1e18;
int n, m;
string s, h;
int xx[nax];
const int p = 43;
int hasz = 0;
int last = -5;
int ok[nax];
int potmod(int a, int b)
{
	int res = 1; while(b){ if(b & 1){ res = (ll) res * a % mod;} a = (ll) a * a % mod; b /= 2;} return res;
}
void go(int x)
{
	int i = max(last, x);
	for(int j = i; x + ss(s) > j; ++j)
		h[j] = s[j - x], ok[j] = 1;
	last = x + ss(s) - 1;
}
int H[nax];
int P[nax];
int daj(int l, int r)
{
	return (H[r] - (l > 0 ? (ll) H[l - 1] * P[r - l + 1] % mod : 0 ) + mod) % mod;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; n >= i; ++i)
		h.pb('a');
	for(int i = 0; ss(s) > i; ++i)
	{
		hasz = ((ll) p * hasz + s[i] - 'a' + 1) % mod;
	}
	for(int i = 1; m >= i; ++i)
	{
		cin >> xx[i];
		--xx[i];
		go(xx[i]);
	}
	P[0] = 1;
	for(int i = 1; n >= i; ++i)
		P[i] = (ll) P[i - 1] * p % mod;
	for(int i = 0; n > i; ++i)
	{
		H[i] = (i > 0 ? ((ll) H[i - 1] * p + h[i] - 'a' + 1) % mod : h[i] - 'a' + 1);
	}
	for(int i = 1; m >= i; ++i)
	{
		if(daj(xx[i], xx[i] + ss(s) - 1) != hasz)
		{
			cout << 0;
			return 0;
		}
	}
	int ile = 0;
	for(int i = 0; n > i; ++i)
		ile += (ok[i] == 0);
	cout << potmod(26, ile);
						
							
						
		
		
    return 0;
}