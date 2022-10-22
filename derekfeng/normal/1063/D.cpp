#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r,k,A,B;
void sol1(){
	ll ans=-1;
	for(int i=n;i<=n+n;i++){
		ll K=(k-1)%i+1,D=i-n;
		if(K<A)continue;K-=A;
		if(min(A,D)>=K&&K+B>=D)ans=i-n;
		if(min(A-1,D-1)>=K&&K+B+1>=D)ans=i-n;
	}
	printf("%lld",ans);
}
ll Ceil(ll a,ll b){
	if(a<0)return -(-a)/b;
	return (a+b-1)/b;
}
ll Floor(ll a,ll b){
	if(a<0)return -(-a+b-1)/b;
	return a/b;
}
void sol2(){
	ll ans=-1;
	if(A<=k&&k<=A*2)ans=min(k-A+1,A)+B;
	for(ll i=1;i<=k/n;i++){
		ll K=k-A*(i+1)-B*i;
		if(K<0)continue;
		ll X=K,Y=-K;
		ll L=max(Ceil(-X,i),Ceil(Y-B,i+1));
		ll R=min(Floor(A-X,i),Floor(Y,i+1));
		if(L<=R)ans=max(ans,X+Y-L);	
	}
	for(ll i=1;i<=k/n;i++){
		ll K=k+1-A*(i+1)-B*i;
		if(K<0)continue;
		ll X=K,Y=-K;
		ll L=max(Ceil(1-X,i),Ceil(Y-B,i+1));
		ll R=min(Floor(A-X,i),Floor(Y,i+1));
		if(L<=R)ans=max(ans,X+Y-L);
	}
	printf("%lld",ans);
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	A=(r-l+n+1)%n;if(!A)A=n;B=n-A;
	if(n<=4e5)sol1();else sol2();
}