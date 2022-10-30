#include<bits/stdc++.h>
#define int long long
const int N=200005,mod=1000000007;
using namespace std;
int gsc(int y,int x){
	int ans=1;
	for(int i=1;i<=x;i<<=1,y=y*y%mod)
		if(x&i)ans=ans*y%mod;
	return ans;
}int inv(int k){return gsc(k,mod-2);}

int n,t,k,jc[N];

int C(int n,int m){
	if(n<m||m<0)return 0;
	return jc[n]*inv(jc[m])%mod*inv(jc[n-m])%mod;
}

main(){
	scanf("%lld",&t);
	jc[0]=1;for(int i=1;i<N;i++)jc[i]=jc[i-1]*i%mod;
	while(t--){
		scanf("%lld%lld",&n,&k); 
		int ans=0;
		for(int i=0;i<=n;i++)
			ans+=C(n-(k-1)*(i-1),i)*inv(C(n,i))%mod;
		printf("%lld\n",ans%mod);
	}
}