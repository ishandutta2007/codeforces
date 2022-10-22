#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
inline int read()
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
int n,tree[1600010][2],lazy[1600010][2],num[400010],tot;
vector<int> Q[400010][2];
struct sb
{
	int l,r,c;
}a[200010];
inline void up(int bj,int ver)
{
	tree[bj][ver]=max(tree[bj*2][ver],tree[bj*2+1][ver]);
}
inline void down(int bj,int ver)
{
	if(!lazy[bj][ver])
		return;
	lazy[bj*2][ver]+=lazy[bj][ver];
	tree[bj*2][ver]+=lazy[bj][ver];
	lazy[bj*2+1][ver]+=lazy[bj][ver];
	tree[bj*2+1][ver]+=lazy[bj][ver];
	lazy[bj][ver]=0;
}
inline void xg(int l,int r,int L,int R,int v,int bj,int ver)
{
	if(L<=l && r<=R)
	{
		tree[bj][ver]+=v;
		lazy[bj][ver]+=v;
		return;
	}
	int mid=(l+r)/2;
	down(bj,ver);
	if(L<=mid)
		xg(l,mid,L,R,v,bj*2,ver);
	if(mid<R)
		xg(mid+1,r,L,R,v,bj*2+1,ver);
	up(bj,ver);
}
inline int cx(int l,int r,int L,int R,int bj,int ver)
{
	if(L<=l && r<=R)
		return tree[bj][ver];
	int mid=(l+r)/2,bck=0;
	down(bj,ver);
	if(L<=mid)
		bck=cx(l,mid,L,R,bj*2,ver);
	if(mid<R)
		bck=max(bck,cx(mid+1,r,L,R,bj*2+1,ver));
	return bck;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
	{
		a[i].l=read(),a[i].r=read(),a[i].c=read()-1;
		num[++tot]=a[i].l;
		num[++tot]=a[i].r;
	}
	num[++tot]=0;
	sort(num+1,num+tot+1);
	tot=unique(num+1,num+tot+1)-num-1;
	for(register int i=1;i<=n;++i)
	{
		a[i].l=lower_bound(num+1,num+tot+1,a[i].l)-num;
		a[i].r=lower_bound(num+1,num+tot+1,a[i].r)-num;
		Q[a[i].r][0].push_back(a[i].l);
		Q[a[i].r][1].push_back(a[i].c);
	}
	for(register int i=2;i<=tot;++i)
	{
		xg(1,tot,i,i,cx(1,tot,1,i-1,1,1),1,0);
		xg(1,tot,i,i,cx(1,tot,1,i-1,1,0),1,1);
		for(register int j=0;j<Q[i][0].size();++j)
			xg(1,tot,1,Q[i][0][j],1,1,Q[i][1][j]);
	}
	printf("%d\n",max(tree[1][0],tree[1][1]));
	return 0;
}