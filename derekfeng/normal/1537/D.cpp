#include<bits/stdc++.h>
using namespace std;
int n,t;
map<int,bool>mp;
int main(){
	cin>>t;
	for(int i=1;i<=29;i+=2)mp[(1<<i)]=1;
	while(t--){
		cin>>n;
		if(mp[n]||n%2==1)puts("Bob");
		else puts("Alice");
	}
}