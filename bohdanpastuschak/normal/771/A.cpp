#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <memory.h>
#include <utility>
#include <cctype>
#include <complex>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;

#define ll long long
#define mod 1000000007
#define infinity (ll)1e8
#define epsilon 1e-7

#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pii pair<int,int>
#define MP make_pair
#define PB push_back

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(ll i = (b) - 1; i >= a; --i)
#define REPEAT(n) FOR(counter, 0, (n))
/*
int n, m;
//cin >> n >> m;

int xx, yy;
vector<int> edges[150001];

map<pair<int, int>, bool> mp;

bool check(int v)
{
	for (int i = 0; i < edges[v].size(); i++)
		for (int j = i + 1; j < edges[v].size(); j++)
			if (i != j && !(mp[make_pair(edges[v][i], edges[v][j])] || mp[make_pair(edges[v][j], edges[v][j])]))
				return true;

	return false;
}

set<int> v;
set<int>::iterator it;
*/
#define MAXN 160000

string a[51] = { "Aaa","Aaq", "Aaz", "Aaw", "Aas", "Aax", "Aae", "Aad", "Aac", "Aar", "Aaf", "Aav", "Aat", "Aag", "Aab", "Aay", "Aah", "Aan", "Aau", "Aaj", "Aam", "Aai", "Aak", "Aao",
"Aala", "Apaa", "Aqaa", "Aaaa", "Azaa", "Awaa", "Asaa", "Axaa", "Aeaa", "Adaa", "Acaa", "Araa", "Afaa", "Avaa", "Ataa", "Agaa", "Abaa", "Ayaa", "Ahaa", "Anaa", "Auaa", "Ajaa", "Amaa", "Aiaa", "Akaa", "Aoaa", "Alaa" };

string jyn[100];

int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

long long res(0);

void find_comps() {
	for (int i = 0; i<n; ++i)
		used[i] = false;
	for (int i = 0; i<n; ++i)
		if (!used[i]) {
			comp.clear();
			dfs(i);
			long long k = comp.size();
			res += k*(k - 1) / 2;
		}
}


int main()
{
	int  m;
	cin >> n >> m;
	int xx, yy;
	for (int i = 0; i < m; i++)
	{
		cin >> xx >> yy;
		xx--;
		yy--;
		g[xx].push_back(yy);
		g[yy].push_back(xx);
	}
	find_comps();
	if (res == m)
	{
		cout << "YES" << endl;
	}
	else
	{

		cout << "NO" << endl;
	}

	return 0;
}