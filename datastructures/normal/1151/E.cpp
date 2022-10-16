#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[100005],ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		if (a[i]==a[i-1])continue;
		if (a[i]>a[i-1])ans+=(a[i]-a[i-1])*(n-a[i]+1);
		else ans+=a[i]*(a[i-1]-a[i]);
	}
	cout<<ans<<endl;
	return 0;
}