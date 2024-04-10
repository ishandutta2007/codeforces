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
//#define mod 1000000007
#define ld long double
#define infinity (ll)1e8+1
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
#define MAXN 50001

int main()
{
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);

	ll a, b;
	cin >> a >> b;

	ll k1 = 0;
	ll k2 = 0;
	ll k = 0;
	while (a >= k*k)
		k++;

	k1 = k;
	k = 0;
	while (b >= k*k + k)
		k++;
	k2 = k;

	if (k1 > k2)
		cout << "Valera";
	else
		cout << "Vladik";

	return 0;
}