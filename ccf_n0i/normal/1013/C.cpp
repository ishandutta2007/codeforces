#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[200005],ans;
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n+n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+n+1);
	ans=(a[n]-a[1])*(a[n+n]-a[n+1]);
	for (i=2;i<=n;i++)
	{
		ans=min(ans,(a[i+n-1]-a[i])*(a[n+n]-a[1]));
	}
	cout<<ans<<endl;
}