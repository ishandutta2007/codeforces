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
/*
bool can(double d)
{
	FOR(i, 0, n)
	{

	}


}

double findInRange(double l, double r)
{
	double mid = (l + r) / 2;
	if (can(mid)) return mid;
	if (abs(l - r) < epsilon) return l;

	if (can(mid))
	{
		return findInRange(l, mid);
	}
	else
	{
		return findInRange(mid, r);
	}
}
*/

int main()
{
	ll n, l;
	cin >> n >> l;

	newVecRead(a, n);
	sortVec(a);
	if (n == 1)
	{
		cout << max(a[0], l - a[0]);
		return 0;
	}

	double d = a[0];
	if (d < l - a[n - 1]) d = l - a[n - 1];
	FOR(i, 0, n - 1)
	{
		if ((a[i + 1] - a[i])/2.0 > d)
			d = (a[i + 1] - a[i])/2.0;
		
	}
	cout << fixed << setprecision(9) << d;
	return 0;
}