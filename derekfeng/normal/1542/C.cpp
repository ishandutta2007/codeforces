#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
ll G[103];
ll lcm(ll a,ll b){
	return a/__gcd(a,b)*b;
}
ll x;
int main(){
	int t;
	G[1]=1;
	for(int i=2;i<=42;i++)G[i]=lcm(G[i-1],i);
	cin>>t;
	while(t--){
		cin>>x;
		ll ans=0;
		for(int i=2;i<=42;i++)
			ans+=(x/G[i-1]-x/G[i])%M*i;
		cout<<ans%M<<"\n";
	}
}