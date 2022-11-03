#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef pair<int,int> pii;
const double eps = 1e-8;
const double PI = acos(-1.0);

int n;
vector<int> mt,used;
vector<vector<int> > g;

int try_kuhn(int v)
{
	if (used[v])return 0;
	used[v]=1;
	for (int i=0; i<g[v].size(); i++)
	{
		int to=g[v][i];
		if (mt[to]==-1 || try_kuhn(mt[to]))
		{
			mt[to]=v;
			return 1;
		}
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	cin >> n;
	g.resize(n);
	for (int i=0; i<n; i++)
	{
		int l,r;
		cin >> l >> r;
		for (int j=l; j<=min(l+111,r); j++)
			g[i].push_back(j);
	}
	mt.assign(10000001,-1);
	for (int i=0; i<n; i++)
	{
		used.assign(n,0);
		try_kuhn(i);
	}
	vector<int> ans(n);
	for (int i=1; i<=10000000; i++)
		if (mt[i]!=-1)
			ans[mt[i]]=i;
	for (int i=0; i<n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}