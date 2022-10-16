#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b,c;cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(a+c<=b)cout<<0<<endl;
		else cout<<min((a+b+c-1)/2,b+c)-b+1<<endl;
	}
}