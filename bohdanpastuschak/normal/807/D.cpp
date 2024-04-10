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

#define infinity (ll)1e8+1
#define PI 3.14159265358979

#define ll long long
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

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001

int n;
vector<vi> a;
int solved[5];
int cost[5];
int petya[5];
int vasya[5];

bool can(int bots)
{
	int now_V[5], now_P[5];
	int now_solved[5], now_cost[5];
	int nowN = n + bots;
	FOR(i, 0, 5)
	{
		if (a[0][i] == -1)
		{
			if (a[1][i] == -1)
			{
				now_P[i] = 0;
				now_V[i] = 0;
			}
			else
			{
				now_solved[i] = solved[i];
				if (2 * now_solved[i] > nowN)
					now_cost[i] = 500;
				else
				{
					if (4 * now_solved[i] > nowN)
						now_cost[i] = 1000;
					else
					{
						if (8 * now_solved[i] > nowN)
							now_cost[i] = 1500;
						else
						{
							if (16 * now_solved[i] > nowN)
								now_cost[i] = 2000;
							else
							{
								if (32 * now_solved[i] > nowN)
									now_cost[i] = 2500;
								else
									now_cost[i] = 3000;
							}
						}
					}
				}


				now_V[i] = 0;
				now_P[i] = now_cost[i] - a[1][i] * now_cost[i] / 250;
			}
		}
		else
		{
			if (a[0][i] >= 0 && a[1][i] == -1)
			{
				now_solved[i] = solved[i];
				if (2 * now_solved[i] > nowN)
					now_cost[i] = 500;
				else
				{
					if (4 * now_solved[i] > nowN)
						now_cost[i] = 1000;
					else
					{
						if (8 * now_solved[i] > nowN)
							now_cost[i] = 1500;
						else
						{
							if (16 * now_solved[i] > nowN)
								now_cost[i] = 2000;
							else
							{
								if (32 * now_solved[i] > nowN)
									now_cost[i] = 2500;
								else
									now_cost[i] = 3000;
							}
						}
					}
				}


				now_P[i] = 0;
				now_V[i] = now_cost[i] - a[0][i] * now_cost[i] / 250;
			}
			else
			{
				if (a[0][i] > a[1][i])
				{
					now_solved[i] = solved[i] + bots;
					if (2 * now_solved[i] > nowN)
						now_cost[i] = 500;
					else
					{
						if (4 * now_solved[i] > nowN)
							now_cost[i] = 1000;
						else
						{
							if (8 * now_solved[i] > nowN)
								now_cost[i] = 1500;
							else
							{
								if (16 * now_solved[i] > nowN)
									now_cost[i] = 2000;
								else
								{
									if (32 * now_solved[i] > nowN)
										now_cost[i] = 2500;
									else
										now_cost[i] = 3000;
								}
							}
						}
					}


					now_P[i] = now_cost[i] - a[1][i] * now_cost[i]/250;
					now_V[i] = now_cost[i] - a[0][i] * now_cost[i] / 250;
				}
				else
				{
					now_solved[i] = solved[i];
					if (2 * now_solved[i] > nowN)
						now_cost[i] = 500;
					else
					{
						if (4 * now_solved[i] > nowN)
							now_cost[i] = 1000;
						else
						{
							if (8 * now_solved[i] > nowN)
								now_cost[i] = 1500;
							else
							{
								if (16 * now_solved[i] > nowN)
									now_cost[i] = 2000;
								else
								{
									if (32 * now_solved[i] > nowN)
										now_cost[i] = 2500;
									else
										now_cost[i] = 3000;
								}
							}
						}
					}
					
					now_P[i] = now_cost[i] - a[1][i] * now_cost[i] / 250;
					now_V[i] = now_cost[i] - a[0][i] * now_cost[i] / 250;
				}
			}
		}
	}

	int SV = 0, SP = 0;
	FOR(i, 0, 5)
	{
		SV += now_V[i];
		SP += now_P[i];
	}
	return SV > SP;
}

int bin_search(int l, int r)
{
	if (l == r)
		if (can(l))
			return l;
		else
			return -1;

	if (r - l == 1)
	{
		if (can(l))
			return l;
		else
			if (can(r))
				return r;
			else
				return -1;
	}

	int mid = (l + r) / 2;
	if (can(mid))
		return bin_search(l, mid);
	else
		return bin_search(mid, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream in("In.txt");
	
	cin >> n;

	vi aaaa(5);
	a.assign(n, aaaa);
	FOR(i, 0, n)
		FOR(j, 0, 5)
		cin >> a[i][j];
	
	FOR(j, 0, 5)
		solved[j] = 0;
	FOR(i, 0, n)
		FOR(j, 0, 5)
		if (a[i][j] != -1)
			solved[j]++;

	
	FOR(i, 0, 5)
	{
		if (2 * solved[i] > n)
			cost[i] = 500;
		else
		{
			if (4 * solved[i] > n)
				cost[i] = 1000;
			else
			{
				if (8 * solved[i] > n)
					cost[i] = 1500;
				else
				{
					if (16 * solved[i] > n)
						cost[i] = 2000;
					else
					{
						if (32 * solved[i] > n)
							cost[i] = 2500;
						else
							cost[i] = 3000;
					}
				}
			}
		}
	}
			
	int BIG = 100000;
	FOR(i,0,BIG)
		if (can(i))
		{
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}