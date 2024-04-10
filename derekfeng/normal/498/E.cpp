#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int N=7,m;
int n,w[8],h[8];
int f[130],g[130];
int dp[8][2];
int mat1[130][130],mat2[130][130];
int tam1[130][130],tam2[130][130];
int main(){
	for(int i=1;i<=N;i++){
		int x;scanf("%d",&x);
		if(x>0)w[++n]=x,h[n]=i;
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		memset(g,0,sizeof(g));
		for(int j=0;j<(1<<h[i-1]);j++){
			int nj=j;
			for(int k=h[i-1];k<h[i];k++)nj|=(1<<k);
			g[nj]=f[j];
		}
		m=(1<<h[i]);
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++)mat1[j][k]=0;
			mat1[j][j]=1;
		}
		for(int j=0;j<m;j++)for(int k=0;k<m;k++){
			memset(dp,0,sizeof(dp));
			dp[h[i]][1]=1;
			for(int l=h[i]-1;~l;l--){
				int ld=(j>>l)&1,rd=(k>>l)&1;
				for(int s=0;s<2;s++){
					(dp[l][0]+=dp[l+1][s])%=M;
					if(s==0||ld==0||rd==0)(dp[l][1]+=dp[l+1][s])%=M;
				}
			}
			mat2[j][k]=dp[0][1];
		}
		int W=w[i];
		for(;W;){
			if(W&1){
				for(int j=0;j<m;j++)for(int k=0;k<m;k++)tam1[j][k]=0;
				for(int j=0;j<m;j++)for(int k=0;k<m;k++)for(int l=0;l<m;l++)
					(tam1[j][l]+=(ll)mat1[j][k]*mat2[k][l]%M)%=M;
				for(int j=0;j<m;j++)for(int k=0;k<m;k++)mat1[j][k]=tam1[j][k];
			}
			for(int j=0;j<m;j++)for(int k=0;k<m;k++)tam2[j][k]=0;
			for(int j=0;j<m;j++)for(int k=0;k<m;k++)for(int l=0;l<m;l++)
				(tam2[j][l]+=(ll)mat2[j][k]*mat2[k][l]%M)%=M;
			for(int j=0;j<m;j++)for(int k=0;k<m;k++)mat2[j][k]=tam2[j][k];
			W/=2;
		}
		memset(f,0,sizeof(f));
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				(f[k]+=(ll)g[j]*mat1[j][k]%M)%=M;
	}
	printf("%d",f[((1<<h[n])-1)]);
}