#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define LL long long
using namespace std;
LL a[500],b[500],c[500000];
int main()
{
	LL x,y,l,r;
	cin>>x>>y>>l>>r;

	int tot1,tot2;
	tot1=1;
	LL now=1;
	a[1]=1;
	while (now<=r/x)
	{
		now*=x;
		a[++tot1]=now;
	}
	now=1;
	b[1]=1;
	tot2=1;
	while (now<=r/y)
	{
		now*=y;
		b[++tot2]=now;
	}
	int tot=0;
	for(int i=1;i<=tot1;i++)
		for(int j=1;j<=tot2;j++)
			if (a[i]>=l-b[j]&&a[i]<=r-b[j])c[++tot]=a[i]+b[j];
	sort(c+1,c+tot+1);
	LL ans=0;
	if (tot==0)ans=r-l+1;
	else
	{
		ans=max(c[1]-l,r-c[tot]);
		for(int i=2;i<=tot;i++)ans=max(ans,c[i]-c[i-1]-1);
	}
	cout<<ans<<endl;
	return 0;
}