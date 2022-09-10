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
#define ld long double
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define mod 1000000007
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<ll>//int
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define MAXN 1000001

ll power(ll n, ll to, ll modulo)
{
	if (to == 0) return 1;
	if (to == 1) return n%modulo;

	if (to % 2 == 1)
		return ((power(n, to - 1, modulo) * n)%modulo);
	else
	{
		ll b = power(n, to / 2, modulo);
		return ((b * b) % modulo);
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> field;
	vector<char> rr;
	FOR(i, 0, n)
	{
		rr.assign(m, 0);
		FOR(j, 0, m)
			cin >> rr[j];
		field.push_back(rr);
	}

	//(i,j) -> m*i + j
	vector<pii> nearT, nearS;
	pii sss, ttt;

	FOR(i, 0, n)
		FOR(j, 0, m)
	{
		if (field[i][j] == 'S')
			sss = MP(i, j);
		if (field[i][j] == 'T')
			ttt = MP(i, j);
	}

	int s = sss.first * m + sss.second;
	int t = ttt.first * m + ttt.second;

	//T
	//left

	for (int i = ttt.second + 1; i < m; ++i)
		if (field[ttt.first][i] != '*')
			nearT.push_back(MP(ttt.first, i));
		else
			break;

	//right

	for (int i = ttt.second - 1; i >= 0; --i)
		if (field[ttt.first][i] != '*')
			nearT.push_back(MP(ttt.first, i));
		else 
			break;

	//up

	for (int i = ttt.first - 1; i >= 0; --i)
		if (field[i][ttt.second] != '*')
			nearT.push_back(MP(i, ttt.second));
		else
			break;

	//down

	for (int i = ttt.first + 1; i < n; ++i)
		if (field[i][ttt.second] != '*')
			nearT.push_back(MP(i, ttt.second));
		else
			break;

	//S

	//left

	for (int i = sss.second + 1; i < m; ++i)
		if (field[sss.first][i] != '*')
			nearS.push_back(MP(sss.first, i));
		else
			break;

	//right

	for (int i = sss.second - 1; i >= 0; --i)
		if (field[sss.first][i] != '*')
			nearS.push_back(MP(sss.first, i));
		else
			break;

	//up

	for (int i = sss.first - 1; i >= 0; --i)
		if (field[i][sss.second] != '*')
			nearS.push_back(MP(i, sss.second));
		else
			break;

	//down

	for (int i = sss.first + 1; i < n; ++i)
		if (field[i][sss.second] != '*')
			nearS.push_back(MP(i, sss.second));
		else
			break;


	for(auto i: nearT)
		if (field[i.first][i.second] == 'S')
		{
			cout << "YES";
			return 0;
		}

	bool ok = true;
	int m1, m2;
	for(auto i: nearT)
		for (auto j : nearS)
		{
			if (i == j)
			{
				cout << "YES";
				return 0;
			}

			if (i.first == j.first)
			{
				ok = true;
				if (i.second < j.second)
				{
					m1 = i.second;
					m2 = j.second;
				}
				else
				{
					m1 = j.second;
					m2 = i.second;
				}

				FOR(k,m1,m2+1)
					if (field[i.first][k] == '*')
					{
						ok = false;
						break;
					}

				if (ok)
				{
					cout << "YES";
					return 0;
				}
			}

			if (i.second == j.second)
			{
				ok = true;
				if (i.first < j.first)
				{
					m1 = i.first;
					m2 = j.first;
				}
				else
				{
					m1 = j.first;
					m2 = i.first;
				}

				FOR(k, m1, m2 + 1)
					if (field[k][i.second] == '*')
					{
						ok = false;
						break;
					}

				if (ok)
				{
					cout << "YES";
					return 0;
				}
			}
		}



	cout << "NO";
	return 0;
}