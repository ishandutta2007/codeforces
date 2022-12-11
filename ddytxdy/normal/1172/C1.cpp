#include<bits/stdc++.h>
using namespace std;
const int N=60,mod=998244353;
int n,m,f[N*2][N][N],a[N],w[N],mx,S[2],g[N*2][N][N],ans;
int power(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]),mx=max(mx,w[i]),S[a[i]]+=w[i];
	for(int i=1;i<=mx+m;i++)for(int j=0;j<=m;j++)f[i][j][m-j]=g[i][j][m-j]=i;
	for(int i=m-1;~i;i--){
		for(int j=0;j<=i;j++){
			int k=i-j;if(k>S[0])continue;
			int s1=S[1]+j,s0=S[0]-k,sum=s1+s0,inv=power(sum,mod-2);
			for(int l=1;l<=mx+i;l++)
				f[l][j][k]=(1ll*l*f[l+1][j+1][k]+1ll*(s1-l)*f[l][j+1][k]+1ll*s0*f[l][j][k+1])%mod*inv%mod,
				g[l][j][k]=(1ll*l*g[l-1][j][k+1]+1ll*(s0-l)*g[l][j][k+1]+1ll*s1*g[l][j+1][k])%mod*inv%mod;
		}
	}
	for(int i=1;i<=n;i++)cout<<(a[i]?f[w[i]][0][0]:g[w[i]][0][0])<<endl;
	return 0;
}