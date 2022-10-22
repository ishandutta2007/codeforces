#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int ans=n/10;
		if(n%10==9)ans++;
		cout<<ans<<"\n";
	}
}