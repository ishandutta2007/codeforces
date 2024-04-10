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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,tree[1200001],a[300001],z[300001],top,lazy[1200001],mem[300001],cnt,minn[300001];
void up(int bj){tree[bj]=min(tree[2*bj],tree[2*bj+1]);}
void down(int bj)
{
	if(!lazy[bj]) return;
	tree[bj*2]+=lazy[bj];
	lazy[bj*2]+=lazy[bj];
	tree[bj*2+1]+=lazy[bj];
	lazy[bj*2+1]+=lazy[bj];
	lazy[bj]=0;
}
void build(int l,int r,int bj)
{
	if(l==r)
	{
		if(l-a[l]<0) tree[bj]=0x3f3f3f3f;
		else tree[bj]=l-a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	up(bj);
}
void fun(int l,int r,int bj)
{
	if(tree[bj]!=0) return;
	if(l==r)
	{
		tree[bj]=0x3f3f3f3f;
		z[++top]=l;
		//id[l]=tim;
		return;
	}
	int mid=(l+r)/2;
	down(bj);
	if(tree[bj*2]==0) fun(l,mid,bj*2);
	if(tree[bj*2+1]==0) fun(mid+1,r,bj*2+1);
	up(bj);
}
void xg(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
	{
		tree[bj]-=1;
		lazy[bj]-=1;
		return;
	}
	int mid=(l+r)/2;
	down(bj);
	if(L<=mid) xg(l,mid,L,R,bj*2);
	if(mid<R) xg(mid+1,r,L,R,bj*2+1);
	up(bj);
}
int root[300001],pcnt;
struct data
{
	int l,r,value;
}Tree[300001*32];
void XG(int l,int r,int zone,int pre,int &bj)
{
	if(!bj) bj=++pcnt;
	if(l==r)
	{
		Tree[bj].value=Tree[pre].value+1;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
	{
		XG(l,mid,zone,Tree[pre].l,Tree[bj].l);
		Tree[bj].r=Tree[pre].r;
	}
	else
	{
		XG(mid+1,r,zone,Tree[pre].r,Tree[bj].r);
		Tree[bj].l=Tree[pre].l;
	}
	Tree[bj].value=Tree[Tree[bj].l].value+Tree[Tree[bj].r].value;
}
int CX(int l,int r,int L,int R,int bj)
{
	if(!bj || L>R) return 0;
	if(L<=l && r<=R) return Tree[bj].value;
	int bck=0,mid=(l+r)/2;
	if(L<=mid) bck=CX(l,mid,L,R,Tree[bj].l);
	if(mid<R) bck+=CX(mid+1,r,L,R,Tree[bj].r);
	return bck;
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build(1,n,1);
	while(1)
	{
		//++tim;
		int fb=top;
		fun(1,n,1);
		if(!top) break;
		mem[++cnt]=z[top];
		if(z[top]!=n) xg(1,n,z[top]+1,n,1);
		--top;
	}
	//for(int i=1;i<=cnt;++i) cout<<"cao "<<mem[i]<<endl;
	minn[1]=mem[1];
	for(int i=2;i<=cnt;++i) minn[i]=min(mem[i],minn[i-1]);
	for(int i=1;i<=cnt;++i) XG(1,n,mem[i],root[i-1],root[i]);
	while(q--)
	{
		int L=read(),R=n-read()+1;
		int l=1,r=n,lim=n+1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(minn[mid]<=L) lim=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",CX(1,n,1,R-1,root[lim-1]));
		//int ans=0;
		//for(int i=1;i<lim;++i) if(mem[i]<R) ++ans;
	}
	return 0;
}