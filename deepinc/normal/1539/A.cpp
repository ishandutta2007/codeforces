#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		long long n,t,x; cin>>n>>x>>t;
		if(n<t/x)cout<<(n-1)*n/2<<endl;
		else cout<<t/x*(n-t/x)+t/x*(t/x-1)/2<<endl;
	}
}