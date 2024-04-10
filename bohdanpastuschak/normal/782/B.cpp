#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); --i)

#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-6

ll n;
vector<double> x;
vector<double> v;

double time(double coord)
{
	double maxTime = -1;
	FOR(i, 0, n)
	{
		maxTime = max(maxTime, (abs(coord - x[i]) / v[i]));
	}

	return maxTime;
}

double solve(double l, double r)
{
	double mid = (l + r) / 2.0;
	if (r - l < epsilon) return time(l);
	double TimeB = time(mid + epsilon);
	double TimeL = time(mid - epsilon);
	double TimeMid = time(mid);

	if (TimeB > TimeMid)
	{
		if (TimeL > TimeMid)
			return TimeMid;
		else
			return solve(l, mid);
	}
	else
	{
		if (TimeL > TimeMid)
			return solve(mid, r);
		else
			return min(solve(l, mid), solve(mid, r));
	}	
}

int main()
{

	cin >> n;
	double temp;
	FOR(i, 0, n)
	{
		cin >> temp;
		x.push_back(temp);
	}
	FOR(i, 0, n)
	{
		cin >> temp;
		v.push_back(temp);
	}
	

	cout << fixed<<setprecision(7)<<solve(0, 1000000000);
	return 0;
}