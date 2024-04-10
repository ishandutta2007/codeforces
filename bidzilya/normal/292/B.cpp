#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int module = 1e9+7;

int n,m;
vector<vector<int> > g;
vector<int> used,pw;

void dfs(int v)
{
	used[v]=1;
	for (int i=0; i<g[v].size(); i++)
	{
		int to=g[v][i];
		if (!used[to])
			dfs(to);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);

//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	
	cin >> n >> m;
	g.resize(n);
	pw.resize(n);
	for (int i=0; i<m; i++)
	{
		int v1,v2;
		cin >> v1 >> v2;
		v1--;v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
		pw[v1]++;
		pw[v2]++;
	}
	used.resize(n);
	dfs(0);
	for (int i=0; i<n; i++)
		if (!used[i])
		{
			cout << "unknown topology" << endl;
			return 0;
		}
	int c2,c1;
	c2=c1=0;
	for (int i=0; i<n; i++)
		if (pw[i]==1)
			c1++;
		else
		if (pw[i]==2)
			c2++;
	if (c2==n)
	{
		cout << "ring topology" << endl;
		return 0;
	}
	if (c1==2 && c2==n-2)
	{
		cout << "bus topology" << endl;
		return 0;
	}
	if (c1==n-1)
		for (int i=0; i<n; i++)
			if (pw[i]==n-1)
			{
				cout << "star topology" << endl;
				return 0;
			}
	cout << "unknown topology" << endl;
	return 0;
}