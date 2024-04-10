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
#define MAXN 100001

int ff(pll a, pll b)
{
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int f; cin >> f;

	vll k(n), l(n);
	FOR(i, 0, n)
		cin >> k[i] >> l[i];

	ll ans = 0;
	vll can(n);
	FOR(i, 0, n)
		can[i] = min(k[i], l[i]);

	vll may(n);
	FOR(i, 0, n)
		may[i] = min(2 * k[i], l[i]);

	vpll diff(n);
	FOR(i, 0, n)
		diff[i] = MP(may[i] - can[i], i);

	sort(ALL(diff), ff);

	vch marked;
	marked.assign(n, 0);
	FOR(i, 0, f)
	{
		marked[diff[i].second] = 1;
		ans += may[diff[i].second];
	}

	FOR(i, 0, n)
		if (marked[i] == 0)
			ans += can[i];
	cout << ans;
	return 0;
}