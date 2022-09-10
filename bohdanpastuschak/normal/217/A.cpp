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
#define infinity (ll)1e8+1
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
#define MAXN 11111

int n;
vi g[1100001];

char is[1001][1001];
char used[1100001];
int c = 0;
void dfs(int v)
{
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			dfs(i);
}
int main()
{
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false);
	//ifstream in("In.txt");

	cin >> n;
	int x, y;
	FOR(i, 0, 1001)
		FOR(j, 0, 1001)
		is[i][j] = 0;

	FOR(i, 0, n)
	{
		cin >> x >> y;
		is[x][y] = 1;
	}

	FOR(i,1,1001)
		FOR(j,1,1001)
		if (is[i][j] == 1)
		{
			FOR(k, 1, 1001)
				if (k != i && is[k][j] == 1)
					g[i * 1000 + j].push_back(k * 1000 + j);

			FOR(k, 1, 1001)
				if (k != j && is[i][k] == 1)
					g[i *1000 + j].push_back(i * 1000 + k);
		}

	FOR(i, 1, 1100001)
		used[i] = 0;

	FOR(i, 1, 1001)
		FOR(j, 1, 1001)
		if (is[i][j] == 1 && used[i * 1000 + j] == 0)
			dfs(i * 1000 + j), c++;

	cout << c - 1;
	return 0;
}