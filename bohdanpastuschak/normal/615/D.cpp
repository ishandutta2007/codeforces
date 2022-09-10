#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); --i)
#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define pb push_back
#define pll pair<ll,ll>
#define infinity (ll)1e18
#define epsilon 1e-5


ll power(ll n, ll to)
{
	if (to == 0) return 1;
	if (to == 1) return n;

	ll res = n;
	ll exp = 1;
	while (2 * exp <= to)
	{
		res *= res;
		res %= mod;
		exp*=2;
	}

	return (res*power(n, to - exp)) % mod;
}

int main()
{
	ll m;
	cin >> m;
	newVecRead(p, m);

	sortVec(p);
	vector<pll> canonical;
	canonical.pb(pll(p[0], 1));
	FOR(i, 1, m)
	{
		if (p[i] == p[i - 1])canonical[canonical.size() - 1].second++;
		else
			canonical.push_back(pll(p[i], 1));
	}

	ll ans = 1;
	ll tau = 1;
	FOR(i, 0, canonical.size())
	{
		tau *= (canonical[i].second + 1);
		tau %= (2*mod - 2);;
	}

	FOR(i, 0, canonical.size())
	{
		ll x = (canonical[i].second * tau) / 2;
		x %= (mod - 1);
		ans *= power(canonical[i].first, x);
		ans %= mod;
	}

	cout << ans;
	return 0;
}