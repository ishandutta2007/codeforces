#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;
	if (b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else x=1,y=0;
	return d;
}
ll x,y;
ll A,B,C;
int main(){
	cin>>A>>B>>C;
	if (A==0){
		if (abs(C)%abs(B)!=0) puts("-1");
		else cout<<"0 "<<-C/B;
		return 0;
	}
	if (B==0){
		if (abs(C)%abs(A)!=0) puts("-1");
		else cout<<"0 "<<-C/A;
		return 0;
	}
	ll A_=abs(A),B_=abs(B),C_=abs(C);
	ll get_=extgcd(A_,B_,x,y);
	if (C%get_!=0){
		puts("-1");
		return 0;
	}
	x*=(-C)/get_,y*=(-C)/get_;
	if (A_!=A) x*=-1;
	if (B_!=B) y*=-1;
	cout<<x<<" "<<y;
}