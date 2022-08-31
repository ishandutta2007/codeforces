#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,mod=1e9+7,i,j,k,p,cnt[105],x,y;
struct juzhen
{
	long long a[105][105];
}a;
juzhen mul(juzhen x,juzhen y)
{
	juzhen ans;
	memset(ans.a,0,sizeof(ans.a));
	int i,j,k;
	for (i=0;i<p;i++)
	{
		for (j=0;j<p;j++)
		{
			for (k=0;k<p;k++)
			{
				(ans.a[i][j]+=x.a[i][k]*y.a[k][j])%=mod;
			}
		}
	}
	return ans;
}
juzhen qpower(juzhen x,int y)
{
	juzhen z;
	memset(z.a,0,sizeof(z.a));
	int i;
	for (i=0;i<p;i++) z.a[i][i]=1;
	while (y)
	{
		if (y&1) z=mul(z,x);
		y/=2;
		x=mul(x,x);
	}
	return z;
}
int main()
{
	cin>>n>>m>>k>>p;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	memset(a.a,0,sizeof(a.a));
	for (i=0;i<p;i++)
	{
		for (j=0;j<10;j++)
		{
			a.a[i][(i*10+j)%p]+=cnt[j];
		}
	}
	a=qpower(a,m);
	cout<<a.a[0][k]%mod<<endl;
	return 0;
}