#include<bits/stdc++.h>
using namespace std;
int t,n,rubbish;
int main(){
	cin>>t;
	while(t--){	
		cin>>n;
		for(int i=0;i<n;i++)cin>>rubbish; 
		cout<<n*3<<"\n";
		for(int i=1;i<=n;i+=2){
			cout<<"1 "<<i<<" "<<i+1<<"\n"; 
			cout<<"2 "<<i<<" "<<i+1<<"\n"; 
			cout<<"1 "<<i<<" "<<i+1<<"\n"; 
			cout<<"1 "<<i<<" "<<i+1<<"\n"; 
			cout<<"2 "<<i<<" "<<i+1<<"\n"; 
			cout<<"1 "<<i<<" "<<i+1<<"\n"; 
		}
	}
}