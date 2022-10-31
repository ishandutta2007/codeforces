#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int b,k;
	scanf("%d%d",&b,&k);
	for(int i=k-1;i>=0;i--)
	{
		scanf("%d",&arr[i]);
	}
	long long ans=0;
	for(int i=k-1;i>=0;i--)
	{
		if(i)
			ans+=arr[i]*b;
		else ans+=arr[i];
	}
	ans%=2;
	if(ans) puts("odd");
	else puts("even");
}