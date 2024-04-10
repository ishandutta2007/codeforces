//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,x[100005],y[100005],z[100005],fa[100005],sum[100005],ans;
char c[100005];
int power(int a,int b,int mod)
{
	int tmp=1;
	while(b)
	{
		if(b&1)
		{
			tmp=tmp*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return tmp;
}
int find(int now)
{
	if(fa[now]==now)
	{
		return now;
	}
//	int tmp=fa[now];
	find(fa[now]);
	sum[now]^=sum[fa[now]];
	return fa[now]=fa[fa[now]];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n+5;++i)
	{
		fa[i]=i;
	}
	ans=n;
	for(int i=1;i<=k;++i)
	{
		cin>>x[i]>>y[i]>>c[i];
		z[i]=(c[i]=='o');
		int x1=x[i],y1=y[i],x2=x[i],y2=y[i],tmp;
		tmp=min(x1,y1)-1;
		x1-=tmp;
		y1-=tmp;
		tmp=x1-1;
		x1-=tmp;
		y1+=tmp;
		tmp=min(x2,n-y2+1)-1;
		x2-=tmp;
		y2+=tmp;
		tmp=x2-1;
		x2-=tmp;
		y2-=tmp;
		x[i]=y1;
		y[i]=y2;
//		cout<<x[i]<<' '<<y[i]<<endl;
		int fa1=find(x[i]),fa2=find(y[i]+2);
		if(fa1==fa2)
		{
			if((sum[x[i]]^sum[y[i]+2])!=z[i])
			{
				cout<<0<<endl;
				return 0;
			}
		}
		else
		{
			if(fa1<fa2)
			{
				fa[fa2]=fa1;
				sum[fa2]=sum[x[i]]^z[i]^sum[y[i]+2];
			}
			else
			{
				fa[fa1]=fa2;
				sum[fa1]=sum[x[i]]^z[i]^sum[y[i]+2];
			}
			--ans;
		}
	}
	cout<<power(2,ans,1000000007)<<endl;
	return 0;
}