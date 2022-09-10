#define _CRT_NO_WARNINGS
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

#define pdd pair<double,double>
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
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001


int n, m;
vector<vch> f;
int lastRow;

int state[16][2];

ll solve(int curr, bool left)
{
	if (state[curr][left] >= 0)
		return state[curr][left];
	if (curr < 0)
		return 0;

	if (curr == lastRow)
	{
		if (left)
		{
			ll mVids;
			FOR(j, 1, m + 1)
				if (f[curr][j] == '1')
					mVids = j;
			state[curr][left] = mVids;
			return mVids;
		}
		else
		{
			ll mVids;
			FOR(j, 1, m + 1)
				if (f[curr][j] == '1')
				{
					mVids = j;
					break;
				}
			state[curr][left] = m + 1 - mVids;
			return m + 1 - mVids;
		}
	}

	bool is = false;
	FOR(i, 1, m + 1)
		if (f[curr][i] == '1')
			is = true;

	if (!is)
	{
		state[curr][left] = 1 + solve(curr - 1, left);
		return state[curr][left];
	}

	ll l1;
	if (state[curr - 1][1] == -1)
		solve(curr - 1, true);
	l1 = state[curr - 1][1];

	ll l2;
	if (state[curr - 1][0] == -1)
		solve(curr - 1, false);
	l2 = state[curr - 1][0];

	if (left)
	{
		ll mVids;
		FOR(j, 1, m + 1)
			if (f[curr][j] == '1')
				mVids = j;

		state[curr][left] = min(l1 + 1 + 2 * mVids, l2 + m + 2);
		return state[curr][left];
	}
	else
	{
		ll mVids;
		FOR(j, 1, m + 1)
			if (f[curr][j] == '1')
			{
				mVids = m + 1 - j;
				break;
			}

		state[curr][left] = min(l1 + m + 2, l2 + 2 *mVids + 1);
		return state[curr][left];
	}
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);
	//ifstream in("In.txt");
	
	cin >> n >> m;
	FOR(i, 0, n)
	{
		vch v;
		v.assign(m + 2, 0);
		FOR(j, 0, m + 2)
			cin >> v[j];

		f.push_back(v);
	}

	lastRow = -1;
	FOR(i, 0, n)
	{
		FOR(j, 1, m + 1)
			if (f[i][j] == '1')
			{
				lastRow = i;
				break;
			}
		if (lastRow != -1)
			break;
	}


	FOR(i, 0, 16)
		state[i][0] = -1, state[i][1] = -1;

	if (lastRow == -1)
	{
		cout << 0;
		return 0;
	}

	cout << solve(n - 1, true);
	return 0;
}