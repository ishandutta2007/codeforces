#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
 
using namespace std;
int a[1002][1002];
int a1[1002][1002];
int b1[1002][1002];
int a2[1002][1002];
int b2[1002][1002];
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = n; i >= 1 ; --i)
	{
		for (int j = m; j >= 1; --j)
		{
			a1[i][j] = max(a1[i][j+1], a1[i+1][j]) + a[i][j];
		}
	}
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			b1[i][j] = max(b1[i-1][j], b1[i][j+1]) + a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			a2[i][j] = max(a2[i-1][j], a2[i][j-1]) + a[i][j];
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = 1; j <= m; ++j)
		{
			b2[i][j] = max(b2[i+1][j], b2[i][j-1]) + a[i][j];
		}
	}
	int ma = 0;
	for (int i = 2; i <= n-1; ++i)
	{
		for (int j = 2; j <= m-1; ++j)
		{
			ma = max(ma, max(b2[i][j-1]+b1[i][j+1]+a1[i+1][j]+a2[i-1][j], b2[i+1][j] + b1[i-1][j] + a1[i][j+1] + a2[i][j-1]));
		}
 
	}
	cout<<ma;
}