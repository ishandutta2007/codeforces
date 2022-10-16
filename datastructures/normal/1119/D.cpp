#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,s[100005],d[100005],sum[100005];
int q,l,r;
int larger(int x){
	int l=1,r=n-1,ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if (d[mid]>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&s[i]);
	sort(s+1,s+1+n);
	for (int i=1;i<n;i++)d[i]=s[i+1]-s[i]-1;
	sort(d+1,d+n);
	for (int i=n-1;i>=1;i--)sum[i]=sum[i+1]+d[i];
	cin>>q;
	while(q--){
		scanf("%lld%lld",&l,&r);
		int p=larger(r-l);
		printf("%lld ",(s[n]+r)-(s[1]+l)+1-(sum[p]-(n-p)*(r-l)));
	}
	return 0;
}