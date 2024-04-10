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
#define mod 1000000009
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
#define vld vector<ld>
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int n; cin >> n;
	vll a(n);
	FOR(i, 0, n)
		cin >> a[i];

	int m; cin >> m;
	vpll lr(m);
	FOR(i, 0, m)
		cin >> lr[i].first >> lr[i].second;


	if (m == 0)
	{
		cout << -1;
		return 0;
	}
	ll sum = 0;
	FOR(i, 0, n)
		sum += a[i];

	if (sum > lr[m - 1].second)
		cout << -1;
	else
	{
		FOR(i,0,m)
			if (lr[i].second >= sum)
			{
				cout << max(sum, lr[i].first);
				return 0;
			}
	}

	return 0;
}