#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int f[9][256],g[9][256];
int N,K,a[5004],s[5004][5004];
void chmin(int &x,int y){if(x>y)x=y;}
int main(){
	scanf("%d%d",&N,&K);if(K>=N-1)return puts("0"),0;
	for(int i=1,x;i<=N;i++)scanf("%d",&x),a[x]=i;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)s[i][j]=s[i][j-1]+(a[i]<a[j]);
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=K;i++)f[i][(1<<(K-i))-1]=0;
	for(int t=2;t<=N;t++){
		memset(g,0x3f,sizeof(g));
		for(int i=0,d=t-1;i<=min(N-(t-1),K);i++,d++)
			for(int j=0;j<(1<<K);j++)if(f[i][j]<inf){
				for(int k=0;k<K;k++)if(!((j>>k)&1)){
					int v=d-K+k,z=d-K-1,val=z<1?0:s[v][z];
					val+=a[d]>a[v];
					for(int p=0;p<K;p++)if((j>>p)&1){
						z=d-K+p;
						if(z>0)val+=a[z]>a[v];
					}
					chmin(g[i-1][j|(1<<k)],f[i][j]+val);
				}
				for(int k=d+1;k<=min(t+K,N);k++){
					int len=k-d,msk=(1<<len)-1;
					if(K<len)msk=(1<<K)-1;
					if((j&msk)!=msk)continue;
					int z=d-K-1,val=z<1?0:s[k][z];
					val+=a[d]>a[k];
					for(int p=0;p<K;p++)if((j>>p)&1){
						z=d-K+p;
						if(z>0)val+=a[z]>a[k];
					}
					int nj=(j>>len);
					if(K>=len)nj|=(1<<(K-len));
					chmin(g[k-t][nj],f[i][j]+val);
				}
			}
		memcpy(f,g,sizeof(f));
	}
	printf("%d",f[0][(1<<K)-1]);
}