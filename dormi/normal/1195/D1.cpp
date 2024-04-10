#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli mod=998244353;
lli fastpow(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
	}
	return ans;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	lli ans=0;
	string in;
	for(int i=0;i<n;i++){
		cin>>in;
		for(lli j=0;j<in.size();j++){
			ans+=(((fastpow(10,j*2)*(in[in.size()-j-1]-'0'))%mod)*(n))%mod;
			ans%=mod;
			ans+=(((fastpow(10,j*2+1)*(in[in.size()-j-1]-'0'))%mod)*(n))%mod;
			ans%=mod;
		}
	}
	printf("%lli\n",ans);
	return 0;
}