#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=998244353,M=3030;
int n,m,f[M][M],a[N],w[N],mx,S[2],g[M][M],ans,inv[N];
int power(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]),mx=max(mx,w[i]),S[a[i]]+=w[i];
	for(int j=0;j<=m;j++)f[j][m-j]=g[j][m-j]=1;
	for(int i=-m;i<=m;i++)inv[i+m]=power(S[0]+S[1]+i,mod-2);
	for(int i=m-1;~i;i--)
		for(int j=0;j<=i;j++){
			int k=i-j;if(k>S[0])continue;
			int s1=S[1]+j,s0=S[0]-k,sum=s1+s0,I=inv[j-k+m];
			f[j][k]=(2ll*f[j+1][k]+1ll*(s1-1)*f[j+1][k]+1ll*s0*f[j][k+1])%mod*I%mod,
			g[j][k]=(1ll*(s0-1)*g[j][k+1]+1ll*s1*g[j+1][k])%mod*I%mod;
		}
	for(int i=1;i<=n;i++)cout<<1ll*(a[i]?f[0][0]:g[0][0])*w[i]%mod<<endl;
	return 0;
}