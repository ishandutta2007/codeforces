#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(int a){
	return Qpow(a,mod-2);
}
int n,m;
int d[200005],sum[200005],a[200005],b[200005];
inline int S(int l,int r){
	return (sum[r]-sum[l-1]+mod)%mod;
}
inline int lower(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (d[mid]<x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%lld",&d[i]);
	sort(d+1,d+1+n);
	for (int i=1;i<=n;i++)sum[i]=(sum[i-1]+d[i])%mod;
	for (int i=1;i<=m;i++)scanf("%lld%lld",&a[i],&b[i]);
	for (int i=1;i<=m;i++){
		int mid=lower(b[i]);
		int num=n-mid;
		int ans=0;
		if (num>0&&num>=a[i]){
			ans+=S(1,mid)*(num-a[i]+1)%mod*inv(num+1)%mod;
			ans%=mod;
		}
		num--;
		if (num>0&&num>=a[i]){
			ans+=S(mid+1,n)*(num-a[i]+1)%mod*inv(num+1)%mod;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}