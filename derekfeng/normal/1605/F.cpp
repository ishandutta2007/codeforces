#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,M;
int C[83][83],pw[6403];
int f[83][83],g[83][83],tot[83][83];
int main(){
	scanf("%d%d%d",&n,&K,&M);
	for(int i=0;i<=80;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	for(int i=0;i<=6400;i++)pw[i]=i==0?1:(pw[i-1]*2%M);
	tot[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=K;j++)
		for(int k=0;k<=j;k++)(tot[i][j]+=(ll)tot[i-1][k]*pw[k]%M*C[j][k]%M)%=M;
	g[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=K;j++){
		g[i][j]=(ll)g[i-1][j]*(pw[j]-i+M)%M;
		for(int k=0;k<j;k++)(g[i][j]+=(ll)g[i-1][k]*pw[k]%M*C[j][k]%M)%=M;
	}
	for(int i=1;i<=n;i++)for(int j=0;j<=K;j++)
		for(int w1=0;w1<i;w1++)for(int w2=0;w2<j;w2++){
			if((n&1)&&w1==n-1&&i==n)continue;
			int mul=(ll)C[i][w1]*C[j][w2]%M*pw[(i-w1)*w2]%M;
			(f[i][j]+=(ll)(tot[w1][w2]-f[w1][w2]+M)%M*mul%M*g[i-w1][j-w2]%M)%=M;
		}
	int ans=0;
	for(int i=0;i<=K;i++)(ans+=(ll)(tot[n][i]-f[n][i]+M)*C[K][i]%M)%=M;
	printf("%d",ans);
}