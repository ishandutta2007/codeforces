#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
char mp[105][105];
int n,m,i,j,k;
bool us[105][105];
string ans;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	memset(us,1,sizeof(us)); 
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			for (k=1;k<=n;k++)
			{
				if (i!=k&&mp[i][j]==mp[k][j]) us[i][j]=us[k][j]=0;
			}
			for (k=1;k<=m;k++)
			{
				if (j!=k&&mp[i][j]==mp[i][k]) us[i][j]=us[i][k]=0;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (us[i][j]) ans.push_back(mp[i][j]);
		}
	}
	cout<<ans;
	return 0;
}