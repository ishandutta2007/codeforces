#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,s=0,x;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;s+=x;s%=n;
	}
	cout<<!!s<<'\n';
}

int main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}