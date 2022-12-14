#include<bits/stdc++.h>
using namespace std;
#define re register int
int a[1005],ans,n;
int main()
{
	cin>>n;
	for(re i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(re i=2;i<=n;i++)
	ans+=a[i]-a[i-1]-1;
	cout<<ans<<endl;
	return 0;
}