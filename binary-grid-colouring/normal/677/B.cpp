#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100010]={0};
int main()
{
	LL n,h,k;
	while(cin>>n>>h>>k)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		LL sum=0,ans=0;
		for(int i=0;i<n;i++)
		{
			if(sum+a[i]<=h) sum+=a[i];
			else
			{
				sum=a[i];
				ans++;
			}
			LL t=sum/k;
			ans+=t;
			sum-=t*k;
		}
		if(sum)ans++;
		printf("%I64d\n",ans);
	}
	return 0;
}