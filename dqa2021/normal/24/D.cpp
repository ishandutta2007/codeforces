#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-9;

int n,m,x,y;
double a[1010][1010],b[1010];
double dp[1010][1010];
void gauss(int n,int k,double *ans)
{
	for (int i=1;i<=n;i++)
	{
		int pos=-1;
		for (int j=i;j<=n&&j<=i+k;j++) if (fabs(a[j][i])>eps) {pos=j;break;}
		if (pos==-1) continue;
		if (pos^i) for (int j=i;j<=i+k+k&&j<=n;j++) swap(a[i][j],a[pos][j]);
		for (int j=pos+1;j<=n&&j<=i+k;j++)
		{
			double tmp=a[j][i]/a[i][i];
			for (int u=i;u<=n&&u<=i+k+k;u++) a[j][u]-=a[i][u]*tmp;
			b[j]-=b[i]*tmp;
		}
	}
	for (int i=n;i;i--)
	{
		for (int j=i+1;j<=n&&j<=i+k+k;j++) b[i]-=a[i][j]*ans[j];
		//a[i][i]=0 then No solution
		ans[i]=b[i]/a[i][i];
	}
	
	for (int i=1;i<=n;i++)
		for (int j=i;j<=i+k+k&&j<=n;j++) a[i][j]=0;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	scanf("%d%d%d%d",&n,&m,&x,&y);
	if (m==1) return printf("%d.00000000\n",(n-x<<1)),0;
	if (x==n) return puts("0.00000000"),0;
	for (int i=n-1;i>=x;i--)
	{
		a[1][1]=-2.0/3,a[1][2]=1.0/3;  //caution n and m
		a[m][m-1]=1.0/3,a[m][m]=-2.0/3;
		for (int i=2;i<m;i++)
		{
			a[i][i-1]=a[i][i+1]=1.0/4;
			a[i][i]=-3.0/4;
		}
		for (int j=1;j<=m;j++) b[j]=(j==1||j==m?-1.0/3:-1.0/4)*dp[i+1][j]-1;
		gauss(m,1,dp[i]);
	}
	/*for (int i=x;i<=n;i++)
		for (int j=1;j<=m;j++)
			printf("%.6lf%c",dp[i][j]," \n"[j==m]);*/
	printf("%.8lf\n",dp[x][y]);
	return 0;
}