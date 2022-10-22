#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,h,x[2010],L[2010],R[2010],vis[2001][2001][2][2];
double dp[2001][2001][2][2],P; //left 0   right 1
double fun(int l,int r,int f1,int f2)
{
	if(l>r) return 0;
	if(vis[l][r][f1][f2]) return dp[l][r][f1][f2];
	vis[l][r][f1][f2]=1;
	if(l==r)
	{
		dp[l][r][f1][f2]+=P*min(h,x[l]-x[l-1]-(f1==1)*h);
		dp[l][r][f1][f2]+=(1.0-P)*min(h,x[r+1]-x[r]-(f2==0)*h);
		return dp[l][r][f1][f2];
	}
	//---------------
	//left to left
	dp[l][r][f1][f2]+=0.5*P*(fun(l+1,r,0,f2)+min(h,x[l]-x[l-1]-(f1==1)*h));
	//left to right
	dp[l][r][f1][f2]+=0.5*(1.0-P)*(fun(l+R[l]+1,r,1,f2)+(l+R[l]<r?x[l+R[l]]-x[l]+h:x[r]-x[l]+min(h,x[r+1]-x[r]-(f2==0)*h)));
	//right to left
	dp[l][r][f1][f2]+=0.5*P*(fun(l,r-L[r]-1,f1,0)+(r-L[r]>l?x[r]-x[r-L[r]]+h:x[r]-x[l]+min(h,x[l]-x[l-1]-(f1==1)*h)));
	//right to right
	dp[l][r][f1][f2]+=0.5*(1.0-P)*(fun(l,r-1,f1,1)+min(h,x[r+1]-x[r]-(f2==0)*h));
	//---------------
	return dp[l][r][f1][f2];
}
int main()
{
	n=read(),h=read();
	scanf("%lf",&P);
	for(int i=1;i<=n;++i) x[i]=read();
	sort(x+1,x+n+1);
	for(int i=n-1;i>=1;--i) if(h>x[i+1]-x[i]) R[i]=R[i+1]+1;
	for(int i=2;i<=n;++i) if(h>x[i]-x[i-1]) L[i]=L[i-1]+1;
	x[0]=-0x3f3f3f3f;
	x[n+1]=0x3f3f3f3f;
	printf("%.6lf\n",fun(1,n,0,1));
	return 0;
}