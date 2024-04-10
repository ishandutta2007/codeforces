#include<bits/stdc++.h>
using namespace std;
int main(){
	long long T;
	cin>>T;
	while(T--){
		long long a,b,n,S;
		cin>>a>>b>>n>>S;
		if(b>=S){
			cout<<"YES\n";
			continue;
		}
		long long mod=S%n;
		if(b<mod){
			cout<<"NO\n";
			continue;
		}
		S-=mod;b-=mod;
		if(a*n+b>=S)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}