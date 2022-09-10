#define _CRT_NO_WARNINGS
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
	ios_base::sync_with_stdio(false);
	//ifstream in("In.txt");

	vi l(4), p(4), s(4), r(4);
	FOR(i, 0, 4)
		cin >> l[i] >> s[i] >> r[i] >> p[i];

	bool can = false;
	FOR(i, 0, 4)
		if ((l[i] == 1 || s[i] == 1 || r[i] == 1) && p[i] == 1)
			can = true;

	if (p[0] == 1)
	{
		if (l[1] == 1)
			can = true;
		if (s[2] == 1)
			can = true;
		if (r[3] == 1)
			can = true;
	}

	if (p[1] == 1)
	{
		if (l[2] == 1)
			can = true;
		if (s[3] == 1)
			can = true;
		if (r[0] == 1)
			can = true;
	}

	if (p[2] == 1)
	{
		if (l[3] == 1)
			can = true;
		if (s[0] == 1)
			can = true;
		if (r[1] == 1)
			can = true;
	}

	if (p[3] == 1)
	{
		if (l[0] == 1)
			can = true;
		if (s[1] == 1)
			can = true;
		if (r[2] == 1)
			can = true;
	}

	if (can)
		cout << "YES";
	else
		cout << "NO";
	

	






	return 0;
}