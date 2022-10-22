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
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,a[100001],b[100010],m,tree[400040],lazy[400040];
void up(int bj)
{
	tree[bj]=min(tree[bj*2],tree[bj*2+1]);
}
void down(int l,int r,int mid,int bj)
{
	if(!lazy[bj]) return;
	tree[bj*2]+=lazy[bj];
	lazy[bj*2]+=lazy[bj];
	tree[bj*2+1]+=lazy[bj];
	lazy[bj*2+1]+=lazy[bj];
	lazy[bj]=0;
}
void xg(int l,int r,int zone,int v,int bj)
{
	if(l==r)
	{
		tree[bj]=min(tree[bj],v);
		return;
	}
	int mid=(l+r)/2;
	down(l,r,mid,bj);
	if(zone<=mid) xg(l,mid,zone,v,bj*2);
	else xg(mid+1,r,zone,v,bj*2+1);
	up(bj);
}
int cx(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R) return tree[bj];
	int mid=(l+r)/2,bck=0x3f3f3f3f;
	down(l,r,mid,bj);
	if(L<=mid) bck=cx(l,mid,L,R,bj*2);
	if(mid<R) bck=min(bck,cx(mid+1,r,L,R,bj*2+1));
	return bck;
}
void build(int l,int r,int bj)
{
	if(l==r)
	{
		if(l) tree[bj]=0x3f3f3f3f;
		else tree[bj]=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	up(bj);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r+1<=n && a[r+1]==a[l]) ++r;
		b[++m]=a[l];
	}
	/*if(n==100000 && a[1]==a[2] && a[1]==2 && a[3]==1)
	{
		cout<<m<<endl;
		return 0;
	}*/
	//for(int i=1;i<=m;++i) cout<<b[i]<<" ";
	//	cout<<endl;
	build(0,n,1);
	for(int i=2;i<=m;++i)
	{
		int last=b[i-1];
		lazy[1]++;
		tree[1]++;
		int v=cx(0,n,b[i],b[i],1)-1;
		v=min(v,cx(0,n,0,b[i]-1,1));
		if(b[i]!=n) v=min(v,cx(0,n,b[i]+1,n,1));
		//cout<<i<<" "<<v<<endl;
		xg(0,n,last,v,1);
	}
	printf("%d\n",tree[1]);
	return 0;
}