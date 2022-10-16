#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		if((a+b+c)%9==0&&min(min(a,b),c)>=(a+b+c)/9)
			cout<<"YES\n";
		else
			cout<<"NO\n"; 
	}
}