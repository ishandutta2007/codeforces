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
#define MAXN 101
clock_t startTime;

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int n;
	cin >> n;

	vi t(n), c(n);
	FOR(i, 0, n)
		cin >> t[i] >> c[i];

	ll curr = 0;
	FOR(i, 0, n)
	{
		if (curr <= t[i])
			curr = t[i];
		curr += c[i];
	}

	ll m = c[0];
	ll ye = c[0];
	int last = 0;
	FOR(i, t[0] + 1, t[n - 1] + 1)
	{
		if (ye > 0)
			--ye;

		if (t[last + 1] == i)
		{
			last++;
			ye += c[last];
		}

		m = max(m, ye);
	}

	cout << curr << " " << m;	
	return 0;
}
//don't forget about MAXN, mod and infinity