#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
const int mod=1e9+9;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while(c<'0' || c>'9' && c!='-')
		c=getchar();
	if(c=='-')
		x=-1,c=getchar();
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,tree[2400001][3],change[300010][2],sum[300010][2],value[300001];
inline void build(int l,int r,int bj)
{
	if(l==r)
	{
		tree[bj][0]=tree[bj][2]=value[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	tree[bj][2]=(tree[bj*2][2]+tree[bj*2+1][2])%mod;
}
inline void up(int bj,int l,int r)
{
	tree[bj][2]=((1ll*tree[bj][0]*sum[r-l+1][0]%mod+1ll*tree[bj][1]*sum[r-l+1][1]%mod)%mod+(tree[bj*2][2]+tree[bj*2+1][2])%mod)%mod;
}
inline void xg(int l,int r,int L,int R,int a,int b,int bj)
{
	if(L<=l && r<=R)
	{
		tree[bj][0]=(tree[bj][0]+(1ll*a*change[l-L+1][0]%mod+1ll*b*change[l-L+1][1]%mod)%mod)%mod;
		tree[bj][1]=(tree[bj][1]+(1ll*a*change[l-L+2][0]%mod+1ll*b*change[l-L+2][1]%mod)%mod)%mod;
		up(bj,l,r);
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid)
		xg(l,mid,L,R,a,b,bj*2);
	if(mid<R)
		xg(mid+1,r,L,R,a,b,bj*2+1);
	up(bj,l,r);
}
inline int cx(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
		return tree[bj][2];
	int bck=(1ll*tree[bj][0]*((sum[min(r,R)-l+1][0]-sum[max(l,L)-l][0]+mod)%mod)%mod+1ll*tree[bj][1]*((sum[min(r,R)-l+1][1]-sum[max(l,L)-l][1]+mod)%mod)%mod)%mod,mid=(l+r)/2;
	if(L<=mid)
		bck=(bck+cx(l,mid,L,R,bj*2))%mod;
	if(mid<R)
		bck=(bck+cx(mid+1,r,L,R,bj*2+1))%mod;
	return bck;
}
signed main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;++i)
		value[i]=read();
	change[1][0]=change[2][1]=1;
	for(register int i=3;i<=n+1;++i)
	{
		change[i][0]=(change[i-1][0]+change[i-2][0])%mod;
		change[i][1]=(change[i-1][1]+change[i-2][1])%mod;
	}
	for(register int i=1;i<=n+1;++i)
	{
		sum[i][0]=(sum[i-1][0]+change[i][0])%mod;
		sum[i][1]=(sum[i-1][1]+change[i][1])%mod;
	}
	build(1,n,1);
	for(register int i=1;i<=m;++i)
	{
		//for(register int j=1;j<=7;++j)
		//	cout<<j<<" :"<<tree[j][0]<<" "<<tree[j][1]<<" "<<tree[j][2]<<endl;
		int type=read(),l=read(),r=read();
		if(type==1)
			xg(1,n,l,r,1,1,1);
		else
			printf("%lld\n",cx(1,n,l,r,1));
	}
	return 0;
}