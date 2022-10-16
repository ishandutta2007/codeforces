#include<bits/stdc++.h>
using namespace std;
long long op(string a){
    long long pos=0,res=0;
	while(pos<a.size())res=(res*100+a[pos++]-'0')%998244353;
	return res*11%998244353;
}
int main(){
	int n;
	long long ans=0;
	string a;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a,ans=(ans+op(a)*n)%998244353;
	//ans+=998244353;
	cout<<(ans+998244353)%998244353;
}