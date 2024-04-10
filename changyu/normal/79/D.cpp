#include<bits/stdc++.h>
const int N=10003,K=20,M=103;
int n,t,m,a[N],nod[N],k,q[N],l,r,d[K][N],e[M],dp[1<<K];
int main(){
	int x,y;
	scanf("%d%d%d",&n,&t,&m);
	for(int i=0;i<t;i++)scanf("%d",&x),a[x]^=1,a[x+1]^=1;
	for(int j=1;j<=m;j++)scanf("%d",e+j);
	for(x=1;x<=n+1;x++)if(a[x])nod[k++]=x;
	for(int i=0;i<k;i++){
		d[i][q[l=r=0]=nod[i]]=1;
		for(;l<=r;){
			x=q[l++];
			for(int j=1;j<=m;j++){
				if((y=x+e[j])<=n+1&&!d[i][y])
					d[i][y]=d[i][x]+1,q[++r]=y;
				if((y=x-e[j])>=  1&&!d[i][y])
					d[i][y]=d[i][x]+1,q[++r]=y;
			}
		}
	}
	std::fill(dp,dp+(1<<k),N*K);
	dp[0]=0;
	for(int I=0;I<(1<<k);I++)
		for(int i=0;i<k;i++)if(~I>>i&1)
			for(int j=i+1;j<k;j++)if(~I>>j&1)
				if(d[i][nod[j]])dp[I|1<<i|1<<j]=std::min(dp[I|1<<i|1<<j],dp[I]+d[i][nod[j]]-1);
	printf("%d\n",dp[(1<<k)-1]==N*K?-1:dp[(1<<k)-1]);
	return 0;
}