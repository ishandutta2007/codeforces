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
pair<int,int> vol[105];
int n,m,i,j,ans[105],hl[105],x;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) 
	{
		cin>>vol[i].first;
		vol[i].second=i;
	}
	sort(vol+1,vol+n+1);
	for (i=1;i<=n;i++)
	{
		hl[i]=max(hl[i-1],(vol[i].first+1)/2);
		m-=hl[i];
	}
	if (m<0) {cout<<-1;return 0;}
	for (i=n;i>=1&&m;i--)
	{
		x=min(vol[i].first,m+hl[i])-hl[i];
		m-=x;
		hl[i]+=x;
	}
	for (i=1;i<=n;i++)
	{
		ans[vol[i].second]=hl[i];
	}
	for (i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}