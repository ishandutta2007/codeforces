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
const int MAXN=1.5e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,h,a[MAXN],b[MAXN],ans,p[MAXN];
int calc(int v)
{
	v=h-v;
	return lower_bound(b+1,b+m+1,v)-b;
}
struct seg_tree
{
	int maxn,tag;
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void up(int x) {tree[x].maxn=max(tree[ls(x)].maxn,tree[rs(x)].maxn);}
void build(int l,int r,int x)
{
	if(l==r)
	{
		tree[x].maxn=l;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	up(x);
}
void change(int x,int val)
{
	tree[x].maxn+=val;
	tree[x].tag+=val;
}
void down(int x)
{
	if(tree[x].tag)
	{
		change(ls(x),tree[x].tag);
		change(rs(x),tree[x].tag);
		tree[x].tag=0;
	}
}
void xg(int l,int r,int L,int R,int val,int x)
{
	if(L<=l && r<=R) {change(x,val);return;}
	int mid=(l+r)>>1;
	down(x);
	if(L<=mid) xg(l,mid,L,R,val,ls(x));
	if(mid<R) xg(mid+1,r,L,R,val,rs(x));
	up(x);
}
int main()
{
	n=read(),m=read(),h=read();
	for(int i=1;i<=m;++i) b[i]=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(b+1,b+m+1);
	build(1,m,1);
	for(int i=1;i<=n;++i) p[i]=calc(a[i]);
	for(int i=1;i<m;++i) if(p[i]<=m) xg(1,m,p[i],m,-1,1);
	for(int i=m;i<=n;++i)
	{
		if(p[i]<=m) xg(1,m,p[i],m,-1,1);
		if(tree[1].maxn<=0) ++ans;
		if(p[i-m+1]<=m) xg(1,m,p[i-m+1],m,1,1);
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!