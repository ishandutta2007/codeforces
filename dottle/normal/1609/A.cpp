#include<bits/stdc++.h>
#define int long long
const int N=1050;
using namespace std;

void solve(){
	int cnt=0;
	int n,x,mx=0,sm=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;while(!(x&1))cnt++,x>>=1;
		mx=max(mx,x);
		sm+=x;
	}
	cout<<(mx<<cnt)-mx+sm<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}