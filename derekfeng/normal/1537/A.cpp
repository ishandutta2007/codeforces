#include<bits/stdc++.h>
using namespace std;
int n,t,x;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++)cin>>x,ans+=x;
		cout<<max((int)(ans!=n),ans-n)<<"\n";
	}
}