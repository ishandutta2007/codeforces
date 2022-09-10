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

#define mod 1000000007
#define infinity (ll)1e18+1
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
#define MAXN 10001

int n;
int p[MAXN];
int h[MAXN];

int find(int i)
{
	if (i == p[i])
		return i;
	return p[i] = find(p[i]);
}

void unite(int i, int j)
{
	i = find(i);
	j = find(j);
	if (i != j)
	{
		if (h[i] < h[j])
			swap(h[i], h[j]);
		p[j] = i;
		if (h[i] == h[j])
			h[i]++;
	}
}

int main()
{
	cin >> n;
	int x, y;

	FOR(i, 1, n + 1)
		p[i] = i, h[i] = 1;

	vpii close;
	vpii open;

	FOR(i, 0, n - 1)
	{
		cin >> x >> y;
		if (find(x) == find(y))
			close.push_back(MP(x, y));
		else
			unite(x, y);
	}

	FOR(i, 2, n + 1)
	{
		if (find(1) != find(i))
		{
			open.push_back(MP(i, 1));
			unite(1, i);
		}
	}

	cout << close.size() << endl;
	FOR(i, 0, close.size())
		cout << close[i].first << " " << close[i].second << " " << open[i].first << " " << open[i].second << endl;
	
	return 0;
}