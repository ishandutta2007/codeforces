#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define int long long
#define mod 998244353
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int pow_2[200005],fac[200005],invfac[200005];
int t,n,a[200005],sum[200005];
map<int,int> qwq;
int tot,l[200005],r[200005];
int val;
int C(int n,int m){
	if (m<0||m>n)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int calc(int l,int r){
	int x=0,y=0;
	l--;
	while(l>=1&&a[l]==0)x++,l--;
	r++;
	while(r<=n&&a[r]==0)y++,r++;
	x++,y++;
	int ans=0;
	for (int i=1;i<=min(x,y);i++)ans=(ans+C(x,i)*C(y,i))%mod;
	return ans;
}
int _calc(int l,int r){
	int x=0,y=0;
	l--;
	while(l>=1&&a[l]==0)x++,l--;
	r++;
	while(r<=n&&a[r]==0)y++,r++;
	int ans=1;
	for (int i=1;i<=min(x,y);i++)ans=(ans+C(x,i)*C(y,i))%mod;
	return ans;
}
signed main(){
	pow_2[0]=1;
	for (int i=1;i<=200000;i++)pow_2[i]=pow_2[i-1]*2%mod;
	fac[0]=1;
	for (int i=1;i<=200000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[200000]=Qpow(fac[200000],mod-2);
	for (int i=200000-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	cin>>t;
	while(t--){
		cin>>n;
		qwq.clear();
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
			if (qwq[sum[i]]==0)qwq[sum[i]]=i;
		}
		if (sum[n]==0){
			cout<<pow_2[n-1]<<endl;
			continue;
		}
		tot=0;
		for (int i=1;i<=n;i++)
			if (a[i]>0&&qwq[sum[n]-sum[i-1]]>=i)++tot,l[tot]=i,r[tot]=qwq[sum[n]-sum[i-1]];
		val=0;
		int cnt=0;
		for (int i=1;i<=n;i++)
			if (sum[i-1]==sum[n]-sum[i-1])cnt++;
		val=pow_2[cnt]-1;
		int ans=0;
		for (int i=tot;i>=1;i--){
			int qwq=calc(l[i],r[i]);
			if (i==1)qwq=_calc(l[i],r[i]);
			qwq=qwq*(1+val)%mod;
			if (i==1)ans=qwq;
			val=(val+qwq)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}