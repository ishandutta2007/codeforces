#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int n,m,K,ans;
int C[103][103];
int f[103][103][103],nf[103][103][103];
int main(){
	for(int i=0;i<=100;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=min(C[i-1][j]+C[i-1][j-1],(int)200);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++)f[i][i][1]=1;
	for(int i=2;i<=m;i++){
		memset(nf,0,sizeof(nf));
		for(int j=1;j<=n;j++)for(int k=1;k<=j;k++)for(int l=1;l<=K;l++)if(f[j][k][l])
			for(int t=k;j+t<=n;t++)if(C[t-1][k-1]*l<=K)
				add(nf[j+t][t-k][C[t-1][k-1]*l],f[j][k][l]);
		memcpy(f,nf,sizeof(f));
		int tmp=0;
		for(int j=1;j<=n;j++)for(int k=1;k<=K;k++)add(tmp,f[j][0][k]);
		add(ans,(ll)tmp*(m-i+1)%M);
	}
	printf("%d",ans);
}