#include<bits/stdc++.h>
using namespace std;
int main(){
	long long m,n;
	cin>>n>>m;
	if (m==n){
		cout<<"0 0"<<endl;
		return 0;
	}
	if (m==0){
		cout<<"0 0"<<endl;
		return 0;
	}
	if (m*3>=n){
		cout<<1<<" "<<n-m<<endl;
	}else{
		cout<<1<<" "<<m*2<<endl;
	}
	return 0;
}