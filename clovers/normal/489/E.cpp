#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
const double inf=1e9;
const int N=2001;
double dp[N],x[N],b[N],l;
int n,pre[N],a[N];
int c[N],tot=0;
bool check(double ans)
{
	memset(pre,-1,sizeof(pre));
	dp[0]=0; x[0]=0.0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=inf;
		for(int j=0;j<i;j++) 
		{
			if(dp[i]>dp[j]+sqrt(fabs(x[i]-x[j]-l))-ans*b[i])
			{
				dp[i]=dp[j]+sqrt(fabs(x[i]-x[j]-l))-ans*b[i];
				pre[i]=j;
			}
		}
	}
	double mi=inf;
	for(int i=1;i<=n;i++) mi=min(mi,dp[i]);
	if(dp[n]<=0) //n3pre 
	{
		for(int i=1;i<=n;i++) a[i]=pre[i];
		return 1;
	}
	else return 0;
}
 
int main()
{
	scanf("%d%lf",&n,&l);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&b[i]);
	double L=0.0,R=inf;
	while(R-L>eps)
	{
		double mid=(L+R)/2.0;
		if(check(mid)) R=mid;
		else L=mid;
	}
	int now=n; 
	while(now) 
	{
		c[++tot]=now;
		now=a[now];
	}
	for(int i=tot;i>=1;i--) printf("%d ",c[i]);
	return 0;
}