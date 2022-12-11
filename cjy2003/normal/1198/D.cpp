#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline void upmin(int &x,int y){x>y?x=y:0;}
inline int qmax(int x,int y){return x>y?x:y;}
int n,dp[51][51][51][51],a[51][51];
int main()
{
	scanf("%d",&n);
	char ch;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='#';
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]+=a[i][j-1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a[i][j]+=a[i-1][j];
	for(int lenx=1;lenx<=n;++lenx)
		for(int leny=1;leny<=n;++leny)
			for(int i=1,k=i+lenx-1;k<=n;++i,++k)
				for(int j=1,l=j+leny-1;l<=n;++j,++l)
				{
					if(a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1]==0)continue;
					dp[i][j][k][l]=qmax(k-i+1,l-j+1);
					for(int p=i;p<k;++p)upmin(dp[i][j][k][l],dp[i][j][p][l]+dp[p+1][j][k][l]);
					for(int p=j;p<l;++p)upmin(dp[i][j][k][l],dp[i][j][k][p]+dp[i][p+1][k][l]);
				}
	printf("%d",dp[1][1][n][n]);
	return 0;
}