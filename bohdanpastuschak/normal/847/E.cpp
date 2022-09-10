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
#include <complex>

#define ld double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) (ll)((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(t) FOR(name_that_will_never_apper, 0, t)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvch vector<vch>
#define vvb vector<vb>
#define vs vector<string>
#define vss vector<vs>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define base complex<double>
#define PI 3.141592653589793
#define alphabet_size 26
	using namespace std;

#define mod 1000000007
#define INF (ll)1e18
#define MAXN 100001

int n;
vi ast;
vi pak;
vi a;
vi p;

bool can(int r)
{
	a = ast;
	p = pak;

	int curr = 0;
	int curr_p = 0;

	while (curr < a.size() && curr_p < p.size())
	{
		auto pos = p[curr_p];

		if (abs(pos - a[curr]) > r)
		{
			++curr_p;
			continue;			
		}

		if (pos <= a[curr])
		{
			while (curr < a.size() && abs(a[curr] - pos) <= r)
				++curr;

			++curr_p;
		}
		else
		{
			int x = pos - a[curr];
			int te = curr;
			int best = -1;
			while (curr < a.size() && a[curr] <= pos)
				curr++;

			while (curr < a.size() && a[curr] <= pos + r - 2 * x)
				curr++;

			best = max(best, curr);
			curr = te;
			while (curr < a.size() && a[curr] <= pos)
				curr++;

			while (curr < a.size() && 2*(a[curr] - pos) <= r - x)
				curr++;

			best = max(best, curr);
			curr = best;
			curr_p++;
		}
	}

	if (curr_p == p.size() && curr < a.size())
		return 0;
	else
		return 1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	int ans = 2e6;

	string s;
	cin >> n >> s;

	FOR(i, 0, n)
		if (s[i] == '*')
			ast.push_back(i);
		else
			if (s[i] == 'P')
				pak.push_back(i);

	int l = 0, r = 2e6, m;
	while (r - l > 1)
	{
		m = (l + r) / 2;
		if (can(m))
			r = m;
		else
			l = m;
	}

	if (can(l))
		ans = min(ans, l);
	else
		ans = min(ans, r);

	ast.clear();
	pak.clear();
	reverse(ALL(s));

	FOR(i, 0, n)
		if (s[i] == '*')
			ast.push_back(i);
		else
			if (s[i] == 'P')
				pak.push_back(i);

	l = 0, r = 2e6, m;
	while (r - l > 1)
	{
		m = (l + r) / 2;
		if (can(m))
			r = m;
		else
			l = m;
	}

	if (can(l))
		ans = min(ans, l);
	else
		ans = min(ans, r);

	cout << ans;
	return 0;
}