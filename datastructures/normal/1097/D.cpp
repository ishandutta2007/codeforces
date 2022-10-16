#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
using namespace std;
int n,k;
int f[105],ans=1;
int inv[105];
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
void dp(int n){
	memset(f,0,sizeof(f));
	f[n]=1;
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			int qwq=0;
			for (int l=j;l<=n;l++)
				qwq=(qwq+inv[l+1]*f[l])%mod;
			f[j]=qwq;
		}
	}
	return;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<=100;i++)inv[i]=Qpow(i,mod-2);
	for (int i=2;i*i<=n;i++){
		if (n%i>0)continue;
		int cnt=0;
		while(n%i==0)cnt++,n/=i;
		dp(cnt);
		int awa=0;
		for (int j=0,qwq=1;j<=cnt;j++,qwq*=i)awa=(awa+qwq%mod*f[j])%mod;
		ans=ans*awa%mod;
	}
	dp(1);
	if (n>1)dp(1),ans=ans*(f[0]+n%mod*f[1]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}