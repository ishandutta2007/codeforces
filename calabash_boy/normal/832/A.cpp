#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	cin>>n>>k;
	long long ans = n/k;
	if (ans&1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}