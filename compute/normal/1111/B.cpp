#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	long long all=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		all+=arr[i];
	}
	sort(arr,arr+n);
	double ans=(all+min(1LL*m,1LL*n*k))/double(n);
	for(int i=0;i<n;i++)
	{
	    if(m-i-1<0) break;
		double cur=0;
		all-=arr[i];
		cur=(all+min(1LL*(m-i-1),1LL*(n-1-i)*k))/double(n-1-i);
		ans=max(ans,cur);
	}
	printf("%.10f\n",ans);

}