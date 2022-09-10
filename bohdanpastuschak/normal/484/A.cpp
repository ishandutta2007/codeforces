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
const ll MAXN = 2001;

ll p2[63];

ll solve(ll l, ll r)
{
	if (l == r)
		return l;

	ll b = -1;
	FOR(i, 0, 61)
		if (p2[i] <= r)
			b = i;

	if (l >= p2[b])
	{
		return p2[b] + solve(l - p2[b], r - p2[b]);
	}
	else
	{
		if (r == p2[b + 1] - 1)
			return r;
		else
			return p2[b] - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	
	int n; cin >> n;
	ll l, r;
	p2[0] = 1;
	FOR(i, 1, 63)
		p2[i] = (p2[i - 1] << 1);
	REPEAT(n)
	{
		cin >> l >> r;
		cout << solve(l, r) << endl;
	}

	return 0; 
}