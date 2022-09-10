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
#define infinity (ll)1e18+1
#define PI 3.14159265358979
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>
#define MP make_pair
#define vi vector<ll>//int
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>

#define newVector(a, n) vi a(n)
#define readVector(a, n) newVector(a, n); FOR(i,0,n) scanf("%d", &a[i]);

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define MAXN 100001

vi a;
vi b;
int n;
int p;
vector<double> need;

bool can(double time)
{
	need.assign(n, 0);
	FOR(i, 0, n)
	{
		if (b[i] > (a[i] + 0.0)*time)
			need[i] = 0;
		else
			need[i] = ((a[i] + 0.0)*time - b[i] + 0.0) / (p + 0.0);
	}
	double t = 0;
	FOR(i, 0, n)
		t += need[i];

	if (t > time) return false;
	else return true;
}

double search(double from, double to)
{
	if (abs(to - from) < 0.0001)
		return to;
	if (can(to)) return to;
	double mid = (from + to) / 2;
	if (can(mid))
		return search(mid, to);
	else
		return search(from, mid);
}

int main()
{
	cin >> n;
	cin >> p;
	a.assign(n, 0);
	b.assign(n, 0);

	FOR(i, 0, n)
		scanf("%d %d", &a[i], &b[i]);

	ll s = 0;
	FOR(i, 0, n)
		s += a[i];

	if (s <= p)
	{
		cout << -1;
		return 0;
	}

	cout << search(0, 1e15);
	return 0;
}