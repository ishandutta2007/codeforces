#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int MAXN=120010;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,a[MAXN],z[MAXN][2],top[2];
ll ans[MAXN];
vector<pair<int,int> > Q[MAXN];
struct seg_tree
{
	int calc,plus1,plus2,minn,num;
	ll val;
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void up(int x)
{
	tree[x].val=tree[ls(x)].val+tree[rs(x)].val;
	tree[x].minn=min(tree[ls(x)].minn,tree[rs(x)].minn);
	tree[x].num=0;
	if(tree[ls(x)].minn==tree[x].minn) tree[x].num+=tree[ls(x)].num;
	if(tree[rs(x)].minn==tree[x].minn) tree[x].num+=tree[rs(x)].num;
}
void build(int l,int r,int x)
{
	if(l==r)
	{
		tree[x].minn=l;
		tree[x].num=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	up(x);
}
void change(int x,int val)
{
	tree[x].minn+=val;
	if(tree[x].calc) tree[x].plus2+=val;
	else tree[x].plus1+=val;
}
void calc(int x,int val)
{
	if(tree[x].minn) return;
	tree[x].val+=(ll)val*tree[x].num;
	tree[x].calc+=val;
}
void down(int x)
{
	if(tree[x].plus1)
	{
		change(ls(x),tree[x].plus1);
		change(rs(x),tree[x].plus1);
		tree[x].plus1=0;
	}
	if(tree[x].calc)
	{
		calc(ls(x),tree[x].calc);
		calc(rs(x),tree[x].calc);
		tree[x].calc=0;
	}
	if(tree[x].plus2)
	{
		change(ls(x),tree[x].plus2);
		change(rs(x),tree[x].plus2);
		tree[x].plus2=0;
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
ll cx(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) return tree[x].val;
	int mid=(l+r)>>1;
	ll bck=0;
	down(x);
	if(L<=mid) bck=cx(l,mid,L,R,ls(x));
	if(mid<R) bck+=cx(mid+1,r,L,R,rs(x));
	return bck;
}
int main()
{
	n=read();
	build(1,n,1);
	for(int i=1;i<=n;++i) a[i]=read();
	q=read();
	for(int i=1;i<=q;++i)
	{
		int l=read(),r=read();
		Q[r].push_back(make_pair(l,i));
	}
	for(int i=1;i<=n;++i)
	{
		change(1,-1);
		int las=i-1;
		while(top[0] && a[z[top[0]][0]]<a[i]) xg(1,n,z[top[0]-1][0]+1,las,a[i]-a[z[top[0]][0]],1),las=z[top[0]-1][0],--top[0];
		z[++top[0]][0]=i;
		las=i-1;
		while(top[1] && a[z[top[1]][1]]>a[i]) xg(1,n,z[top[1]-1][1]+1,las,a[z[top[1]][1]]-a[i],1),las=z[top[1]-1][1],--top[1];
		z[++top[1]][1]=i;
		calc(1,1);
		for(int j=0;j<Q[i].size();++j) ans[Q[i][j].second]=cx(1,n,Q[i][j].first,i,1);
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}
//ore no turn,draw!