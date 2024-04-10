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
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<ld,ld>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001
clock_t startTime;

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int k, n;
	cin >> k >> n;

	vll a(k);
	FOR(i, 0, k)
		cin >> a[i];

	vll b(n);
	FOR(i, 0, n)
		cin >> b[i];

	vll p(k);
	p[0] = a[0];

	FOR(i, 1, k)
		p[i] = p[i - 1] + a[i];
		

	/*ll n, k, p;
	cin >> n >> k >> p;

	vll a(n), b(k);
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, k)
		cin >> b[i];

	sort(ALL(a));
	sort(ALL(b));

	ll ans = 0;
	*/


	ll ans = 0;

	set<ll> ss;
	FOR(i, 0, k)//b[0] - in this time
	{
		ll start = b[0] - p[i];
		set<ll> sh_b;
		FOR(j, 1, n)
			sh_b.insert(b[j] - start);

		FOR(j, 0, k)
			sh_b.erase(p[j]);

		if (sh_b.size() == 0)
			ss.insert(start);
	}


	cout << ss.size();
	return 0;
}
//don't forget about MAXN, mod and infinity