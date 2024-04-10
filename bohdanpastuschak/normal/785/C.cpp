#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
#include <functional>
#include <list>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mod 1000000007
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i>= (a); --i)

#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-6

ll ifMeq0(ll n)
{
	ll ss = sqrt(1 + (double)(8 * (double)n));
	if (ss*ss == 8 * n + 1)
		return (ss - 1) / 2;
	else
		return (ss - 1) / 2 + 1;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	if (n <= m)
	{
		cout << n;
		return 0;
	}
	cout << ifMeq0(n - m) + m;



	return 0;
}