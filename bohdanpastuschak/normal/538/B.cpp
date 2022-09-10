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
const ll MAXN = 1000001;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	int n;
	cin >> n;

	vvi dp;
	vi t = { 1 };
	vi prev = { 1 };
	vi nex;
	FOR(i, 0, 7)
	{
		nex.clear();
		for (auto j : prev)
			nex.push_back(10 * j), nex.push_back(10 * j + 1);
		prev = nex;
		for (auto j : nex)
			t.push_back(j);
	}

	vi vvv;
	dp.assign(MAXN, vvv);

	dp[1] = { 1 };
	int best;
	FOR(i, 2, n + 1)
	{
		best = 0;
		FOR(j, 1, t.size())
			if (i >= t[j])
				if (dp[i - t[j]].size() < dp[i - t[best]].size())
					best = j;
		dp[i] = dp[i - t[best]];
		dp[i].push_back(t[best]);
	}

	cout << dp[n].size() << endl;
	iter(el, dp[n])
		cout << el << " ";
	return 0;
}