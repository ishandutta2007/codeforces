#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int a[300100],ans1[300010],ans2[300010],now1,now2,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int t=min(i-1,n-i)*2+1;
		if (a[i]<=a[i-1]||a[i]<=a[i+1])ans2[t]=max(ans2[t],a[i]);
		else ans2[t]=max(ans2[t],max(a[i-1],a[i+1]));
		if (i-1!=n-i)t++; else t--;
		ans1[t]=max(ans1[t],a[i]);
	}
	if (n==1)
	{
		cout<<a[1]<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		if ((n-i)%2==0)
		{
			now1=max(now1,ans1[n-i]);
			cout<<now1<<" ";
		}
		else
		{
			now2=max(now2,ans2[n-i]);
			cout<<now2<<" ";
		}
	}
	cout<<now1<<endl;
	return 0;
}