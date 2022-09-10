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

#define mod 1000000007
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define ll long long
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<ll>//int
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>

#define newVector(a, n) vi a(n)
#define readVector(a, n) newVector(a, n); FOR(i,0,n) cin>>a[i];

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define MAXN 1000001

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	if (a%b == 0) return b;
	if (a < b) swap(a, b);
	return gcd(b, a%b);
}

ll gcdArr(vi a)
{
	ll res = a[0];
	FOR(i, 1, a.size())
		res = gcd(res, a[i]);
	return res;
}

int main()
{
	int n;
	cin >> n;

	readVector(a, n);

	if (gcdArr(a) > 1)
	{
		cout << "YES" << endl << 0;
		return 0;
	}

	//gcd must be 2

	FOR(i, 0, n)
		a[i] = a[i] % 2;

	int ind = 0;
	int pairs = 0;
	while (ind < n - 1)
	{
		if (a[ind] == 1 && a[ind + 1] == 1)
		{
			a[ind] = 0;
			a[ind + 1] = 0;
			++pairs;
			ind += 2;
		}
		else
			ind++;
	}

	int now = 0;
	FOR(i, 0, n)
		if (a[i] == 1)
			now++;

	cout << "YES"<<endl<<(2 * now + pairs);
	return 0;
}