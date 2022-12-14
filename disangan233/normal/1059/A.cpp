#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,m,k,ans,a[100005],b[100005];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(re i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}ans+=(a[1])/k;
	for(re i=2;i<=n;i++)ans+=(a[i]-a[i-1]-b[i-1])/k;
	ans+=(m-a[n]-b[n])/k;
	cout<<ans<<endl;
}