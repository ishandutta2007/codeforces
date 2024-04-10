#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll M=1000000007;
int n,q,a[400005],i,f[305],u,j,k,l,r,x,pri[1005],num;
bitset<65> v[1600005],p[1600005],t;
char c[105];
ll tree[1600005],lazy[1600005];
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
	return x%M;
}
void Mark(int i,int l,int r,int ll,int rr,int x)
{
	if(p[i][x]==1)
		return;
	if(l>=ll&&r<=rr)
		p[i][x]=1;
	v[i][x]=1;
	if(l==r)
		return;
	int mid=(l+r)/2;
	if(mid>=ll)
		Mark(i*2,l,mid,ll,rr,x);
	if(mid<rr)
		Mark(i*2+1,mid+1,r,ll,rr,x);
}
ll Quick_pow(ll x,ll y)
{
	ll s=x,ans=1;
	while(y>0)
	{
		if(y&1)
			ans=ans*s%M;
		s=s*s%M;
		y>>=1;
	}
	return ans;
}
void Push(int i,int l,int r,int ll,int rr,int x)
{
	int mid=(l+r)/2;
	if(l>=ll&&r<=rr)
	{
		lazy[i]=lazy[i]*x%M;
		tree[i]=tree[i]*Quick_pow(x,r-l+1)%M;
		return;
	}
	if(mid>=ll)
		Push(i*2,l,mid,ll,rr,x);
	if(mid<rr)
		Push(i*2+1,mid+1,r,ll,rr,x);
	tree[i]=tree[i*2]*tree[i*2+1]%M*Quick_pow(lazy[i],r-l+1)%M;
}
ll Query(int i,int l,int r,int ll,int rr)
{
	int mid=(l+r)/2;
	if(l>=ll&&r<=rr)
		return tree[i];
	long long s=1;
	if(mid>=ll)
		s=Query(i*2,l,mid,ll,rr);
	if(mid<rr)
		s=s*Query(i*2+1,mid+1,r,ll,rr)%M;
	return s*Quick_pow(lazy[i],min(rr,r)-max(ll,l)+1)%M;
}
void Q2(int i,int l,int r,int ll,int rr)
{
	int mid=(l+r)/2;
	if(l>=ll&&r<=rr)
	{
		t|=v[i];
		return;
	}
	if(mid>=ll)
		Q2(i*2,l,mid,ll,rr);
	if(mid<rr)
		Q2(i*2+1,mid+1,r,ll,rr);
}
void rp(int l,int r,int x)
{
	int i;
	Push(1,1,n,l,r,x);
	for(i=1;i<=num;i++)
		if(x%pri[i]==0)
			Mark(1,1,n,l,r,i);
}
int main(){
	scanf("%d %d",&n,&q);
	for(i=1;i<=n*4;i++)
		tree[i]=lazy[i]=1;
	for(i=2;i<=300;i++)
		if(f[i]==0)
		{
			f[i]=k++;
			for(j=i*2;j<=300;j+=i)
				f[j]=1;
			u++;
			pri[++num]=i;
		}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		rp(i,i,a[i]);
	}
	scanf("\n");
	while(q--)
	{
		scanf("%s %d %d\n",c,&l,&r);
		if(c[0]=='M')
		{
			scanf("%d",&x);
			rp(l,r,x);
		}
		else
		{
			t.reset();
			Q2(1,1,n,l,r);
			ll ans=Query(1,1,n,l,r);
			for(i=1;i<=num;i++)
				if(t[i]==1)
					ans=ans*(pri[i]-1)%M*ni(pri[i])%M;
			cout<<(ans%M+M)%M<<endl;
		}
	}
}