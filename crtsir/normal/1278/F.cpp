#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k,s[5003][5003];
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)ret=1ll*ret*x%mod;
		times>>=1;x=1ll*x*x%mod;
	}return ret;
}
int main(){
	cin>>n>>m>>k;
	int ans=0,PW=1;
	for(int i=0;i<5003;i++)
		s[i][i]=1;
	for(int i=2;i<5003;i++)
		for(int j=1;j<i;j++)
			s[i][j]=(1ll*s[i-1][j]*j+s[i-1][j-1])%mod;
	for(int i=0;i<=k;i++){
		ans=(ans+1ll*s[k][i]*mypow(m,mod-1-i)%mod*PW)%mod;
		PW=1ll*PW*(n-i)%mod;
	}
	cout<<ans;
}