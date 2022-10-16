#include<bits/stdc++.h>
using namespace std;
long long a[1000003];
int main(){
	long long n,ans=0;
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++)
		a[i]=(a[i-1]*(n+1-i))%998244353;
	a[0]=0;
	for(int i=1;i<n-1;i++)
		ans=(ans+(a[i]*i%998244353)*(n-i-1))%998244353;
	cout<<(ans+a[n])%998244353;
}
//24,12,