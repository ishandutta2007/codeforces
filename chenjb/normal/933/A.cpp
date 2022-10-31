#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;
int a[2100],one[2100],two[2100];
int n,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	one[0]=two[0]=0;
	for(int i=1;i<=n;i++)one[i]=one[i-1]+(1==a[i]);
	for(int i=1;i<=n;i++)two[i]=two[i-1]+(2==a[i]);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int now=0;
		int t1=0;
		int t2=0;
		for(int j=i;j<=n;j++)
		{
			if (a[j]==1)t1++;
			else
			if (a[j]==2)
			{
				t2++;
				if(t2>t1)
				{
					now=now+t2;
					t1=t2=0;
				}
			}
			int sum=now+t1+one[i-1]+two[n]-two[j];
			//cout<<now<<endl;
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}