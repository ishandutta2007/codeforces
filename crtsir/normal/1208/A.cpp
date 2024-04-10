#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,a,b;
		cin>>a>>b>>n;
		//a,b,a^b,a,b
		if(n%3==0)cout<<a;
		if(n%3==1)cout<<b;
		if(n%3==2)cout<<(a^b);
		cout<<endl;
	} 
}