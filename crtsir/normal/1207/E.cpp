#include<bits/stdc++.h>
using namespace std;
int ans,x; 
int main(){
	cout<<"? ";
	for(int i=0;i<100;i++)cout<<i<<' ';
	cout<<endl;
	cin>>x;x/=128;
	ans+=x*128;
	cout<<"? ";
	for(int i=127;i<12800;i+=128)cout<<i<<' ';
	cout<<endl;
	cin>>x;
	cout<<"! "<<ans+127-x%128;
}