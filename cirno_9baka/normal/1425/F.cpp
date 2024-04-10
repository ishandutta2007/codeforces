#include<bits/stdc++.h>
using namespace std;
int n,a[10005],i,ans[10005],w;
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		cout<<'?'<<' '<<i<<' '<<i+1<<endl;
		cin>>a[i];
	}
	cout<<'?'<<' '<<1<<' '<<3<<endl;
	cin>>w;
	ans[1]=w-a[2];
	for(i=1;i<=n;++i)
		ans[i+1]=a[i]-ans[i];
	cout<<'!';
	for(i=1;i<=n;++i)
		cout<<' '<<ans[i];
	cout<<endl;
}