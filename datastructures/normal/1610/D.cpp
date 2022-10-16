#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define int long long
#define mod 1000000007
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t; 
}
int inv(int x){
	return Qpow(x,mod-2);
}
int fac[1000005],invfac[1000005]; 
int pow_2[1000005],ans;
int C(int n,int m){
	if (m<0||m>n)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void pre_calc(int maxn){
	fac[0]=1;
	for (int i=1;i<=maxn;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[maxn]=inv(fac[maxn]);
	for (int i=maxn-1;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	pow_2[0]=1;
	for (int i=1;i<=maxn;i++)pow_2[i]=pow_2[i-1]*2%mod;
	return;
}
int n,a[200005],cnt[35],suf[35];
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	pre_calc(n);
	for (int i=1;i<=n;i++){
		cin>>a[i];
		for (int j=0;j<=30;j++)
			if (a[i]&(1<<j)){
				cnt[j]++;
				break;
			}
	}
	for (int i=30;i>=0;i--)suf[i]=suf[i+1]+cnt[i];
	for (int i=0;i<=30;i++){
		int qwq=0;
		if (i==0){
			for (int j=1;j<=cnt[i];j++)
				qwq=(qwq+C(cnt[i],j))%mod;
		}
		else{
			for (int j=2;j<=cnt[i];j+=2)
				qwq=(qwq+C(cnt[i],j))%mod;
		}
		ans=(ans+qwq*pow_2[suf[i+1]])%mod;
	}
	cout<<ans<<endl;
	return 0;
}