#include<bits/stdc++.h>
using namespace std;
int T,n,a[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		string ans;
		for(int i=0;i<=100;i++)
			ans+='a';
		for(int i=0;i<n;i++){
			cout<<ans<<endl;
			ans[a[i]]='a'+'b'-ans[a[i]];
		}
		cout<<ans<<endl;
	}
}