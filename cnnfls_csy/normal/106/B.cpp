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
struct ii
{
	int sp,ra,hd,co,id;
}cum[100005],uscum[100005];
//vector<ii> uscum;
int n,m,i,j,us[100005],mi=1<<25,ms;
bool cmp(ii x,ii y)
{
	if (x.co<y.co) return 1;
	return 0;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>cum[i].sp>>cum[i].ra>>cum[i].hd>>cum[i].co;
		cum[i].id=i;
		us[i]=1;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (i!=j&&(cum[i].sp<cum[j].sp&&cum[i].ra<cum[j].ra&&cum[i].hd<cum[j].hd)) us[i]=0;
		}
	}
	//for (i=1;i<=n;i++) cerr<<us[i]<<' ';
	for (i=1;i<=n;i++)
	{
		if (us[i]&&cum[i].co<mi)
		{
			mi=cum[i].co;
			ms=i;
		}
	}
	cout<<ms;
	return 0;
}