#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
long long n,m,i,j,dp[1005][1565],ans1;
double dp2[1005][1565],ans2;
struct ii
{
	double ss,sl,ts,tl,pf;
	long long ss2,sl2,ts2,tl2,pf2;
}num[1005];
bool cmp(ii x,ii y)
{
	return x.tl*x.pf/(1-x.pf)<y.tl*y.pf/(1-y.pf);
}
void upd(int x,int y,long long f,double g)
{
	if (x>n+1) return;
	if (y>m) return;
	if (f<dp[x][y]) return;
	if (f==dp[x][y]&&g>dp2[x][y]) return;
	dp[x][y]=f;
	dp2[x][y]=g;
	if (f>ans1)
	{
		ans1=f;
		ans2=g;
	}
	if (f==ans1&&g<ans2) ans2=g;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf%lf",&num[i].ss,&num[i].sl,&num[i].ts,&num[i].tl,&num[i].pf);
		num[i].ss2=(long long)(num[i].ss*1000000+0.5);
		num[i].sl2=(long long)(num[i].sl*(1-num[i].pf)*1000000+0.5);
		num[i].ts2=(long long)(num[i].ts*1000000+0.5);
		num[i].tl2=(long long)(num[i].tl*1000000+0.5);
		num[i].pf2=(long long)(num[i].pf*1000000+0.5);
		//cerr<<num[i].tl2*num[i].pf2/(1000000-num[i].pf2)<<endl;
	}
	sort(num+1,num+n+1,cmp);
	/*for (i=1;i<=n;i++)
	{
		printf("%lf %lf %lf %lf %lf\n",num[i].ss,num[i].sl,num[i].ts,num[i].tl,num[i].pf);
	}*/
	for (i=1;i<=n;i++)
	{
		//cerr<<num[i].ss<<endl;
		for (j=0;j<=m;j++)
		{
			upd(i+1,j,                             dp[i][j],                      dp2[i][j]);
			upd(i+1,j+num[i].ts+0.000001,          dp[i][j]+num[i].ss2,           dp2[i][j]+num[i].ts);
			upd(i+1,j+num[i].ts+num[i].tl+0.000001,dp[i][j]+num[i].ss2+num[i].sl2,(dp2[i][j]+num[i].ts)*num[i].pf+(j+num[i].ts+num[i].tl)*(1-num[i].pf));
		}
	}
	/*for (i=2;i<=n+1;i++)
	{
		//cerr<<num[i].ss<<endl;
		for (j=0;j<=m;j++)
		{
			cerr<<dp[i][j]<<' ';
		}
		cerr<<endl;
	}
	for (i=2;i<=n+1;i++)
	{
		//cerr<<num[i].ss<<endl;
		for (j=0;j<=m;j++)
		{
			cerr<<dp2[i][j]<<' ';
		}
		cerr<<endl;
	}*/
	printf("%.12f %.12f\n",ans1/1000000.0,ans2);
	return 0;
}