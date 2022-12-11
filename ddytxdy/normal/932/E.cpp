#include<bits/stdc++.h>
using namespace std;
const int N=5050,mod=1e9+7;
int S[N][N],n,k,ans,A[N];
int power(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d%d",&n,&k);S[1][1]=1;A[1]=n;
	for(int i=2;i<=k;i++)A[i]=1ll*A[i-1]*(n-i+1)%mod;
	for(int i=2;i<=k;i++)for(int j=1;j<=i;j++)S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
	for(int i=1;i<=min(n,k);i++)ans=(ans+1ll*S[k][i]*power(2,n-i)%mod*A[i])%mod;
	printf("%d\n",ans);
	return 0;
}