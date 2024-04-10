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
#include <stdio.h>

#define ld double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define SZ(a) (ll)((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REP(I, t) FOR(I,0,t)
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
#define base complex<ld>
#define PI 3.141592653589793
using namespace std;
#define mod 1000000007
#define INF (ll)1e9
#define MAXN 100007

void ok()
{
	cout << "YES";
	exit(0);
}

void bad()
{
	cout << "NO";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int p2[5];
	p2[0] = 1;
	FOR(i, 1, 5)
		p2[i] = 2 * p2[i - 1];

	ll n, k;
	cin >> n >> k;

	vvi a(n, vi(k, 0));
	FOR(i, 0, n)
		FOR(j, 0, k)
		cin >> a[i][j];

	int var = (1 << k);
	vi times(var, 0);

	int t;
	FOR(i, 0, n)
	{
		t = 0;
		FOR(j, 0, k)
			if (a[i][j] == 1)
				t += p2[j];

		times[t]++;
	}

	if (times[0])
		ok();

	if (times[var - 1] == n)
		bad();

	if (k == 2)
	{
		if (times[1] && times[2])
			ok();
		else
			bad();
	}

	if (k == 3)
	{
		if (times[1])
		{
			if (times[2] || times[4] || times[6])
				ok();
			else
				bad();				
		}
		else
		{
			if (times[2])
			{
				if (times[4] || times[5])
					ok();
				else
					bad();
			}
			else
			{
				if (times[4])
				{
					if (times[3])
						ok();
					else
						bad();
				}
				else
				{
					bad();
				}

			}
		}
	}

	if (times[1])
	{
		if (times[2] || times[4] || times[6] || times[8] || times[10] || times[12] || times[14])
			ok();
		else
			bad();
	}

	if (times[2])
	{
		if (times[4] || times[5] || times[8] || times[9] || times[12] || times[13])
			ok();
		else
			bad();
	}

	if (times[4])
	{
		if (times[3] || times[8] || times[9] || times[10] || times[11])
			ok();
		else
			bad();
	}

	if (times[8])
	{
		if (times[3] || times[5] || times[6] || times[7])
			ok();
		else
			bad();
	}

	if (times[3] && times[12])
		ok();

	if (times[5] && times[10])
		ok();

	if (times[6] && times[9])
		ok();

	bad();
	return 0;
}