#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	long long ans=0;
	for(int i=0;i<n/2;i++)
	{
		ans+=(arr[i]+arr[n-1-i])*(arr[i]+arr[n-1-i]);
	}
	printf("%lld\n",ans);
}