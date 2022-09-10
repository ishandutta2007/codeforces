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
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<ld,ld>
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

	/*ll x1, x2, y1, y2, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

	if (abs(x1 - x2) % x == 0 && abs(y1 - y2) % y == 0)
		cout << "YES";
	else
		cout << "NO";

	*/

	int n;
	cin >> n;

	vll a(n);
	FOR(i, 0, n)
		cin >> a[i];

	sort(ALL(a));
	
	ll ans = 0;
	if (a[0] == a[1])
	{
		if (a[0] == a[2])
		{
			ll x = 0;
			FOR(i, 0, n)
				if (a[i] == a[0])
					x++;
				else
					break;

			ans = x*(x - 1)*(x - 2) / 6;
		}
		else
		{
			ans = 1;
			FOR(i, 3, n)
				if (a[i] == a[2])
					ans++;
				else
					break;
		}
	}
	else
	{
		if (a[1] == a[2])
		{
			ll x = 0;
			FOR(i, 1, n)
				if (a[i] == a[1])
					x++;
				else
					break;

			ans = x*(x - 1) / 2;
		}
		else
		{
			ans = 1;
			FOR(i, 3, n)
				if (a[i] == a[2])
					ans++;
				else
					break;
		}
	}

	cout << ans;
	return 0;
}