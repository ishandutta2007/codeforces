#include<bits/stdc++.h> 
using namespace std;

int n,s,t;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>s;
		cout<<s/(n-(n-1)/2)<<endl; 
	}
}