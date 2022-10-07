#include<bits/stdc++.h>
using namespace std;
const int M=31607,L=5000,N=1000005;
int n,i,t,m,j,a[25][25],ans,f[N*3],tmp[N*3],d[25],b[25][25];
int qpow(int a,int b)
{
	int s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int cal()
{
	for(i=0;i<(1<<n);++i)
		f[i]=1;
	for(i=1;i<=n;++i)
	{
		tmp[0]=1;
		for(j=1;j<(1<<n);++j)
			tmp[j]=tmp[j^(-j&j)]*a[i][__lg(-j&j)+1]%M;
		for(j=0;j<(1<<n);++j)
			f[j]=f[j]*(-tmp[j]+1)%M;
	}
//	for(i=0;i<(1<<n);++i)
//		cout<<f[i]<<' ';
//	cout<<endl;
	for(i=1;i<=n;++i)
	{
		d[i]=1;
		for(j=1;j<=n;++j)
			d[i]=d[i]*a[j][i]%M;
	}
	int ans=0;
	for(i=0;i<(1<<n);++i)
	{
		int s=f[((1<<n)-1)^i];
		for(j=0;j<n;++j)
			if(i>>j&1)
				s=s*(-d[j+1])%M;
		ans=(ans+s)%M;
	}
	//cout<<(ans%M+M)%M<<endl;
	return ans%M;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	int iv=qpow(10000,M-2);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			scanf("%d",&b[i][j]);
			b[i][j]=b[i][j]*iv%M;
		}
	//cout<<qpow(b[1][1],4)*9%M<<endl;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			a[i][j]=b[i][j];
	ans+=1-cal();
	int s=1;
	for(i=1;i<=n;++i)
	{
		s=s*a[i][i]%M;
		a[i][i]=1;
	}
	ans+=cal()*s;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			a[i][j]=b[i][j];
	s=1;
	for(i=1;i<=n;++i)
	{
		s=s*a[n-i+1][i]%M;
		a[n-i+1][i]=1;
	}
	ans+=cal()*s;
	for(i=1;i<=n;++i)
	{
		s=s*a[i][i]%M;
		a[i][i]=1;
	}
	ans-=cal()*s;
	cout<<(ans%M+M)%M;
}