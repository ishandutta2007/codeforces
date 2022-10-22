#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll n,s,h[6];
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else x=1,y=0;
	return d;
}
ll Floor(ll a,ll b){
	if(a<0)return (a-b+1)/b;
	return a/b;
}
ll Ceil(ll a,ll b){
	if(a<0)return a/b;
	return (a+b-1)/b;
}
int k3,k4,k5;
int main(){
	scanf("%lld%lld",&n,&s);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),h[x]++;
	int a=h[3],b=h[5];
	ll X,Y,G=extgcd(a,b,X,Y);
	ll A=b/G,B=a/G;
	ll ans=inf;
	for(ll i=0;i<=s;i+=h[4]){
		if((s-i)%G>0)continue;
		ll t=(s-i)/G,d=i/h[4];
		ll x=X*t,y=Y*t;
		ll L=Ceil(-x,A);
		ll R=min(min(Floor(y-d,B),Floor(y-x,A+B)),Floor(d-x,A));
		if(L>R)continue;
		ll pA=Floor(i-a*x,a*A),pB=Ceil(b*y-i,b*B),LL,RR;
		LL=max(L,pB),RR=min(R,pA);
		if(LL<=RR){
			ll tmp=2*i-a*x-b*y;
			if(tmp<ans)ans=tmp,k3=x+LL*A,k4=d,k5=y-LL*B;
		}
		LL=L,RR=min(R,min(pA,pB-1));
		if(LL<=RR){
			ll tmp=b*y-a*x-RR*(a*A+b*B);
			if(tmp<ans)ans=tmp,k3=x+RR*A,k4=d,k5=y-RR*B;
		}
		LL=max(L,max(pA+1,pB)),RR=R;
		if(LL<=RR){
			ll tmp=a*x-b*y+LL*(a*A+b*B);
			if(tmp<ans)ans=tmp,k3=x+LL*A,k4=d,k5=y-LL*B;
		}
		LL=max(L,pA+1),RR=min(R,pB-1);
		if(LL<=RR){
			ll tmp=a*x+b*y-2*i;
			if(tmp<ans)ans=tmp,k3=x+RR*A,k4=d,k5=y-RR*B;
		}
	}
	if(ans==inf)puts("-1");
	else printf("%lld %lld %lld",k3,k4,k5);
}