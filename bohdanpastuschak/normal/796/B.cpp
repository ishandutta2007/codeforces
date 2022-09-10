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
	vi h(m);
	FOR(i, 0, m)
		scanf("%d", &h[i]);
	
	vector<pii> uv(k);
	FOR(i, 0, k)
	{
		scanf("%d", &uv[i].first);
		scanf("%d", &uv[i].second);
	}

	int curr = 1;
	vector<bool> isOtv;
	isOtv.assign(n+1, false);
	FOR(i, 0, m)
		isOtv[h[i]] = true;

	FOR(i, 0, k)
	{
		if (isOtv[curr]) break;
		if (curr == uv[i].first)
		{
			curr = uv[i].second;
		}
		else if (curr == uv[i].second)
		{
			curr = uv[i].first;
		}
	}


	cout << curr;

	return 0;
}