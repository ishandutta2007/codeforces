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
long long n,m,i,j,ans;
struct ii
{
	long long k,l;
}day[100005];
bool cmp(ii x,ii y)
{
	if (min(x.k*2,x.l)-min(x.k,x.l)>min(y.k*2,y.l)-min(y.k,y.l)) return 1;
	return 0;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>day[i].k>>day[i].l;
	}
	sort(day+1,day+n+1,cmp);
	/*for (i=1;i<=n;i++)
	{
		cerr<<day[i].k<<' '<<day[i].l<<endl;
	}*/
	for (i=1;i<=m;i++) ans+=min(day[i].k*2,day[i].l);
	for (i=m+1;i<=n;i++) ans+=min(day[i].k,day[i].l);
	cout<<ans;
	return 0;
}