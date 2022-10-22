#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q;
int qtree[MAXN*4];
struct seg_tree
{
	int val,lazy;
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void qxg(int l,int r,int zone,int val,int x)
{
	if(l==r) {qtree[x]=max(qtree[x],val);return;}
	int mid=(l+r)>>1;
	if(zone<=mid) qxg(l,mid,zone,val,ls(x));
	else qxg(mid+1,r,zone,val,rs(x));
	qtree[x]=max(qtree[ls(x)],qtree[rs(x)]);
}
int qcx(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) return qtree[x];
	int mid=(l+r)>>1,bck=0;
	if(L<=mid) bck=qcx(l,mid,L,R,ls(x));
	if(mid<R) bck=max(bck,qcx(mid+1,r,L,R,rs(x)));
	return bck;
}
void change(int l,int r,int x)
{
	tree[x].lazy=1;
	tree[x].val=r-l+1;
}
void down(int l,int mid,int r,int x)
{
	if(tree[x].lazy)
	{
		change(l,mid,ls(x));
		change(mid+1,r,rs(x));
		tree[x].lazy=0;
	}
}
void xg(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) {change(l,r,x);return;}
	int mid=(l+r)>>1;
	down(l,mid,r,x);
	if(L<=mid) xg(l,mid,L,R,ls(x));
	if(mid<R) xg(mid+1,r,L,R,rs(x));
	tree[x].val=tree[ls(x)].val+tree[rs(x)].val;
}
int cx(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) return tree[x].val;
	int mid=(l+r)>>1,bck=0;
	down(l,mid,r,x);
	if(L<=mid) bck=cx(l,mid,L,R,ls(x));
	if(mid<R) bck+=cx(mid+1,r,L,R,rs(x));
	return bck;
}
int main()
{
	n=read(),q=read();
	while(q--)
	{
		int type=read();
		if(type==0)
		{
			int l=read(),r=read(),val=read();
			if(val) qxg(1,n,r,l,1);
			else xg(1,n,l,r,1);
		}
		else
		{
			int x=read();
			if(cx(1,n,x,x,1)==1) puts("NO");
			else
			{
				int l=1,r=x,L,R;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(cx(1,n,mid,x,1)==x-mid) L=mid,r=mid-1;
					else l=mid+1;
				}
				l=x,r=n;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(cx(1,n,x,mid,1)==mid-x) R=mid,l=mid+1;
					else r=mid-1;
				}
				if(qcx(1,n,1,R,1)>=L) puts("YES");
				else puts("N/A");
			}
		}
	}
	return 0;
}
//ore no turn,draw!