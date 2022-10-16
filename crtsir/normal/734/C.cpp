#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010],c[200010],d[200010],n,m,k,x,s,ans=LONG_LONG_MAX;
int main()
{
	cin>>n>>m>>k>>x>>s;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=k;i++)cin>>c[i];
	for(int i=1;i<=k;i++)cin>>d[i];
	a[0]=x;
	for(int i=0;i<=m;i++)
	{
		if(b[i]>s)continue;
		long long maxn=upper_bound(d+1,d+k+1,s-b[i])-d-1;
		ans=min(ans,(n-c[maxn])*a[i]);
	}
	cout<<ans;
}