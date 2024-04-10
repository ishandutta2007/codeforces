#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ls (bj<<1)
#define rs (bj<<1|1)
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
int n,q;
char s[200010];
struct data
{
	int ans;
	int value,lvalue,rvalue;
	int sum;
	int l,r; //lmax,rmin
}tree[800010];
void up(int bj)
{
	tree[bj].sum=tree[ls].sum+tree[rs].sum;
	tree[bj].ans=max(max(tree[ls].ans,tree[rs].ans),max(tree[ls].rvalue+tree[rs].l,tree[rs].lvalue-tree[ls].r));
	tree[bj].lvalue=max(tree[ls].lvalue,max(tree[ls].value+tree[rs].l,tree[rs].lvalue-tree[ls].sum));
	tree[bj].rvalue=max(tree[rs].rvalue,max(tree[rs].value-tree[ls].r,tree[rs].sum+tree[ls].rvalue));
	tree[bj].value=max(tree[ls].value+tree[rs].sum,tree[rs].value-tree[ls].sum);
	tree[bj].l=max(tree[ls].l,tree[ls].sum+tree[rs].l);
	tree[bj].r=min(tree[rs].r,tree[rs].sum+tree[ls].r);
}
void build(int l,int r,int bj)
{
	if(l==r)
	{
		int v=(s[l]=='('?1:-1);
		tree[bj].sum=v;
		tree[bj].l=max(0,v);
		tree[bj].r=min(0,v);
		tree[bj].value=tree[bj].lvalue=tree[bj].rvalue=tree[bj].ans=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,ls);
	build(mid+1,r,rs);
	up(bj);
}
void xg(int l,int r,int zone,char c,int bj)
{
	if(l==r)
	{
		int v=(c=='('?1:-1);
		tree[bj].sum=v;
		tree[bj].l=max(0,v);
		tree[bj].r=min(0,v);
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid) xg(l,mid,zone,c,ls);
	else xg(mid+1,r,zone,c,rs);
	up(bj);
}
int main()
{
	n=read(),q=read();
	scanf("%s",s+1);
	int N=2*(n-1);
	build(1,N,1);
	printf("%d\n",tree[1].ans);
	while(q--)
	{
		int x=read(),y=read();
		xg(1,N,x,s[y],1);
		xg(1,N,y,s[x],1);
		swap(s[x],s[y]);
		//cout<<s+1<<endl;
		printf("%d\n",tree[1].ans);
	}
	return 0;
}
/*
5 3
(()()())
7 6
4 5
7 6
*/