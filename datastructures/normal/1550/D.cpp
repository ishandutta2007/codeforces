#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int fac[200005],invfac[200005],t,n,l,r;
int a[200005],b[200005];
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2)t=t*a%mod;
	return t;
}
int inv(int a){
	return Qpow(a,mod-2);
}
int C(int n,int m){
	if (n<0||m<0||n<m)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
signed main(){
	fac[0]=1;
	for (int i=1;i<=200000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[200000]=inv(fac[200000]);
	for (int i=199999;i>=0;i--)invfac[i]=(invfac[i+1]*(i+1))%mod;
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		for (int i=1;i<=n;i++)a[i]=l-i,b[i]=r-i;
		int ans=0;
		if (n%2==1)ans=min(1-l,r-n)*(C(n,n/2)+C(n,n-n/2))%mod;
		else ans=min(1-l,r-n)*C(n,n/2)%mod;
		if (1-l>r-n){
			for (int i=1;i<=n;i++){
				a[i]=-a[i],b[i]=-b[i];
				swap(a[i],b[i]);
			}
			for (int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]),swap(b[i],b[n-i+1]);
		}
		int j=n;
		for (int i=2;i<=n;i++){
			while(j>0&&b[j]<-a[i])j--;
			if (n%2==1){
				int qwq=n/2;
				ans=(ans+C(j-i+1,qwq-(i-1)))%mod;
				qwq=n-n/2;
				ans=(ans+C(j-i+1,qwq-(i-1)))%mod;
			}
			else{
				int qwq=n/2;
				ans=(ans+C(j-i+1,qwq-(i-1)))%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}