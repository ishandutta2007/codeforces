#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=250005;
ll mod;
int n,m;
ll fac[N];
int main(){
	int i,j;
	cin>>n>>mod;
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ll ans=0;
	for(i=1;i<=n;i++)
		ans=(ans+((fac[i]*fac[n-i]%mod)*(n-i+1)%mod)*(n-i+1)%mod)%mod;
	cout<<ans;
	return 0;
}