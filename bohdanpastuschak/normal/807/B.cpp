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

#define infinity (ll)1e8+1
#define PI 3.14159265358979

#define ll long long
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

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

int main()
{
	ios_base::sync_with_stdio(false);
	
	int p, x, y;
	cin >> p >> x >> y;
	int BIG = 10000;
	bool can;
	FOR(usp, 0, BIG)
	{
		can = false;

		FOR(nu, 0, BIG)
			if (x + 100 * usp - 50 * nu >= y)
			{
				int t = x + 100 * usp - 50 * nu;
				t = (t / 50) % 475;
				REPEAT(25)
				{
					t = (t * 96 + 42) % 475;
					if (p == 26 + t)
					{
						can = true;
						break;
					}
				}
			}
			else
				break;


		if (can)
		{
			cout << usp;
			return 0;
		}
	}


	return 0;
}