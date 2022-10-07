#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,m,r,s[1005][1005],i,j,x[10005],y[10005],z[10005];
long long fac[100005],inv[100005],ans;
int Sq(int a,int b,int x,int y)
{
	a=max(a,1),b=max(b,1);
	x=min(x,1000),y=min(y,1000);
	return s[x][y]-s[a-1][y]-s[x][b-1]+s[a-1][b-1];
}
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
long long C(int n,int m)
{
	if(n<m)
		return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main()
{
	scanf("%d %d %d",&n,&m,&r);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		++s[x[i]][y[i]];
	}
	fac[0]=1;
	for(i=1;i<=10000;++i)
		fac[i]=fac[i-1]*i%M;
	for(i=0;i<=10000;++i)
		inv[i]=qpow(fac[i],M-2);
	for(i=1;i<=1000;++i)
		for(j=1;j<=1000;++j)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j)
			{
				int a1=0,a2=0,a3=0;
				if(max(x[i],x[j])-r<=min(x[i],x[j])+r&&max(y[i],y[j])-r<=min(y[i],y[j])+r)
					a1=Sq(max(x[i],x[j])-r,max(y[i],y[j])-r,min(x[i],x[j])+r,min(y[i],y[j])+r);
				a2=Sq(x[i]-r,y[i]-r,x[i]+r,y[i]+r)-a1;
				a3=Sq(x[j]-r,y[j]-r,x[j]+r,y[j]+r)-a1;
				ans=(ans+(C(n,m)-C(n-a1,m))*z[i]%M*z[j])%M;
				ans=(ans+(C(n-a1,m)-C(n-a1-a2,m)-C(n-a1-a3,m)+C(n-a2-a3-a1,m))*z[i]%M*z[j])%M;
				//cout<<i<<' '<<j<<' '<<a1<<' '<<a2<<' '<<a3<<' '<<C(n,m)-C(n-a1,m)+C(n-a1,m)-C(n-a1-a2,m)-C(n-a1-a3,m)+C(n-a2-a3-a1,m)<<endl;
			}
			else
			{
				int a1=Sq(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
				ans=(ans+(C(n,m)-C(n-a1,m))*z[i]%M*z[i])%M;
			}
	cout<<(ans%M+M)%M;
}