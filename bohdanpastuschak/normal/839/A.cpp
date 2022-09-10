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

#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rep0(i, n) for(ll i = (0); i < (n); i++)
#define repd(i,m,n) for(ll i=(m); i > (n); i--)
#define iter(el, arr) for(auto& el : arr)
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll,ll>
#define plli pair<pll,ll>
#define MP make_pair
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
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
using namespace std;

ll power(ll n, ll to, ll modulo = mod)
{
	ll res = 1;
	while (to) 
	{
		if (to & 1)
			res = (res*n) % modulo;
		n = (n*n) % modulo;
		to >>= 1;
	}

	return res;
}

const ll INF = 1e18;
const ll MAXN = 100001;

/*
int segment_tree[4 * MAXN];

void build_tree(vi a, int v, int tl, int tr) 
{
	if (tl == tr)
		segment_tree[v] = a[tl];
	else 
	{
		int tm = (tl + tr) / 2;
		build_tree(a, v * 2, tl, tm);
		build_tree(a, v * 2 + 1, tm + 1, tr);
		segment_tree[v] = segment_tree[v * 2] + segment_tree[v * 2 + 1];
	}
}

ll sum_tree(int v, int tl, int tr, int l, int r) 
{
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return segment_tree[v];
	int tm = (tl + tr) / 2;
	return 
		sum_tree(v * 2, tl, tm, l, min(r, tm)) + 
		sum_tree(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update_tree(int v, int tl, int tr, int pos, ll new_val) 
{
	if (tl == tr)
		segment_tree[v] = new_val;
	else 
	{
		int tm = (tl + tr) / 2;

		if (pos <= tm)
			update_tree(v * 2, tl, tm, pos, new_val);
		else
			update_tree(v * 2 + 1, tm + 1, tr, pos, new_val);

		segment_tree[v] = segment_tree[v * 2] + segment_tree[v * 2 + 1];
	}
}
*/

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n, k;
	cin >> n >> k;

	vll a(n);
	FOR(i, 0, n)
		cin >> a[i];

	int curr = 0;
	int dala = 0;
	int day = 0;
	int ye = 0;
	while (day < n)
	{
		ye += a[day];
		if (ye >= 8)
			dala += 8, ye -= 8;
		else
			dala += ye, ye = 0;
		if (dala >= k)
			break;
		++day;
	}



	if (dala < k)
		cout << -1;
	else
		cout << day + 1;


	return 0;
}