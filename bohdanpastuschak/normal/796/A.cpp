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
#define infinity (ll)1e9+1
#define PI 3.14159265358979
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>
#define MP make_pair
#define vi vector<ll>
#define vpll vector<pll>

#define newVector(a, n) vi a(n)
#define readVector(a, n) newVector(a, n); FOR(i,0,n)cin>>a[i];

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

int main()
{
	//ifstream in("In.txt");

	int n, m, k; cin >> n >> m >> k;
	readVector(a, n);

	int vidd = 1000000;
	FOR(i, m, n)
	{
		if (a[i] > 0 && a[i] <= k)
		{
			vidd = i - m + 1;
			break;
		}
	}

	int vidd2 = 1000000;
	RFOR(i, m - 1, 0)
	{
		if (a[i] > 0 && a[i] <= k)
		{
			vidd2 = m - i -1;
			break;
		}
	}

	cout << 10 * min(vidd, vidd2);

	return 0;
}