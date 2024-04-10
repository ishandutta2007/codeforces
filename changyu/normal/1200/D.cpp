#include<cstdio>
#define max(a,b)((a)>(b)?(a):(b))
const int N=2005;
int n,m,b0[N][N],b1[N][N],b2[N][N],b3[N][N],c0[N][N],c1[N][N],p0[N],p1[N],ans;char a[N][N];
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++){
	  p0[i]=1;
	  for(int j=1;j<=n;j++)
		if(a[i][j]=='B')p0[i]=0;
	  p0[i]+=p0[i-1];
	}
	for(int j=1;j<=n;j++){
	  p1[j]=1;
	  for(int i=1;i<=n;i++)
		if(a[i][j]=='B')p1[j]=0;
	  p1[j]+=p1[j-1];
	}
	for(int i=0;i<=n+1;i++){
	  b0[i][0]=1;
	  for(int j=1;j<=n;j++)
		b0[i][j]|=a[i][j]=='B'?0:b0[i][j-1];
	  b1[i][n+1]=1;
	  for(int j=n;j;j--)
		b1[i][j]|=a[i][j]=='B'?0:b1[i][j+1];
	}
	for(int j=0;j<=n+1;j++){
	  b2[0][j]=1;
	  for(int i=1;i<=n;i++)
		b2[i][j]|=a[i][j]=='B'?0:b2[i-1][j];
	  b3[n+1][j]=1;
	  for(int i=n;i;i--)
		b3[i][j]|=a[i][j]=='B'?0:b3[i+1][j];
	}
	for(int i=m;i<=n;i++)
	  for(int j=1;j<=n;j++)
		c0[i][j]=c0[i][j-1]+(b2[i-m][j]&&b3[i+1][j]);
	for(int i=1;i<=n;i++)
	  for(int j=m;j<=n;j++)
		c1[i][j]=c1[i-1][j]+(b0[i][j-m]&&b1[i][j+1]);
	for(int i=m;i<=n;i++)
	  for(int j=m;j<=n;j++)
		ans=max(ans,c0[i][j]-c0[i][j-m]+c1[i][j]-c1[i-m][j]+p0[n]-(p0[i]-p0[i-m])+p1[n]-(p1[j]-p1[j-m]));
	printf("%d",ans);
	return 0;
}