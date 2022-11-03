#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n,m;
vector<vector<int> > g;
vector<int> cmp,cnt,used;
int c = 0;

void dfs(int v)
{
	cmp[v] = c;
	cnt[c]++;
	used[v]=1;
	for (int i=0; i<g[v].size(); i++)
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	
	cin >> n >> m;
	g.resize(n);
	for (int i=0; i<m; i++)
	{
		int v1,v2;
		cin >> v1 >> v2;
		v1--;v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	used.resize(n);
	cmp.resize(n);
	cnt.resize(n);
	for (int i=0; i<n; i++)
		if (!used[i])
		{
			dfs(i);
			c++;
		}
	for (int i=0; i<c; i++)
		if (cnt[i]>3)
		{
			cout << -1 << endl;
			return 0;
		}
	int c1=0,c2=0;
	for (int i=0; i<c; i++)
		if (cnt[i]==1)
			c1++;
		else
		if (cnt[i]==2)
			c2++;
	if (c2 > c1 || (c1-c2)%3!=0)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i=0; i<c; i++)
		if (cnt[i]==3)
		{
			for (int j=0; j<n; j++)
				if (cmp[j]==i)
					cout << j+1 << " ";
			cout << endl;
		}
	used.assign(c,0);

	for (int i1=0; i1<c; i1++)
		if (cnt[i1]==2)
			for (int i2=0; i2<c; i2++)
				if (!used[i2] && cnt[i2]==1)
				{
					for (int i=0; i<n; i++)
						if (cmp[i]==i1 || cmp[i]==i2)
							cout << i+1 << " ";
					cout << endl;
					used[i2]=1;
					break;
				}
				
	for (int i=0; i<(c1-c2)/3; i++)
	{
		for (int itr=0; itr<3; itr++)
			for (int j=0; j<n; j++)
				if (cnt[cmp[j]]==1 && !used[cmp[j]])
				{
					used[cmp[j]]=1;
					cout << j+1 << " ";
				}
		cout << endl;
	}
	

	return 0;
}