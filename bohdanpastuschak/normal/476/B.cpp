#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) ll((a).size())
#define X first
#define Y second

#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
using namespace std;

const ll INF = 1e9;
const ll MAXN = 200001;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	string s1, s2;
	cin >> s1 >> s2;
	int a = 0;
	FOR(i, 0, s1.size())
		if (s1[i] == '+')
			a++;
		else
			a--;

	int b = 0;
	FOR(i, 0, s2.size())
		if (s2[i] == '+')
			b++;
		else
			if (s2[i] == '-')
				b--;


	int x = 0;
	FOR(i, 0, s2.size())
		if (s2[i] == '?')
			x++;

	int del = abs(a - b);

	if (del > x)
		cout << "0.00000";
	else
	{
		ld dp[41][11];
		dp[10][0] = 1.000;

		FOR(i, 0, 41)
			FOR(j, 0, 11)
			dp[i][j] = 0;

		dp[10][0] = 1.000;
		FOR(i,1,11)
			FOR(j, 0, 41)
		{
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) / 2.0;
		}

		cout << fixed<<setprecision(10)<< dp[10 + del][x];
	}

	return 0;
}