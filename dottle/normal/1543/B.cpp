#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

void solve(){
	int n,s=0,x;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x,s+=x;
	cout<<s%n*(n-s%n)<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}