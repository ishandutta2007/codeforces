#include<cstdio>
typedef long long ll;
const int N=10001,K=52,M=1e9+7;
int f[K][N][K+1],g[K][N][K+1],n,inv[K+1],alpha[15],k,ans;ll a,p[15];
void Dfs(int t,ll d,int s){
	if(t>k){ans=(ans+d%M*s)%M;return;}
	ll la=1;
	for(int i=0;i<=alpha[t];i++)
	  Dfs(t+1,la*d,1ll*f[alpha[t]][n][i]*s%M),la*=p[t];
}
int main(){
	scanf("%I64d%d",&a,&n);
	inv[1]=1;
	for(int i=2;i<=K;i++)inv[i]=1ll*inv[M%i]*(M-M/i)%M;
	for(int i=0;i<K;i++){
	  f[i][0][i]=1;
	  for(int k=i;k>=0;k--)g[i][0][k]=(1ll*f[i][0][k]*inv[k+1]+g[i][0][k+1])%M;
	  for(int j=1;j<=n;j++)
		for(int k=i;k>=0;k--){
		  f[i][j][k]=(f[i][j][k]+1ll*g[i][j-1][k])%M;
		  g[i][j][k]=(1ll*f[i][j][k]*inv[k+1]+g[i][j][k+1])%M;
		}
	}
	for(ll i=2;i*i<=a;i++)
	  if(a%i==0){
		p[++k]=i;
		while(a%i==0)a/=i,alpha[k]++;
	  }
	if(a>1)p[++k]=a,alpha[k]=1;
	Dfs(1,1,1);
	printf("%d",ans);
	return 0;
}