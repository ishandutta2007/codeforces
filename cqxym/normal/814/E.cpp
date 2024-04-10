#include<stdio.h>
#define R register int
#define L long long
#define P 1000000007
int d[301],f[301][301],fac[301],pw[301],g[301][301][301],C[301][4];
int main(){
	pw[0]=fac[0]=1;
	int n,ct[2]={0,0};
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",d+i);
		ct[d[i]-2]++;
		pw[i]=pw[i-1];
		if((pw[i]&1)==1){
			pw[i]+=P;
		}
		pw[i]>>=1;
		fac[i]=(L)fac[i-1]*i%P;
	}
	for(R i=0;i<=n;i++){
		C[i][0]=1;
		for(R j=1;j!=4&&j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	g[0][0][0]=1;
	for(R i=0;i<=n;i++){
		for(R j=1;j<=n;j++){
			for(R k=0;k<=ct[1]&&k<=j;k++){
				if(k!=0){
					for(R a=0;a!=3&&a<=j-k;a++){
						for(R b=0;b!=3-a&&b!=k;b++){
							int deg=2-a-b,x=j-k-a+b,y=k-b-1;
							if(deg<=i){
								g[i][j-k][k]=((L)C[j-k][a]*C[k-1][b]%P*g[i-deg][x][y]%P*pw[deg==2]+g[i][j-k][k])%P;
							}
						}
					}
				}else{
					for(R a=0;a!=2&&a!=j;a++){
						int deg=a^1,x=j-a-1;
						if(i>=deg){
							g[i][j][0]=((L)g[i-deg][x][0]*C[j-1][a]+g[i][j][0])%P;
						} 
					}
				}
			}
		}
	}
	f[1][d[1]]=(P+1)/fac[d[1]];
	for(R i=2;i<=n;i++){
		ct[0]=ct[1]=0;
		for(R j=i;j!=1;j--){
			ct[d[j]-2]++;
			for(R k=0;k<=n;k++){
				f[i][k]=((L)g[k][ct[0]][ct[1]]*f[j-1][i-j+1]%P*fac[i-j+1]+f[i][k])%P;
			}
		}
	}
	printf("%d",f[n][0]);
	return 0;
}