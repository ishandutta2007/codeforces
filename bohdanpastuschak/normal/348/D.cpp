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
#define MAXN 3001
clock_t startTime;

int n;
int m;

char field[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll ways(pii s, pii f)
{
	FOR(i, 0, MAXN)
		FOR(j, 0, MAXN)
		dp[i][j] = 0;

	if (field[f.first][f.second] == '.')
		dp[f.first][f.second] = 1;
	else
		return 0;

	RFOR(i, f.first, 0)
		if (field[i][f.second] == '.')
			dp[i][f.second] = dp[i + 1][f.second];
		else
			dp[i][f.second] = 0;

	RFOR(i, f.second, 0)
		if (field[f.first][i] == '.')
			dp[f.first][i] = dp[f.first][i + 1];
		else
			dp[f.first][i] = 0;

	RFOR(i, f.first, s.first)
		RFOR(j, f.second, s.second)
		if (field[i][j] == '.')
			dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
		else
			dp[i][j] = 0;

	return dp[s.first][s.second]%mod;
}

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	cin >> n >> m;
	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> field[i][j];

	ll a = ways(MP(0, 1), MP(n - 2, m - 1)), b = ways(MP(1, 0), MP(n - 1, m - 2));
	ll c = ways(MP(0, 1), MP(n - 1, m - 2)), d = ways(MP(1, 0), MP(n - 2, m - 1));
	cout << ((a*b - c*d) % mod + mod) % mod;
	return 0;
}
//don't forget about MAXN, mod and infinity