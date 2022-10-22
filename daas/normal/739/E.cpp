#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
double eps=1e-9;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,A,B,cntp[2001],cntq[2001];
double p[2001],q[2001],dp[2001],ANS;
int solve(double W1,double W2)
{
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1];
		cntp[i]=cntp[i-1];
		cntq[i]=cntq[i-1];
		double v1=dp[i-1]+p[i]+W1;
		if(fabs(v1-dp[i])>eps && v1>dp[i]) dp[i]=v1,cntp[i]=cntp[i-1]+1,cntq[i]=cntq[i-1];
		double v2=dp[i-1]+q[i]+W2;
		if(fabs(v2-dp[i])>eps && v2>dp[i]) dp[i]=v2,cntp[i]=cntp[i-1],cntq[i]=cntq[i-1]+1;
		double v3=dp[i-1]+p[i]+q[i]-p[i]*q[i]+W1+W2;
		if(fabs(v3-dp[i])>eps && v3>dp[i]) dp[i]=v3,cntp[i]=cntp[i-1]+1,cntq[i]=cntq[i-1]+1;
	}
	return cntq[n]<=B;
}
int check(double W)
{
	double l=-1,r=0;
	int bck;
	while(fabs(l-r)>eps)
	{
		double mid=(l+r)/2.0;
		if(solve(W,mid)) bck=cntp[n],ANS=dp[n]-B*mid,l=mid;
		else r=mid;
	}
	return bck<=A;
}
int main()
{
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;++i) scanf("%lf",&p[i]);
	for(int i=1;i<=n;++i) scanf("%lf",&q[i]);
	double l=-1,r=0,ans;
	while(fabs(l-r)>eps)
	{
		double mid=(l+r)/2.0;
		if(check(mid)) ans=ANS-A*mid,l=mid;
		else r=mid;
	}
	printf("%.4lf\n",ans);
	return 0;
}