#include <iostream>
#include <cstdio>
#include <map> 
#define mod 1000000007
#define int long long
using namespace std;
int t,n,b[200005],sum[200005],sumf[200005],f[200005][2];
map <int,int>c;
int ans;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%lld",&b[i]),sum[i]=sum[i-1]+b[i];
		c.clear();
		f[1][0]=1,f[1][1]=0;
		for (int i=1;i<=n;i++){
			f[i][0]=(sumf[i-1]+1)%mod;
			f[i][1]=(sumf[i-1]-c[sum[i-1]]+(sum[i]!=b[i])+mod)%mod;
			sumf[i]=(sumf[i-1]+f[i][1])%mod;
			c[sum[i-1]]=(c[sum[i-1]]+f[i][1])%mod;
		}
		cout<<(f[n][0]+f[n][1])%mod<<endl;
	}
	return 0;
}