#include<bits/stdc++.h>
using namespace std;
int n,m,q;
string s[23],t[23];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<m;i++)cin>>t[i];cin>>q;
	while(q--){
		int a;
		cin>>a;
		cout<<s[(a+n-1)%n]<<t[(a+m-1)%m]<<endl;
	}
}