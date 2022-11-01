#include<iostream>
using namespace std;
#define ll long long
ll Gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return Gcd(b,a%b);
}
int main(){
	ll n,m,c,d,u,i,q,a,b;
	cin>>n>>m>>q;
	u=Gcd(n,m);
	m/=u;
	n/=u;
	for(i=0;i<q;i++){
		cin>>a>>b>>c>>d;
		if(a==1){
			b=(b+n-1)/n;
		}else{
			b=(b+m-1)/m;
		}
		if(c==1){
			d=(d+n-1)/n;
		}else{
			d=(d+m-1)/m;
		}
		if(b==d){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}