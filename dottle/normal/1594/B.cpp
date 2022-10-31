#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;

int n,k;

void solve(){
	cin>>n>>k;
	int ans=0;
	for(int i=1;k;i=i*n%mod,k>>=1)
		ans+=i*(k&1);
	cout<<ans%mod<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}