#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define mod 1000000007
using namespace std;
int t,n,a[500005];
int c[60],pow_2[205],ans;
signed main(){
	cin>>t;
	pow_2[0]=1;
	for (int i=1;i<=200;i++)pow_2[i]=pow_2[i-1]*2%mod;
	while(t--){
		cin>>n;
		memset(c,0,sizeof(c));
		ans=0;
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			for (int j=0;j<60;j++)
				if ((1ll<<j)&a[i])c[j]++;
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<60;j++)
				if ((1ll<<j)&a[i])ans=(ans+a[i]%mod*c[j]%mod*n%mod*pow_2[j]%mod)%mod;
			int s=0;
			for (int j=0;j<60;j++)
				if (((1ll<<j)&a[i])==0)s=(s+pow_2[j]*c[j]%mod)%mod;
			for (int j=0;j<60;j++)
				if ((1ll<<j)&a[i])ans=(ans+pow_2[j]*c[j]%mod*s%mod)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}