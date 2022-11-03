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

int n,l;
vector<vector<int> > c;
vector<int> a,b,ans;

void dfs(int v)
{
	for (int i=0; i<7; i++)
		while (c[v][i])
		{
			c[v][i]--;
			c[i][v]--;
			dfs(i);
		}
	ans[l]=v;
	l++;
}

void buildAnswer()
{
	vector<int> used(n,0);
	for (int i=n-1; i>=0; i--)
		for (int j=0; j<n; j++)
			if (!used[j])
			{
				if (ans[i]==a[j] && ans[i+1]==b[j])
				{
					cout << (j+1) << " -" << endl;
					used[j]=1;
					break;
				}else
				if (ans[i]==b[j] && ans[i+1]==a[j])
				{
					cout << (j+1) << " +" << endl;
					used[j]=1;
					break;
				}
			}
}

int main()
{
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		ifstream cin("input.txt");
		ofstream cout("output.txt");
	#endif
	cin >> n;
	a.resize(n);
	b.resize(n);
	ans.resize(n+1);
	c.resize(7);
	for (int i=0; i<7; i++)
		c[i].resize(7);
	for (int i=0; i<n; i++)
	{
		cin >> a[i] >> b[i];
		c[a[i]][b[i]]++;
		c[b[i]][a[i]]++;
	}
	int st,cn=0;
	for (int i=0; i<7; i++)
	{
		int sum=0;
		for (int j=0; j<7; j++)
			sum += c[i][j];
		if (sum%2==1)
		{
			cn++;
			st=i;
		}
		if (cn==0 && sum>0)
			st=i;
	}
	if (cn!=2 && cn!=0)
	{
		cout << "No solution" << endl;
		return 0;
	}
	l=0;
	dfs(st);
	if (l==n+1)
	{
		buildAnswer();
		return 0;
	}
	cout << "No solution" << endl;
	return 0;
}