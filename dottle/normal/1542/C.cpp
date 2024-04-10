#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;

int n,t;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}

void solve(){
	int ans=0,lc=1;
	for(int i=1;n;i++){
		int nw=i/gcd(lc,i);
		ans+=(n-n/nw)*i,n=n/nw,lc*=nw;
	}
	cout<<ans%mod<<endl; 
}

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)cin>>n,solve();
}