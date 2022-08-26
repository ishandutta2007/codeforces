#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
vector<int> bi[1005];
int n,m,i,j,cnt,x;
int main()
{
	cin>>n;
	for (i=2;i<=n;i++)
	{
		cin>>x;
		bi[x].push_back(i);
	}
	for (i=1;i<=n;i++)
	{
		if (bi[i].empty()) continue;
		cnt=0;
		for (j=0;j<bi[i].size();j++) if (bi[bi[i][j]].empty()) cnt++;
		if (cnt<3)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}