#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1000000000;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
ll gcd(ll x,ll y){
	return !y?x:gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x/gcd(x,y)*y;
}
int main(){
	int T,n,i;
	ll x,y,ans,r,t;
	read(T);
	while(T--){
		read(x);read(y);
		if(x>y){
			printf("%lld\n",ans=x+y);
		}
		else if(x==y){
			printf("%lld\n",ans=x);
		}
		else{
			r=y%x;
			printf("%lld\n",ans=y-r/2LL);
		}
	} 
	return 0;
}