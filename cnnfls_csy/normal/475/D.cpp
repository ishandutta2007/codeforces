#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x;
map<int,long long> lst,ans,now;
int gcd(int x,int y)
{
	if (y) return gcd(y,x%y);
	return x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		now.clear();
		cin>>x;
		lst[x]++;
		for (map<int,long long>::iterator it=lst.begin();it!=lst.end();it++)
		{
			 ans[gcd(it->first,x)]+=it->second;
			 now[gcd(it->first,x)]+=it->second;
		}
		lst=now;
	}
	cin>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}