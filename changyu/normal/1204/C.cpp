#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
const int N=102,M=1e6+3,INF=1e8;
int n,m,d[N][N],dp[M],fa[M],w[M],b[M];char t[N][N];
void Out(int i){
	if(i>1)Out(fa[i]);
	printf("%d ",w[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%s",t[i]+1);
	  for(int j=1;j<=n;j++)d[i][j]=t[i][j]=='1'?1:INF;
	  d[i][i]=0;
	}
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	 	for(int j=1;j<=n;j++)
		  d[i][j]=min(d[i][j],d[i][k]+d[k][j]); 
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	dp[1]=1;
	for(int i=2;i<=m;i++){
	  b[i]=b[i-1]+d[w[i-1]][w[i]];
	  for(int j=max(1,i-n);j<i;j++)
		if(b[i]-b[j]==d[w[j]][w[i]])
		  {dp[i]=dp[j]+1,fa[i]=j;break;}
	}printf("%d\n",dp[m]);
	Out(m);
	return 0;
}