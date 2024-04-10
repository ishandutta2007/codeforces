#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;


const int nax = 1000005, mod = 1e9 + 7, pot = 17;


struct fen{
	ll t[nax];
	void add(int pos, int x)
	{
		for(int i = pos; nax > i; i += i & -i)
			t[i] = (t[i] + x) % mod;
	}
	ll daj(int x)
	{
		ll ans = 0;
		for(int i = x; i >= 1; i -= i & -i)
			ans = (ans + t[i]) % mod;
		return ans;
	}
	ll query(int l, int r)
	{
		return (daj(r) - daj(l - 1) + mod) % mod;
	}
};

vector <pair<int, int>> v;
int d[nax];
fen lewo, prawo;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> d[i];
		v.pb({d[i], i});
	}
	sort(v.begin(), v.end());
	
	ll res = 0;
	for(auto it: v)
	{
		lewo.add(it.se, it.se);
		prawo.add(it.se, n - it.se + 1);
		res = (res + (ll) (n - it.se + 1) * lewo.query(1, it.se) % mod * it.fi % mod) % mod;
		res = (res + (ll) it.se * prawo.query(it.se + 1, n) % mod * it.fi % mod) % mod;
	}
	cout << res;

    return 0;
}