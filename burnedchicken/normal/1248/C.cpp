#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;

int main(){
	ll n,m,ans;
	cin >> n >> m;
	ll dp1[n],dp2[m];
	ll mod=1e9+7;
	if(m*n==1){
		cout << 2 << endl;
		return 0;
	}
	if(m*n==2){
		cout << 4 << endl;
		return 0;
	}
	if(n==1){
		dp2[0]=1;
		dp2[1]=2;
		for(ll i=0; i<m-2; i++){
			dp2[i+2]=(dp2[i+1]+dp2[i])%mod;
		}
		cout << (2*dp2[m-1])%mod << endl;
		return 0;
	}
	if(m==1){
		dp1[0]=1;
		dp1[1]=2;
		for(ll i=0; i<n-2; i++){
			dp1[i+2]=(dp1[i+1]+dp1[i])%mod;
		}
		cout << (2*dp1[n-1])%mod << endl;
		return 0;
	}
	dp1[0]=1;
	dp1[1]=2;
	for(ll i=0; i<n-2; i++){
		dp1[i+2]=(dp1[i+1]+dp1[i])%mod;
	}
	dp2[0]=1;
	dp2[1]=2;
	for(ll i=0; i<m-2; i++){
		dp2[i+2]=(dp2[i+1]+dp2[i])%mod;
	}
	ans=(2*dp1[n-1])%mod;
	ans=(ans+2*dp2[m-1])%mod;
	ans=(ans+mod-2)%mod;
	cout << ans << endl;
	return 0;
}