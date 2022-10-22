#include<cstdio>
const int N=1002;
int n,m,b[N][N],c[N][N][3],q[N],l,r,ans;char a[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
	  scanf("%s",a[i]+1);
	  for(int j=1;j<=m;j++){
		b[i][j]=a[i][j]==a[i][j-1]?b[i][j-1]+1:1;
		if(a[i][j]==a[i-1][j])
		  c[i][j][2]=c[i-1][j][2],c[i][j][1]=c[i-1][j][1],c[i][j][0]=c[i-1][j][0]+1;
		else
		  c[i][j][2]=c[i-1][j][1],c[i][j][1]=c[i-1][j][0],c[i][j][0]=1;
	  }
	}
	for(int j=1;j<=m;j++)
	{
	  l=0,r=-1;
	  for(int i=1;i<=n;i++)
	  {
		for(;l<=r&&b[q[r]][j]>=b[i][j];r--);
		q[++r]=i;
		if(c[i][j][0]==c[i][j][1]&&c[i][j][1]<=c[i][j][2]){
		  for(;l<=r&&q[l]<=i-c[i][j][0]*3;l++);
		  ans+=b[q[l]][j];
		}
	  }
	}
	printf("%d",ans);
	return 0;
}