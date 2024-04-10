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
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

ll power(ll n, ll to, ll modulo = mod)
{
	if (to == 0) return 1;
	if (to == 1) return n%modulo;
	int exp = 1;
	ll ans = n;
	while (2 * exp <= to)
	{
		ans *= ans;
		ans %= modulo;
		exp *= 2;
	}
	return ((ans*power(n, to - exp, modulo)) % modulo);
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int n, m;
	cin >> n >> m;

	vector<vi> g;
	vi h;
	FOR(i, 0, n)
	{
		h.assign(m, 0);
		FOR(j, 0, m)
			cin >> h[j];
		g.push_back(h);
	}

	int best = 5 * 100 * 1000;
	bool norm = true;
	int index = -1;
	vi ans_a, ans_b;
	FOR(a0, 0, g[0][0] + 1)
	{
		norm = true;
		vi b(n);
		FOR(i, 0, n)
		{
			b[i] = g[i][0] - a0;
			if (b[i] < 0)
				norm = false;
		}

		if (!norm)
			break;

		bool can = true;
		int curr = 0;

		vi a(m);
		a[0] = a0;

		FOR(i, 1, m)
		{
			a[i] = g[0][i] - b[0];
			if (a[i] < 0)
			{
				can = false;
				break;
			}
		}

		FOR(i, 0, n)
			FOR(j, 0, m)
			if (a[j] + b[i] != g[i][j])
				can = false;

		if (!can)
			continue;

		curr = 0;
		FOR(i, 0, m)
			curr += (a[i]);

		FOR(i, 0, n)
			curr += b[i];

		if (best > curr)
		{
			best = curr;
			index = a0;
			ans_a = a;
			ans_b = b;
		}		
	}

	if (index == -1)
		cout << -1;
	else
	{
		cout << best << endl;
		FOR(i, 0, m)
		{
			REPEAT(ans_a[i])
				cout << "col " << i + 1 << endl;
		}
		FOR(i, 0, n)
		{
			REPEAT(ans_b[i])
				cout << "row " << i + 1 << endl;
		}
	}
	return 0;
}