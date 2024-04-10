#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-9;

int n,m,A,B;
bool mp[30][30]; int deg[30]; double p[30];

double a[510][510],b[510],ans[510]; int pos[510];
void gauss(int n)
{
	for (int i=1;i<=n;i++) pos[i]=i;
	for (int i=1;i<=n;i++)
	{
		int maxpos=i;
		for (int j=i+1;j<=n;j++) if (fabs(a[i][j])>fabs(a[i][maxpos])+eps) maxpos=i;
		//No Solution
		if (i^maxpos)
		{
			swap(pos[i],pos[maxpos]);
			for (int j=1;j<=n;j++) swap(a[j][i],a[j][maxpos]);
		}
		for (int j=i+1;j<=n;j++)
		{
			double tmp=a[j][i]/a[i][i];
			for (int u=i;u<=n;u++) a[j][u]-=tmp*a[i][u];
			b[j]-=tmp*b[i];
		}
	}
	for (int i=n;i;i--)
	{
		for (int j=i+1;j<=n;j++) b[i]-=ans[pos[j]]*a[i][j];
		ans[pos[i]]=b[i]/a[i][i];
	}
}
int gethash(int x,int y)
{
	return (x-1)*n+y;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&A,&B);
	if (n==1) return puts("1.000000000"),0;
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y); mp[x][y]=mp[y][x]=true; deg[x]++,deg[y]++;
	}
	for (int i=1;i<=n;i++) scanf("%lf",p+i);
	int x=gethash(A,B); b[x]+=-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			x=gethash(i,j);
			a[x][x]-=1;
			if (i==j) continue;
			for (int u=1;u<=n;u++)
				if (i==u||mp[i][u])
					for (int v=1;v<=n;v++)
						if (j==v||mp[j][v])
						{
							double y=(i==u?p[i]:(1-p[i])/deg[i])*(j==v?p[j]:(1-p[j])/deg[j]);   //caution deg i
							//printf("%d %d -> %d %d for %.5lf\n",i,j,u,v,y);
							a[gethash(u,v)][x]+=y;
						}
		}
	}
	/*for (int i=1;i<=n*n;printf(" %.5lf\n",b[i]),i++)
		for (int j=1;j<=n*n;j++)
			printf("%.5lf%c",a[i][j]," \n"[j==n*n+1]);*/
	gauss(n*n);
	for (int i=1;i<=n;i++) x=gethash(i,i),printf("%.9lf ",ans[x]); putchar('\n');
	return 0;
}