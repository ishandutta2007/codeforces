#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int F[2003][2003];
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)
			ret=1ll*ret*x%mod;
		times>>=1;
		x=1ll*x*x%mod;
	}return ret;
}
int main(){
	F[0][0]=1;
	for(int i=1;i<2003;i++)
		for(int j=1;j<=i;j++)
			F[i][j]=(1ll*j*F[i-1][j]+F[i-1][j-1])%mod; 
	int T;
	cin>>T;
	while(T--){
		int n,m,k,pw=1,val=1,ans=0;
		scanf("%d%d%d",&n,&m,&k);
		val=1ll*(m+1)/2*mypow(m,mod-2)%mod;
		for(int i=1;i<=k;i++){
			pw=1ll*pw*val%mod*(n+1-i)%mod;
			ans=(ans+1ll*pw%mod*F[k][i])%mod;
		}cout<<1ll*ans*mypow(m,n)%mod<<endl;
	}
}