#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll M=998244353;
int n,i,m,a[100005],b[100005],j,k,u,l;
ll s,f[55][55][105],s1,ans;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
ll ni(ll x)
{
	ll a,b;
	x=(x%M+M)%M;
	exgcd(x,M,a,b);
	a=(a%M+M)%M;
	return a;
}
int main(){
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			a[i]=-1;
			u++;
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		s+=b[i];
		if(a[i]==-1)
			s1+=b[i];
	}
	for(i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		f[0][0][b[i]]=1;
		for(j=0;j<=m;j++)
			for(k=0;k<=m-j;k++)
			{
				if(j!=0)
				{
					ll a1=s1-(j-1);
					ll a2=s-s1+k;
					ll t=a1+a2;
					if(a[i]==-1)
						for(l=0;l<=b[i];l++)
							f[j][k][l]+=f[j-1][k][l]*(a1-l)%M*ni(t)%M+f[j-1][k][l+1]*(l+1)%M*ni(t)%M;
					else
						for(l=b[i];l<=b[i]+m;l++)
							f[j][k][l]+=f[j-1][k][l]*a1%M*ni(t)%M;
				}
				if(k!=0)
				{
					ll a1=s1-j;
					ll a2=s-s1+k-1;
					ll t=a1+a2;
					if(a[i]==-1)
						for(l=0;l<=b[i];l++)
							f[j][k][l]+=f[j][k-1][l]*a2%M*ni(t)%M;
					else
						for(l=b[i];l<=b[i]+m;l++)
							f[j][k][l]+=f[j][k-1][l-1]*(l-1)%M*ni(t)%M+f[j][k-1][l]*(a2-l)%M*ni(t)%M;
				}
			}
		ans=0;
		for(j=0;j<=m;j++)
			for(k=0;k<=b[i]+m;k++)
				ans=(ans+f[j][m-j][k]*k%M)%M;
		cout<<(ans%M+M)%M<<endl;
	}
}