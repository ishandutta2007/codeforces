#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	if(n%2)cout<<0;
	else
		n/=2,cout<<int(pow(2,n)); 
}