#include<bits/stdc++.h>
using namespace std;
long long a=0,b=1,n,m,ans;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long c=b;
		b=(a+b)%1000000007;a=c;
	}
	ans+=b;a=0;b=1;
	for(int i=0;i<m;i++){
		long long c=b;
		b=(a+b)%1000000007;a=c;
	}
	ans+=b;
	ans--;
	ans%=1000000007;
	cout<<ans*2%1000000007;
}