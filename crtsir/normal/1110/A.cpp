#include<bits/stdc++.h>
using namespace std;
int main(){
	int b,k;
	cin>>b>>k;
	long long x;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		x=(x*b+n)%2;
	}
	if(x)cout<<"odd";else
	cout<<"even";
}