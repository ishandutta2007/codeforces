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
#define pii pair<ll, ll>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) (ll)((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(t) FOR(name_that_will_never_apper, 0, t)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define vi vector<ll>
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
using namespace std;
#define mod 1000000007
#define INF (ll)1e18
#define MAXN 2001

ll check(ll a, ll b)
{
	if (a == b)
		return 2;

	if (a == 1 && b == 3)
		return 1;
	
	if (a == 1 && b == 2)
		return 0;

	if (a == 2 && b == 1)
		return 1;

	if (a == 2 && b == 3)
		return 0;

	if (a == 3 && b == 1)
		return 0;

	if (a == 3 && b == 2)
		return 1;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	ll k, al, bo;
	cin >> k >> al >> bo;

	vvll a(4, vll(4)), b(4, vll(4));
	FOR(i, 0, 3)
		FOR(j, 0, 3)
		cin >> a[i+1][j+1];

	FOR(i, 0, 3)
		FOR(j, 0, 3)
		cin >> b[i+1][j+1];



	ll res1 = 0, res2 = 0;

	set<pii> bulo;
	pii start = MP(al, bo);
	pii curr;
	pii cycle_start;

	map<pii, ll> pos;
	ll length;

	FOR(i,0,243)
	{
		curr = MP(a[al][bo], b[al][bo]);
		if (!has(curr, bulo))
		{
			bulo.insert(curr);
			al = curr.X;
			bo = curr.Y;
			pos[curr] = i;
		}
		else
		{
			cycle_start = curr;
			length = i - pos[curr];
			break;
		}
	}

	curr = start;

	al = start.X;
	bo = start.Y;
	while (curr != cycle_start && k > 0)
	{
		al = curr.X;
		bo = curr.Y;
		ll game = check(al, bo);
		if (game == 0)
			res1++;
		else
			if (game == 1)
				res2++;

		--k;
		curr = MP(a[al][bo], b[al][bo]);
	}

	if (k)
	{
		ll x, y;
		x = k / length;
		y = k % length;

		curr = cycle_start;
		al = curr.X;
		bo = curr.Y;

		bool first = 1;
		while (first || (curr != cycle_start))
		{
			al = curr.X;
			bo = curr.Y;

			first = 0;

			ll game = check(al, bo);
			if (game == 0)
				res1 += x;
			else
				if (game == 1)
					res2 += x;

			curr = MP(a[al][bo], b[al][bo]);
		}

		curr = cycle_start;
		REPEAT(y)
		{
			al = curr.X;
			bo = curr.Y;

			first = 0;

			ll game = check(al, bo);
			if (game == 0)
				res1++;
			else
				if (game == 1)
					res2++;

			curr = MP(a[al][bo], b[al][bo]);			
		}
	}

	cout << res2 << " " << res1;
	return 0;
}