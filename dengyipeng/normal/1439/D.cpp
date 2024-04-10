#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 505
#define ll long long 
using namespace std;

int n,m,mo,i,j,k;
ll f[maxn],g[maxn],C[maxn][maxn],ans;
ll f0[maxn][maxn],g0[maxn][maxn];
ll P(int n,int m){return C[n+m-1][m-1];}

int main(){
	scanf("%d%d%d",&n,&m,&mo);
	for(C[0][0]=1,i=1;i<=n+1;i++) for(C[i][0]=1,j=1;j<=i;j++)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	f[0]=1,g[0]=0,f[1]=2,g[1]=0;
	for(i=2;i<=n;i++) {
		(f[i]+=f[i-1]*(i+1)*2)%=mo;
		(g[i]+=f[i-1]*i%mo*(i-1))%=mo;
		(g[i]+=g[i-1]*(i+1)*2)%=mo;
		for(j=1;j+1<i;j++){ 
			k=i-j-1;
			(f[i]+=f[j]*f[k]%mo*(j+k+2)%mo*C[j+k][k])%=mo;
			(g[i]+=(g[j]*f[k]+g[k]*f[j])%mo*(j+k+2)%mo*C[j+k][k])%=mo;
			(g[i]+=f[j]*f[k]%mo*C[j+k][k]%mo*((1ll*(j+1)*j/2+1ll*(k+1)*k/2)%mo))%=mo;
		}
	}
	f0[0][0]=1,g0[0][0]=0;
	for(i=0;i<=m;i++) for(j=0;j<=m;j++) if (f0[i][j]){
		for(k=1;j+k<=m;k++){
			(f0[i+1][j+k]+=f0[i][j]*f[k]%mo*C[j+k][k])%=mo;
			(g0[i+1][j+k]+=(g0[i][j]*f[k]+f0[i][j]*g[k])%mo*C[j+k][k])%=mo;
		}
	}
	for(i=1;i<=m;i++) if (n+1-m-i>=0)
		(ans+=g0[i][m]*P(n+1-m-i,i+1))%=mo;
	printf("%lld\n",ans);
}