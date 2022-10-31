#include<bits/stdc++.h>
#define int long long
const int N=100050;
using namespace std;

void solve(){
	int _0=0,_1=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		_0+=x==0;_1+=x==1; 
	}
	cout<<(_1<<_0)<<endl;
}

main(){
	int t;cin>>t;
	while(t--)solve();
}