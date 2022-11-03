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
#include <cstring>
using namespace std;	

vector<int> a;
vector<vector<int> > v1,v2;
bool b[1<<23][23];
int n;

inline int bit(int mask,int i)
{
	return ((mask >> i)&1);
}

void go(int mask, int v)
{
	mask += (1<<v);
	b[mask][v]=1;
	for (int i=0; i<23; i++)
		if (i!=v && bit(mask,i))
			b[mask-(1 << i)][v]=1;
}

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n;
	a.resize(n);
	v1.resize(n);
	v2.resize(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++)
	{
		for (int i1=0; i1<i; i1++)
			for (int i2=i1; i2<i; i2++)
				if (a[i1]+a[i2]==a[i])
				{
					v1[i].push_back(i1);
					v2[i].push_back(i2);
				}
		if (!v1[i].size())
		{
			cout << -1 << endl;
			return 0;
		}
	}
	b[1][0]=1;
	for (int i=0; i<n-1; i++)
		for (int mask=0; mask<(1<<(i+1)); mask++)
			if (b[mask][i])
			for (int j=0; j<v1[i+1].size(); j++)
				if (bit(mask, v1[i+1][j]) && bit(mask, v2[i+1][j]))
				{
					go(mask, i+1);		
					break;
				}
	int ans=n;
	for (int i=0; i<(1<<n); i++)
		if (b[i][n-1])
		{
			int cnt=0;
			for (int j=0; j<23; j++)
				if (bit(i,j))
					cnt++;
			ans=min(ans,cnt);
		}
	cout << ans << endl;

	return 0;
}