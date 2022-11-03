#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


int n,c,c2;
vector<int> top,p,used,ic,cnt;
vector<vector<int> > component,g,component2;
vector<pair<int,int> > ans;

void dfs(int v)
{
	used[v]=1;
	if (!used[p[v]]) 
		dfs(p[v]);
	top.push_back(v);
}

void topologicalSort()
{
	top.clear();
	used.assign(n,0);
	for (int i=0; i<n; i++)
		if (!used[i])
			dfs(i);
	reverse(top.begin(),top.end());
}

void dfs2(int v)
{
	component[c].push_back(v);
	ic[v]=c;
	used[v]=1;
	for (int i=0; i<g[v].size(); i++)
		if (!used[g[v][i]])
			dfs2(g[v][i]);
}
	

void createComponents()
{
	ic.resize(n);
	used.assign(n,0);
	component.resize(n);
	c=0;
	for (int i=0; i<n; i++)
		if (!used[top[i]])
		{
			dfs2(top[i]);
			c++;
		}
}

void dfs3(int v)
{
	component2[c2].push_back(v);
	used[v]=1;
	for (int i=0; i<component[v].size(); i++)
	{
		int u=ic[p[component[v][i]]];
		if (!used[u])
			dfs3(u);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	p.resize(n);
	g.resize(n);
	for (int i=0; i<n; i++)
	{
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
	}
	topologicalSort();
	createComponents();	
	if (c==1)
	{
		cout << 0 << endl;
		return 0;
	}
	cnt.resize(c);
	for (int i=0; i<n; i++)
		if (ic[i]!=ic[p[i]])
			cnt[ic[p[i]]]++;
	used.assign(c,0);
	component2.resize(c);
	c2=0;
	for (int i=0; i<c; i++)
		if (cnt[i]==0)
		{
			dfs3(i);
			c2++;
		}
	cout << c2 << endl;
	for (int i=0; i<c2; i++)
	{
		int v1=i;
		int v2=(i+1)%c2;
		int cmp=component2[v1][component2[v1].size()-1];
		int cmp2=component2[v2][0];
		cout << (component[cmp][0]+1) << " " << (component[cmp2][0]+1) << endl;
	}
	return 0;
}