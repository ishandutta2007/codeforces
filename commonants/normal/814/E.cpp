#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
const int MX=51,md=1000000007;
int n,d[MX];
int fac[MX],inv[MX],facinv[MX];

int f[MX][MX],g[MX][MX][MX];
#define C(x,y) ((LL)fac[x]*facinv[y]%md*facinv[x-y]%md)
void ini(){
	fac[0]=facinv[0]=1;
	inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(LL)inv[md%i]*(md-md/i)%md;
	for(int i=1;i<=n;i++)fac[i]=(LL)fac[i-1]*i%md;
	for(int i=1;i<=n;i++)facinv[i]=(LL)facinv[i-1]*inv[i]%md;
	g[0][0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n-i;j++)if(i||j){
			if(!i){
				for(int k=2;k<j;k++)g[0][i][j]=(g[0][i][j]+(LL)g[0][i][j-1-k]*C(j-1,k)%md*((LL)fac[k]*inv[2]%md)%md)%md;
			}else{
				if(i>=2)g[0][i][j]=(g[0][i][j]+(LL)g[0][i-2][j]*(i-1)%md)%md;
				if(j>=1)g[0][i][j]=(g[0][i][j]+(LL)g[0][i][j-1]*j%md)%md;
			}
		}
	for(int i=1;i<n;i++){
		for(int s=0;s<n-i;s++){
			for(int k=0;k<=s;k++){
				int j=s-k;
				if(j||k){
					if(j)g[i][j][k]=(g[i][j][k]+(LL)g[i-1][j-1][k]*j%md)%md;
					if(k)g[i][j][k]=(g[i][j][k]+(LL)g[i-1][j+1][k-1]*k%md)%md;
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	ini();
	f[d[1]+1][d[1]]=1;
	for(int i=d[1]+2;i<=n;i++){
		for(int j=1;j<=i-d[1]-1;j++){
			int cl0=0,cl1=0;
			for(int k=1;k<i-j;k++){
				if(d[i-j-k+1]==2)cl0++;else cl1++;
				f[i][j]=(f[i][j]+(LL)g[j][cl0][cl1]*f[i-j][k]%md)%md;
			}
		}
	}
	int ans=0,cc0=0,cc1=0;
	for(int i=1;i<n;i++){
		if(d[n-i+1]==2)cc0++;else cc1++;
		ans=(ans+(LL)f[n][i]*g[0][cc0][cc1]%md)%md;
	}
	printf("%d\n",ans);
	return 0;
}