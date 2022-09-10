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


int main()
{
	string s;
	cin >> s;

	int ans = -1;
	int curr = 0;
	FOR(i, 0, s.size() - 1)
		if (s[i] == 'V' && s[i + 1] == 'K')
			curr++;
	ans = max(ans, curr);

	FOR(i, 0, s.size())
	{
		if (s[i] == 'V') s[i] = 'K';
		else s[i] = 'V';

		int curr = 0;
		FOR(i, 0, s.size() - 1)
			if (s[i] == 'V' && s[i + 1] == 'K')
				curr++;
		ans = max(ans, curr);

		if (s[i] == 'V') s[i] = 'K';
		else s[i] = 'V';
	}


	cout << ans;
	return 0;
}