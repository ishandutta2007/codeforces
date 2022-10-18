#include<bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long n,k;
	cin>>n>>k;
	if(k%n==0) cout<<k/n;
	else cout<<k/n+1;
	return 0;
}