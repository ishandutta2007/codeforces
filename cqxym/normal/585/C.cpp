#include<iostream>
using namespace std;
#define ll unsigned long long
ll Gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return Gcd(b,a%b);
}
int main(){
	ll x,y;
	cin>>x>>y;
	if(Gcd(x,y)>1){
		cout<<"Impossible";
		return 0;
	}
	while(x>1&&y>1){
		if(x>y){
			cout<<x/y<<'A';
			x%=y;
		}else{
			cout<<y/x<<'B';
			y%=x;
		}
	}
	if(x==1){
		cout<<y-1<<'B';
	}else if(y==1){
		cout<<x-1<<'A';
	}
	return 0;
}