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
long long n,m,i,j,ax[100005],x,ma,us;
vector<long long> bx;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&ax[i]);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%lld",&x);
		bx.push_back(x);
	}
	sort(ax+1,ax+n+1);
	sort(bx.begin(),bx.end());
	//for (i=0;i<m;i++) cerr<<bx[i]<<' ';
	us=0;
	for (i=1;i<=n;i++)
	{
		while (abs(ax[i]-bx[us])>=abs(ax[i]-bx[us+1])&&us<m) us++;
		ma=max(ma,abs(ax[i]-bx[us]));
	}
	cout<<ma;
	return 0;
}