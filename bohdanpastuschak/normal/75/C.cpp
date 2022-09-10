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

ll gcd(ll a, ll b)
{
	if (a == b) return a;
	if (a == 1 || b == 1) return 1;
	return gcd(max(a, b) % min(a, b), min(a, b));
}

set<ll> divisors(ll a)
{
	set<ll> v;
	for (int i = 1; i*i <= a; ++i)
	{
		if (a%i == 0)
		{
			v.insert(i);
			v.insert(a / i);
		}
	}
	return v;
}

int main()
{
	ll a, b;
	cin >> a >> b;
	ll n;
	cin >> n;
	
	set<ll> divA = divisors(a);
	set<ll> divB = divisors(b);

	vector<ll> ans;
	ll low, high;
	FOR(i, 0, n)
	{
		cin >> low >> high;
		ll d =-1;

		for (auto bdivisor : divB)
		{
			if (bdivisor >= low && bdivisor <= high && divA.find(bdivisor) != divA.end())
			{
				d = max(d,bdivisor);
			}
		}		

		ans.push_back(d);
	}

	FOR(i, 0, ans.size())
		cout << ans[i] << endl;

	return 0;
}