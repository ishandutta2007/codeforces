#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=1000000007;
typedef long long ll;
int n,i,mu[100005],p,j;
ll f[100005],ans;
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
ll ni(ll a)
{
	ll x,y;
	exgcd(a,M,x,y);
	return x;
}
ll Count(int a,int m)
{
	ll ans=0;
	int i;
	for(i=1;i*i<a;i++)
		if(a%i==0)
			ans=ans+mu[i]*(m/i)+mu[a/i]*(m/(a/i));
	if(i*i==a)
		ans+=mu[i]*(m/i);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int tmp=i;
		p=1;
		for(j=2;j*j<=tmp;j++)
			if(tmp%j==0)
			{
				if(tmp/j%j==0)
				{
					p=0;
					break;
				}
				else
					p=-p;
				tmp/=j;
			}
		if(tmp!=1)
			p=-p;
		mu[i]=p;
	}
	for(i=n;i>=1;i--)
	{
		for(j=i*2;j<=n;j+=i)
			f[i]=(f[i]+f[j]*Count(j/i,n/i)%M*ni(n)%M)%M;
		if(i==1)
			f[i]+=ni(n);
		else
			f[i]=(f[i]+ni(n))*ni(n-(n/i))%M*n%M;
	}
	for(i=1;i<=n;i++)
		ans=(ans+f[i])%M;
	cout<<(ans%M+M)%M;
}