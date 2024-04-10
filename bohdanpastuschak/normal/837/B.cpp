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

const ll INF = 1e18;
const ll MAXN = 105;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	int m;
	cin >> n >> m;
	char f[MAXN][MAXN];
	FOR(i, 1, n + 1)
		FOR(j, 1, m + 1)
		cin >> f[i][j];

	bool hor = false;
	bool ver = false;

	if (n % 3 == 0)
	{
		char c1, c2, c3;
		c1 = f[1][1];
		c2 = f[n / 3 + 1][1];
		c3 = f[2 * n / 3 + 1][1];

		if (c1 == c2 || c1 == c3 || c2 == c3)
		{
			hor = false;
		}
		else
		{
			hor = true;
			FOR(i, 1, n / 3 + 1)
				FOR(j, 1, m + 1)
				if (f[i][j] != c1)
					hor = false;

			FOR(i, n/3 + 1, 2*n / 3 + 1)
				FOR(j, 1, m + 1)
				if (f[i][j] != c2)
					hor = false;

			FOR(i,2* n/3 + 1, n + 1)
				FOR(j, 1, m + 1)
				if (f[i][j] != c3)
					hor = false;

			if (hor)
			{
				cout << "YES";
				return 0;
			}

		}
	}


	if (m % 3 == 0)
	{
		char c1, c2, c3;
		c1 = f[1][1];
		c2 = f[1][1 + m/3];
		c3 = f[1][1 + 2*m/3];

		if (c1 == c2 || c1 == c3 || c2 == c3)
		{
			ver = false;
		}
		else
		{
			ver = true;
			FOR(i, 1, m / 3 + 1)
				FOR(j, 1, n + 1)
				if (f[j][i] != c1)
					ver = false;

			FOR(i, m / 3 + 1, 2 * m / 3 + 1)
				FOR(j, 1, n + 1)
				if (f[j][i] != c2)
					ver = false;

			FOR(i, 2 * m / 3 + 1, m + 1)
				FOR(j, 1, n + 1)
				if (f[j][i] != c3)
					ver = false;

			if (ver)
			{
				cout << "YES";
				return 0;
			}

		}
	}


	if (hor || ver)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
//don't forget about MAXN, mod and INF