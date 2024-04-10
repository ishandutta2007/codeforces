#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

void solve(){
	int x,y;
	cin>>x>>y;
	if(x==y)cout<<"0 0"<<endl;
	else cout<<abs(x-y)<<' '<<min(x%abs(x-y),abs(x-y)-x%abs(x-y))<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}