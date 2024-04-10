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
const int module = 7+1e9;
const int MAXT = 1e5+1;

int n,m;
vector<vector<int> > g,used;
vector<int> ans,p;
int l;

void dfs(int v)
{
	for (int i=1; i<=n; i++)
		if (g[v][i] && !used[v][i])
		{
			used[v][i]=used[i][v]=1;
			dfs(i);
		}
	p[l]=v;
	l++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		ifstream cin("input.txt");
		ofstream cout("output.txt");
	#endif
	cin >> n >> m;
	g.resize(n+1);
	used.resize(n+1);
	for (int i=0; i<=n; i++)
	{
		g[i].resize(n+1);
		used[i].resize(n+1);
	}
	p.resize(m+1);
	for (int i=0; i<=m; i++)
		cin >> p[i];
	bool found=false;
	for (int i=m; i>=1; i--)
	{
		g[p[i-1]][p[i]]=g[p[i]][p[i-1]]=1;
		for (int j=p[i]+1; j<=n; j++)
			if (g[p[i-1]][j])
			{
				for (int v1=1; v1<=n; v1++)
					for (int v2=1; v2<=n; v2++)
						used[v1][v2]=0;
				l=i;
				g[p[i-1]][j]=g[j][p[i-1]]=0;
				dfs(j);
				g[p[i-1]][j]=g[j][p[i-1]]=1;
				reverse(p.begin()+i,p.end());
				if (p[l-1]!=p[0] || l!=m+1)continue;
				for (int k=0; k<=m; k++)
					cout << p[k] << " ";
				cout << endl;
				return 0;
			}
	}
	cout << "No solution" << endl;
	return 0;
}