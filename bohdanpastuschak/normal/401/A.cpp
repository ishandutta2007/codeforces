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
const ll MAXN = 51;

ll p10[11];

ll s(ll p)
{
	if (p == 1)
		return 11;
	return 9 * p10[p - 1] * p + s(p - 1) + 1;
}

ll solve(ll n)
{
	if (n < 10)
		return n;
	ll res = 0;

	ll p;
	FOR(i, 1, 11)
		if (n < p10[i])
		{
			p = i - 1;
			break;
		}

	res += s(p);
	res += solve(n - p10[p]) + p10[p]*p;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	p10[0] = 1;
	FOR(i, 1, 11)
		p10[i] = 10 * p10[i - 1];

	ll n, x;
	cin >> n >> x;
	vll a(n);
	FOR(i, 0, n)
		cin >> a[i];
	ll s = 0;
	FOR(i, 0, n)
		s += a[i];

	s = abs(s);
	cout << ((s + x - 1) / x);
	return 0;
}