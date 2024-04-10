#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,s,a[1000005],ans;
signed main(){
	cin>>n>>s;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n/2;i++)
		if (a[i]>s)ans+=a[i]-s;
	if (a[(n+1)/2]<s)ans+=s-a[(n+1)/2];
	if (a[(n+1)/2]>s)ans+=a[(n+1)/2]-s;
	for (int i=(n+1)/2+1;i<=n;i++)
		if (a[i]<s)ans+=s-a[i];
	cout<<ans<<endl;
	return 0;
}