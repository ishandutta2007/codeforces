#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define int long long
using namespace std;
int n,a[15],f[16384],cnt[16384],mul[16384],pow_mul[16384][20],val[16384],inv_val[16384],ans;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
int calc(int s1,int s2){
	int val1=pow_mul[s1][cnt[s2]],val2=inv_val[s1|s2]*val[s1]%mod*val[s2]%mod;
	return val1*val2%mod;
}
int lowbit(int x){
	return x&(-x);
}
signed main(){
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i];
	for (int i=1;i<(1<<n);i++)cnt[i]=cnt[i-lowbit(i)]+1;
	for (int i=1;i<(1<<n);i++){
		mul[i]=1;
		for (int j=0;j<n;j++)
			if (i&(1<<j))mul[i]=mul[i]*a[j]%mod;
		pow_mul[i][0]=1;
		for (int j=1;j<n;j++)pow_mul[i][j]=pow_mul[i][j-1]*mul[i]%mod;
	}
	for (int i=0;i<(1<<n);i++){
		val[i]=1;
		for (int j=0;j<n;j++)
			for (int k=0;k<j;k++)
				if ((i&(1<<j))&&(i&(1<<k)))val[i]=val[i]*(a[j]+a[k])%mod;
		inv_val[i]=inv(val[i]);
	}
	for (int i=0;i<n;i++){
		memset(f,0,sizeof(f));
		f[1<<i]=1;
		for (int j=0;j<(1<<n);j++){
			if (!(j&(1<<i)))continue;
			f[j]=1;
			for (int k=(j-1)&j;k;k=(k-1)&j)
				f[j]=(f[j]+mod-f[k]*calc((j^k),k))%mod;
		}
		ans=(ans+f[(1<<n)-1])%mod;
	}
	cout<<ans<<endl;
	return 0;
}