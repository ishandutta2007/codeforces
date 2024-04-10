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

	int n;
	cin >> n;

	vll v(n);
	FOR(i, 0, n)
		cin >> v[i];

	auto u = v;
	sort(ALL(u));

	vll sum_v(n + 1);
	sum_v[0] = 0;
	FOR(i, 1, n + 1)
		sum_v[i] = sum_v[i - 1] + v[i - 1];

	vll sum_u(n + 1);
	sum_u[0] = 0;
	FOR(i, 1, n + 1)
		sum_u[i] = sum_u[i - 1] + u[i - 1];

	int m; cin >> m; int t, l, r;
	REPEAT(m)
	{
		cin >> t >> l >> r;
		if (t == 1)
		{
			cout << sum_v[r] - sum_v[l - 1] << endl;
		}
		else
		{
			cout << sum_u[r] - sum_u[l - 1] << endl;
		}


	}
	return 0;
}