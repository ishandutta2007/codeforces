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


int main()
{
	int n;
	cin >> n;
	vector<string> s(n);
	FOR(i, 0, n)
		cin >> s[i];

	vector<vector<string>> canBe(n);
	string b;
	FOR(i, 0, n)
	{
		canBe[i].push_back(s[i]);
		FOR(j, 0, s[i].size() - 1)
		{
			b = "";
			FOR(k, 1, canBe[i][j].size())
				b += canBe[i][j][k];
			b += canBe[i][j][0];
			canBe[i].push_back(b);
		}
	}

	int numInOne = s[0].size();
	int ans = 100000;
	FOR(i, 0, canBe[0].size())//po mozhlyvyh
	{
		int curr = 0;
		bool can = true;
		FOR(str, 0, n)//po pochatkovyh
		{
			int index = -1;
			FOR(j,0,numInOne)//po perestanovkah
				if (canBe[str][j] == canBe[0][i])
				{
					index = j;
					break;
				}

			if (index == -1) can = false;
			else
			{
				curr += index;
			}
		}

		if (can)
		{
			ans = min(ans, curr);
		}
	}

	if (ans >= 100000)
		cout << -1;
	else
		cout << ans;
	return 0;
}