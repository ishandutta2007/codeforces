#define _CRT_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int, int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 300001

ll power(ll n, ll to)
{
	if (to == 0) return 1;
	if (to == 1) return n;
	int exp = 1;
	ll ans = n;
	while (2 * exp <= to)
	{
		ans *= ans;
		ans %= mod;
		exp *= 2;
	}
	return ((ans*power(n, to - exp)) % mod);
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vll x(n);
	FOR(i, 0, n)
		cin >> x[i];

	sort(ALL(x));
	ll ans = 0;

	ll power[MAXN];
	power[0] = 1;
	FOR(i, 1, MAXN)
		power[i] = (2 * power[i - 1]) % mod;

	FOR(i, 0, n)
	{
		ans += x[i] * (power[i] - power[n - 1 - i]);
		ans %= mod;
	}

	cout << (ans%mod);
	return 0;
}