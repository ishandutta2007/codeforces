#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	cout<<0<<endl;
	int x,p=0;
	cin>>x;
	while(!x)
		cout<<(p^(p+1))<<endl,cin>>x,p++; 
}

int main(){
	ios::sync_with_stdio(false);
	int T=1;cin>>T;
	while(T--)solve();
}