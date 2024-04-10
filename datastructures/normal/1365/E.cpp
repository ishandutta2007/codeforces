#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[100005];
int ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			for (register int k=1;k<=n;k++)
				ans=max(ans,a[i]|a[j]|a[k]);
	cout<<ans<<endl;
	return 0;
}