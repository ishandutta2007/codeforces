#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;
int n,a[305];
int len,C[305][305],fac[305],p[305];
int f[305][305],ans;
int work(int n){
	for (int i=2;i*i<=n;i++)
		while(n%(i*i)==0)n/=i*i;
	return n;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i],a[i]=work(a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;){
		int j=i;
		while(a[j]==a[i])j++;
		++len;
		p[len]=j-i;
		i=j;
	}
	for (int i=0;i<=n;i++)C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	f[0][0]=1;
	for (int i=1;i<=len;i++)
		for (int j=1;j<=n;j++){
			for (int k=1;k<=p[i]&&k<=j;k++)
				f[i][j]=(f[i][j]+f[i-1][j-k]*C[p[i]-1][k-1]%mod*C[j][k])%mod;
		}
	for (int i=len;i<=n;i++)
		if ((n-i)&1)ans=(ans+mod-f[len][i])%mod;
		else ans=(ans+f[len][i])%mod;
	for (int i=1;i<=len;i++)ans=ans*fac[p[i]]%mod;
	cout<<ans<<endl;
	return 0;
}