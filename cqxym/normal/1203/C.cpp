#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll Gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return Gcd(b,a%b);
}
int main(){
	ll n,i,k,s,t,ans=0;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<n;i++){
		scanf("%lld",&s);
		k=Gcd(k,s);
	}
	t=sqrt(k);
	for(i=1;i<=t;i++){
		if(k%i==0){
			ans+=2;
		}
	}
	if(t*t==k){
		ans--;
	}
	printf("%lld",ans);
	return 0;
}