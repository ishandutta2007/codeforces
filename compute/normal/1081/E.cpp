#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];
vector<int> fac[maxn];
long long ans[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	n/=2;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		for(int j=1;j<sqrt(arr[i]);j++)
		{
			if(arr[i]%j==0)
				fac[i].push_back(arr[i]/j);
		}
		sort(fac[i].begin(),fac[i].end());
	}
	int now=0;
	bool flag=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<fac[i].size();j++)
		{
			int a=fac[i][j],b=arr[i]/a;
			if((a+b)%2) continue;
			int aa=(a+b)/2,bb=(a-b)/2;
			if(bb<=now) continue;
			else{
				ans[i]=1LL*bb*bb-1LL*now*now;
				now=aa;
				break;
			}
		}
		if(ans[i]==0) flag=0;
		if(!flag) break;
	}
	if(!flag) puts("No");
	else {
		puts("Yes");
		for(int i=0;i<n;i++)
		{
			printf("%lld %d ",ans[i],arr[i]);
		}
	}

}