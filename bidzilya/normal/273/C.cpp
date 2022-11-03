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

const double eps = 1e-8;
const double PI = acos(-1.0);

int n,m;
vector<vector<int> > g;
vector<int> ans,a,b,t;

stack<int> s;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	
	cin >> n >> m;
	a.resize(m);
	b.resize(m);
	g.resize(n);
	t.resize(n);
	for (int i=0; i<m; i++)
	{
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	ans.assign(n,1);
	for (int i=0; i<n; i++)
	{
		t[i]=0;
		for (int j=0; j<g[i].size(); j++)
			if (ans[i]==ans[g[i][j]])
				t[i]++;
		if (t[i]>1)
			s.push(i);
	}
	while (s.size())
	{
		int v=s.top();
		s.pop();
		if (t[v]<=1)continue;
		ans[v]=(ans[v]+1)%2;
		t[v]=g[v].size()-t[v];
		for (int i=0; i<g[v].size(); i++)
			if (ans[v]==ans[g[v][i]])
			{
				t[g[v][i]]++;
				if (t[g[v][i]]>1)
					s.push(g[v][i]);
			}else
				t[g[v][i]]--;
	}
	for (int i=0; i<n; i++)
		cout << ans[i];
	cout << endl;
	return 0;
}