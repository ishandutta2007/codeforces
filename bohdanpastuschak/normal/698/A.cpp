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
#define MAXN 101
clock_t startTime;

int max(int a, int b, int c)
{
	if (a > b)
		return max(a, c);
	else
		return max(b, c);
}

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int n;
	cin >> n;
	vi a(n+1);
	FOR(i, 0, n)
		cin >> a[i+1];


	int dp[MAXN][3];
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	FOR(i, 1, n + 1)
	{
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		if (a[i] == 1 || a[i] == 3)
			dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
		else
			dp[i][1] = dp[i-1][1];
		if (a[i] == 2 || a[i] == 3)
			dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
		else
	    	dp[i][2] = dp[i-1][2];
	}

	cout << n - max(dp[n][0], max(dp[n][1], dp[n][2]));
	return 0;
}
//don't forget about MAXN, mod and infinity