#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const long long M=998244353;
const long long iv2=499122177;
int n,i,t,m,j,f[N],u[N],vis[N],a[N],k,x;
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	scanf("%d",&n);
	if(n<=3)
	{
		cout<<0<<endl;
		return 0;
	}
	for(i=1;i<=n;++i)
		if(i*i>=n)
			break;
	int t=i;
	int p=n/t;
	int tmp=n;
	for(i=1;i<t;++i)
	{
		u[i]=p;
		tmp-=p;
	}
	while(tmp&&u[t]<=p)
	{
		++u[t];
		--tmp;
	}
	for(i=1;i<=tmp;++i)
		++u[i];
	int s=0,mx=0;
	for(i=1;i<=t;++i)
		mx=max(mx,u[i]);
	for(i=1;i<=n;++i)
	{
		for(j=s+1;j<s+min(u[i],t);++j)
			f[j]=1;
		s+=u[i];
	}
	while(1)
	{
		k=0;
		for(j=1;j<=n&&k<mx;++j)
			if(f[j]!=vis[j])
			{
				vis[j]=1;
				a[++k]=j;
			}
		if(k<mx)
		{
			cout<<0<<endl;
			break;
		}
		cout<<k<<' ';
		for(j=1;j<=k;++j)
			cout<<a[j]<<' ';
		cout<<endl;
		scanf("%d",&x);
		j=k;
		while(j--)
		{
			vis[x]=0;
			x=x%n+1;
		}
	}
}