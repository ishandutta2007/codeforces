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
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

ll diff(ll n)
{
	ll t = n;
	ll s = 0;
	while (t != 0)
	{
		s += t % 10;
		t /= 10;
	}
	return n - s;
}

ll search(ll l, ll r, ll s)
{
	if (diff(l) >= s)
		return l;
	if (l == r)
		return l;
	if (r - l == 1)
		if (diff(l) >= s)
			return l;
		else
			return r;

	ll mid = (l + r) / 2;
	if (diff(mid) >= s)
		return search(l, mid, s);
	return search(mid, r, s);
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	ll n, s;
	cin >> n >> s;


	ll first;
	if (diff(n) < s)
	{
		cout << 0;
		return 0;
	}

	ll f =  search(10, n, s);
	cout << n - f + 1;
	return 0;
}