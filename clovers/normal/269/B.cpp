#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,a[N],dp[N];
double x;

int main() 
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%lf",&a[i],&x);
	a[0]=0; dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<=a[i]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++) mx=max(dp[i],mx);
	cout<<n-mx<<endl;
	return 0;
}