#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int n,mod,fac[1000005],ans;
signed main(){
	cin>>n>>mod;
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	for (int i=1;i<=n;i++)ans=(ans+(n-i+1)*(n-i+1)%mod*fac[n-i]%mod*fac[i]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}