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
typedef pair<int, int> pii;

const ll INF = 1e18;

int n;
vector<vector<ll> > b;
vector<ll> ans;
vector<int> x,us;

int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin >> n;
	b.resize(n);
	for (int i=0; i<n; i++)
	{
		b[i].resize(n);
		for (int j=0; j<n; j++)
			cin >> b[i][j];
	}
	x.resize(n);
	for (int i=0; i<n; i++)
	{
		cin >> x[i];
		x[i]--;
	}
	ans.resize(n);
	us.resize(n);
	for (int i=n-1; i>=0; i--)
	{
		us[x[i]]=1;
		for (int v1=0; v1<n; v1++)
			for (int v2=0; v2<n; v2++)
				if (us[v1] && us[v2])
				{
					b[x[i]][v2]=min(b[x[i]][v2],b[x[i]][v1]+b[v1][v2]);
					b[v2][x[i]]=min(b[v2][x[i]],b[v2][v1]+b[v1][x[i]]);
				}
		for (int v1=0; v1<n; v1++)
			for (int v2=0; v2<n; v2++)
				if (us[v1] && us[v2])
					b[v1][v2] = min(b[v1][v2], b[v1][x[i]]+b[x[i]][v2]);
		ans[i]=0;
		for (int v1=0; v1<n; v1++)
			for (int v2=0; v2<n; v2++)
				if (us[v1] && us[v2])
					ans[i] += b[v1][v2];
	}
	for (int i=0; i<n; i++)
		cout << ans[i] << " ";
	cout << endl;	
	return 0;
}