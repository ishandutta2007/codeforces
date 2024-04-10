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
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

ll n, s;
vll a;

ll can(ll k)
{
	vll vart(n);
	FOR(i, 0, n)
		vart[i] = a[i] + k*(i + 1);
	sort(ALL(vart));
	ll res = 0;
	FOR(i, 0, k)
		res += vart[i];

	if (res > s)
		return -1;
	else
		return res;
}

ll bin(ll l, ll r)
{
	if (can(r) != -1) return r;
	if (l == r)
		return r;
	if (r - l == 1)
	{
		if (can(r) != -1)
			return r;
		else
			return l;
	}

	ll mid = (l + r) / 2;
	if (can(mid) != -1)
		return bin(mid, r);
	return bin(l, mid);
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);
	//ifstream in("In.txt");

	
	cin >> n >> s;
	a.assign(n, 0);
	FOR(i, 0, n)
		cin >> a[i];

	ll k, t;
	k = bin(0, n);
	t = can(k);
	cout << k << " " << t;
	return 0;
}