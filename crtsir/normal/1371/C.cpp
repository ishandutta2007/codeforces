#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		long long a,b,x,y;
		cin>>a>>b>>x>>y;
		if(a+b<x+y){cout<<"No\n";continue;}
		if(a>b&&y>b){cout<<"No\n";continue;}
		if(a<=b&&y>a){cout<<"No\n";continue;}
		else cout<<"Yes\n";
	} 
}