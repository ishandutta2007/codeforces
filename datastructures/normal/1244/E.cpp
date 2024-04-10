#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define inf 1000000000000000000
using namespace std;
int n,k,a[100005],sum[100005],ans=inf;
inline int check(int x){
	return (sum[n]-sum[x-1])-a[x]*(n-x+1);
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		if (i*a[i]-sum[i]>k)break;
		int rest=k-(i*a[i]-sum[i]);
		int l=i,r=n,mx=n;
		while(l<=r){
			int mid=(l+r)/2;
			if (check(mid)<=rest)mx=mid,r=mid-1;
			else l=mid+1;
		}
		if (mx<=n-i+1)mx=n-i+1;
		rest-=check(mx);
		if (rest>=(a[mx]-a[mx-1])*(n-mx+1)){
			rest-=(a[mx]-a[mx-1])*(n-mx+1);
			mx--;
			ans=min(ans,a[mx]-a[i]-min(a[i+1]-a[i],rest/i));
		}
		else ans=min(ans,a[mx]-a[i]-min(a[mx]-a[mx-1],rest/(n-mx+1)));
	}
	cout<<max(ans,0ll)<<endl;
	return 0;
}