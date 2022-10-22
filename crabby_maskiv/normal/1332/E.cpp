#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
ll n,m,l,r;
ll po(ll x,ll k){
	ll ret=1;
	x%=mod;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
int main(){
	int i,j;
	cin>>n>>m>>l>>r;
	ll od=((r-l+1+(l&1)))/2,ev=(r-l+1+(!(l&1)))/2;
	if((m*n)&1){
		cout<<po(r-l+1,n*m)%mod;
	}
	else{
		cout<<(mod+1>>1)*(po(od+ev,n*m)+po(od-ev+mod,n*m)+mod)%mod;
	}
	return 0;
}