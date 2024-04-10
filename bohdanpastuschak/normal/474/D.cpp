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

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001
clock_t startTime;

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int t, k;
	cin >> t >> k;
	ll dp[MAXN];
	FOR(i, 0, k)
		dp[i] = 1;
	dp[k] = 2;
	FOR(i, k+1, MAXN)
	{
		dp[i] = dp[i - 1];
		if (i >= k)
			dp[i] += dp[i - k];
		dp[i] %= mod;
	}

	ll pref[MAXN];
	pref[0] = 0;
	FOR(i,1,MAXN)
		pref[i] = (pref[i - 1] + dp[i]) % mod;

	int a, b;
	REPEAT(t)
	{
		cin >> a >> b;
		cout << (pref[b] + mod - pref[a - 1]) % mod << endl;
	}

	return 0;
}
//don't forget about MAXN, mod and infinity