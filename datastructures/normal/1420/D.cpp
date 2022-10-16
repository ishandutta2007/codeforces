#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define mod 998244353
#define int long long
using namespace std;
int n,k,fac[1000005],l[1000005],r[1000005],c[1000005],d[1000005],_s[1000005],tot,now,ans;
inline int lower(int x){
	register int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int ans=Qpow(a,p/2);
	ans=ans*ans%mod;
	if (p%2)ans=ans*a%mod;
	return ans;
}
inline int inv(int a){
	return Qpow(a,mod-2);
}
inline int C(int n,int m){
	if (n<m)return 0;
	return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;
}
signed main(){
	cin>>n>>k;
	fac[0]=1;
	for (int i=1;i<=1000000;i++)fac[i]=fac[i-1]*i%mod;
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		_s[++tot]=l[i],_s[++tot]=r[i];
	}
	sort(_s+1,_s+1+tot);
	for (int i=1;i<=n;i++)l[i]=lower(l[i]),r[i]=lower(r[i]);
	for (int i=1;i<=n;i++)c[l[i]]++,d[r[i]+1]++;
	for (int i=1;i<=tot;i++){
		now-=d[i];
		for (int j=1;j<=c[i];j++)
			ans+=C(now,k-1),ans%=mod,now++;
	}
	cout<<ans<<endl;
	return 0;
}