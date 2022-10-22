#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n,m;
int a[N+1];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n/2+1;i<n;i++)
		if((i-n/2)*(a[i+1]-a[i])>m)return printf("%lld",a[i]+m/(i-n/2)),0;
		else m-=(i-n/2)*(a[i+1]-a[i]);
	printf("%lld",a[n]+m/(n-n/2));
	return 0;
}