#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int n,a[100005],sum[2],ans;
inline int work(int x,int s){
	int ans=0;
	while(x)ans+=(x%10)*s,ans%=mod,s*=100,s%=mod,x/=10;
	return ans;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum[0]+=work(a[i],1),sum[0]%=mod;
		sum[1]+=work(a[i],10),sum[1]%=mod;
	}
	for (int i=1;i<=n;i++){
		ans+=(sum[0]+work(a[i],10)),ans%=mod;
		ans+=(sum[1]+work(a[i],1)),ans%=mod;
		ans-=(work(a[i],1)+work(a[i],10)),ans=(ans%mod+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}