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
	string in[n];
	lli am[13]={};
	for(int i=0;i<n;i++){
		cin>>in[i];
		for(int j=in[i].size();j>=0;j--){
			am[j]+=1;
		}
	}
	for(int i=0;i<n;i++){
		for(lli j=0;j<in[i].size();j++){
			ans+=(((fastpow(10,j*2)*(in[i][in[i].size()-j-1]-'0'))%mod)*(am[j]))%mod;
			ans%=mod;
			for(lli k=j-1;k>=0;k--){
				ans+=(((fastpow(10,j*2-((j-k)))*(in[i][in[i].size()-j-1]-'0'))%mod)*(am[k]-am[k+1]))%mod;
				ans%=mod;
			}
			ans+=(((fastpow(10,j*2+1)*(in[i][in[i].size()-j-1]-'0'))%mod)*(am[j+1]))%mod;
			ans%=mod;
			for(lli k=j-1;k>=0;k--){
				ans+=(((fastpow(10,j*2-((j-k))+1)*(in[i][in[i].size()-j-1]-'0'))%mod)*(am[k+1]-am[k+2]))%mod;
				ans%=mod;
			}
		}
	}
	printf("%lli\n",ans);
	return 0;
}