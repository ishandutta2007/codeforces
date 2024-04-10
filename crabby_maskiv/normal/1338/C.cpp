#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
ll f1(ll x){
	ll t=1,b=1;
	while(x>t){
		x-=t;
		t*=4;
		b*=4;
	}
	return b+x-1;
}
ll f2(ll x){
	ll t=1,b=2;
	while(x>t){
		x-=t;
		t*=4;
		b*=4;
	}
	ll ans=b;
	t=1;x--;
	while(x){
		if(x%4==1) ans+=2*t;
		else if(x%4==2) ans+=3*t;
		else if(x%4==3) ans+=t;
		t*=4;
		x/=4;
	}
	return ans;
}
int main(){
	int i,j,k;
	int T;cin>>T;
	while(T--){
		ll x;cin>>x;
		if(x%3==1) cout<<f1((x+2)/3)<<endl;
		else if(x%3==2) cout<<f2((x+2)/3)<<endl;
		else cout<<(f1((x+2)/3)^f2((x+2)/3))<<endl;
	}
	return 0;
}