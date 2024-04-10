#define _CRT_SECURE_NO_WARNINGS
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
#define ld long double
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define mod 1000000007
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<ll>//int
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define MAXN 1000001

ll power(ll n, ll to, ll modulo)
{
	if (to == 0) return 1;
	if (to == 1) return n%modulo;

	if (to % 2 == 1)
		return ((power(n, to - 1, modulo) * n)%modulo);
	else
	{
		ll b = power(n, to / 2, modulo);
		return ((b * b) % modulo);
	}
}

int main()
{
	int n; cin >> n;
	int k; cin >> k;
	vi a(n); FOR(i, 0, n)cin >> a[i];

	ll ans = 0;
	int m = a[0];
	int diff;
	FOR(i, 0, n)
		if (a[i] < m)
			m = a[i];

	FOR(i, 0, n)
	{
		if ((a[i] - m) % k != 0)
		{
			cout << -1;
			return 0;
		}
		else
			ans += (a[i] - m)/k;
	}
	cout << ans;

	return 0;
}