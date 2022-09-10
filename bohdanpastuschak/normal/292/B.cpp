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
clock_t startTime;

int n;
int m;
vi g[MAXN];

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	cin >> n >> m;
	int a, b;
	FOR(i, 0, m)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int s1 = 0;
	FOR(i, 1, n + 1)
		if (g[i].size() == 1)
			s1++;

	if (s1 == 2)
	{
		int s2 = 0;
		FOR(i, 1, n + 1)
			if (g[i].size() == 2)
				s2++;
		if (s2 + s1 == n)
			cout << "bus topology";
		else
			cout << "unknown topology";
		return 0;
	}
	else
	{
		if (s1 == 0)
		{
			int s2 = 0;
			FOR(i, 0, n)
				if (g[i + 1].size() == 2)
					s2++;
			if (s2 != n)
				cout<< "unknown topology";
			else
			{
				cout << "ring topology";
			}
		}
		else
		{
			if (s1 == n - 1)
			{
				cout << "star topology";
				return 0;
			}
			else
				cout<< "unknown topology";
		}
	}
		
	return 0;
}
//don't forget about MAXN, mod and infinity