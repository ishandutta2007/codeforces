#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007LL;
int main(){
	long long n,m,k,ans=1LL,i;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==1||k>n){
		for(i=1;i<=n;++i)ans=ans*m%mod;
		printf("%lld\n",ans);
	}
	else if(k<n){
		if(k&1)ans=m*m;
		else ans=m;
		printf("%lld\n",ans);
	}
	else if(k==n){
		for(i=1;i*2<=n+1;++i)ans=ans*m%mod;
		printf("%lld\n",ans);
	}
	return 0;
}