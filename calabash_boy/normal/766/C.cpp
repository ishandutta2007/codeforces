#include <iostream>

using namespace std;

const int mod=1e9+7,sz=1005;
int n,a[35],dp[sz],ct[sz],mx,i,j;
string s;

// template<typename t> t min(t a,t b){return a<b?a:b;}
int main() {
	cin>>n>>s;
	for(int i=0;i<26;i++) cin>>a[i];
	dp[0]=1; ct[0]=0;
	for(i=1;i<=n;i++){
		int mn=a[s[i-1]-'a'];
		for(j=i-1; i-j<=mn&&j>=0; j--) {
			mn=min(mn,a[s[j-1]-'a']);
			dp[i]=(dp[i]+dp[j])%mod;
		}
		mx=max(mx,i-j-1);
		ct[i]=ct[j+1]+1;
	}
	cout<<dp[n]<<endl<<mx<<endl<<ct[n]<<endl;

	return 0;
}