#include<bits/stdc++.h>
using namespace std;int T;
int main(){
	cin>>T;while(T--){
		long long n,r;cin>>n>>r;
		long long ans=(min(r,n-1)+1)*min(r,n-1)/2;
		if(r>=n)ans++;
		cout<<ans<<endl;
	} 
}