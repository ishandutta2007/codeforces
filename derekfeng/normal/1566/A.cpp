#include<bits/stdc++.h>
using namespace std;
int T,n,s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		int id=(n+1)/2-1;
		cout<<s/(n-id)<<"\n";
	}
}