#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <memory.h>
#include <utility>
#include <cctype>
#include <complex>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;

#define ll long long
#define mod 1000000007
#define infinity (ll)1e8
#define epsilon 1e-4

#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pii pair<int,int>
#define MP make_pair
#define PB push_back

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(ll i = (b) - 1; i >= a; --i)
#define REPEAT(n) FOR(counter, 0, (n))

#define vec(a) vector<ll> a
#define vec(a, n) vector<ll> a(n)
#define newVectorRead(a, n) vec(a,n) FOR(i,0,n) cin>>a[i];
#define ALL(V) V.begin(), V.end()

int main()
{
	vector<vector<int>> a(5);
	int t;
	int ind1, ind2;
	FOR(i, 0, 5)
	{
		FOR(j, 0, 5)
		{
			cin >> t;
			if (t == 1)
			{
				ind1 = i;
				ind2 = j;
			}
			a[i].push_back(t);
		}
	}

	cout << abs(2 - ind1) + abs(2 - ind2);

	return 0;
}