#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	if(n==k)cout<<"0 0"<<endl;
	else if(k==0)cout<<"0 0"<<endl;
	else cout<<"1 "<<min(k*2,n-k)<<endl;
	return 0;
}