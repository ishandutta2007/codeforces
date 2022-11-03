

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;	
vector<vector<int> > a;
int n,m,d;
long long x;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n >> m >> d;
	a.resize(n);
	for (int i=0; i<n; i++)
		a[i].resize(m);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];
	x = -1;
	int y=a[0][0]%d;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j]%d!=y)
			{
				cout << -1 << endl;
				return 0;
			}
	for (int k=0; k<=10000; k++)
	{
		int t=y+k*d;
		long long tx=0;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				tx += abs(t-a[i][j])/d;
		if (x==-1 || tx<x)
			x = tx;
	}
	cout << x << endl;
	return 0;
}