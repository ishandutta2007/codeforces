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
int n,m,i,j;
vector<pair<int,int>/**/> bi;
int main()
{
	cin>>n>>m;
	for (i=2;i<=m+1;i++)
	{
		bi.push_back(make_pair(1,i));
	}
	for (i=m+2;i<=n;i++)
	{
		bi.push_back(make_pair(i,i-m));
	}
	n--;
	cout<<(n+m-1)/m+(n+m-2)/m<<endl;
	sort(bi.begin(),bi.end());
	for (i=0;i<bi.size();i++)
	{
		cout<<bi[i].first<<' '<<bi[i].second<<endl;
	}
	return 0;
}