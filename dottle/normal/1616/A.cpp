#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;map<int,int>a;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;a[abs(x)]++;
	} 
	int ans=0; 
	for(auto x:a)ans+=min(x.second,2ll-!x.first);
	cout<<ans<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}