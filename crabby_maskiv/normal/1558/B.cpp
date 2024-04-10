#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6+5;
int n,mod;
int a[N];
int sum,dp;
int main(){
	int i,j;
	cin>>n>>mod;
	for(i=1;i<=n;i++){
		if(i==1){
			sum=dp=1;
		}
		else{
			a[i]=(a[i]+a[i-1])%mod;
			dp=(sum+a[i])%mod;
			sum=(sum+dp)%mod;
		}
		for(j=2;i*j<=n;j++){
			a[i*j]=(a[i*j]+dp)%mod;
			if(i*j+j<=n) a[i*j+j]=(a[i*j+j]-dp+mod)%mod;
		}
	}
	cout<<dp;
	return 0;
}