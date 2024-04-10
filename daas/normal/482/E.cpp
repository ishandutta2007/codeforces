#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
#define ls(x) (tree[x].son[0])
#define rs(x) (tree[x].son[1])
using namespace std;
const int MAXN=100010;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,pre[MAXN];
struct LCT
{
	int son[2],fa,value;
	int size,xsize;
	int ans,xans;
	int ctb,del;
}tree[MAXN];
int noroot(int x){return ls(tree[x].fa)==x || rs(tree[x].fa)==x;}
void up(int x) //size  ans  ctb
{
	tree[x].size=tree[ls(x)].size+tree[rs(x)].size+tree[x].xsize; //size push_up

	tree[x].ctb=tree[ls(x)].ctb+tree[rs(x)].ctb+tree[x].xsize*tree[x].value; //quest push_up

	tree[x].ans=tree[ls(x)].ans+tree[rs(x)].ans+tree[x].xans\
	+tree[x].value*(tree[x].xsize*tree[x].xsize-tree[x].del)\
	+2*tree[x].value*tree[x].xsize*tree[rs(x)].size\
	+2*tree[ls(x)].ctb*(tree[x].size-tree[ls(x)].size);
}
void rotate(int x)
{
	int y=tree[x].fa,z=tree[y].fa;
	int K=(rs(y)==x);
	if(noroot(y)) tree[z].son[rs(z)==y]=x;
	tree[tree[x].son[K^1]].fa=y;
	tree[y].son[K]=tree[x].son[K^1];
	tree[x].son[K^1]=y;
	tree[y].fa=x;
	tree[x].fa=z;
	up(y);
}
void splay(int x)
{
	while(noroot(x))
	{
		int y=tree[x].fa,z=tree[y].fa;
		if(noroot(y)) (rs(y)==x)^(rs(z)==y)?rotate(x):rotate(y);
		rotate(x);
	}
	up(x);
}
void access(int x)
{
	for(int last=0;x!=0;last=x,x=tree[x].fa)
	{
		splay(x); //xsize xans del

		tree[x].xsize+=tree[rs(x)].size;
		tree[x].xans+=tree[rs(x)].ans;
		tree[x].del+=tree[rs(x)].size*tree[rs(x)].size;

		tree[x].son[1]=last;

		tree[x].xsize-=tree[rs(x)].size;
		tree[x].xans-=tree[rs(x)].ans;
		tree[x].del-=tree[rs(x)].size*tree[rs(x)].size;

		up(x);
	}
}
void link(int x,int y)
{
	access(y),splay(y);
	access(x),splay(x);
	tree[y].fa=x; //xsize xans del
	tree[x].xsize+=tree[y].size;
	tree[x].xans+=tree[y].ans;
	tree[x].del+=tree[y].size*tree[y].size;
	up(x);
}
void cut(int x,int y)
{
	access(x);
	splay(x);
	splay(y); //xsize xans del
	tree[x].xsize-=tree[y].size;
	tree[x].xans-=tree[y].ans;
	tree[x].del-=tree[y].size*tree[y].size;
	tree[y].fa=0;
	up(x);
}
int check(int x,int y)
{
	access(y);
	splay(y);
	splay(x);
	return noroot(y);
}
signed main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read();
	for(int i=2;i<=n;++i) pre[i]=read();
	for(int i=1;i<=n;++i)
	{
		tree[i].ans=tree[i].ctb=tree[i].value=read();
		tree[i].size=tree[i].xsize=1;
	}
	for(int i=2;i<=n;++i) link(pre[i],i);
	access(1);
	splay(1);
	printf("%.10lf\n",(double)tree[1].ans/n/n);
	//for(int i=1;i<=n;++i) cout<<i<<" :"<<tree[i].son[0]<<" "<<tree[i].son[1]<<" "<<tree[i].ans<<" "<<tree[i].fa<<" "<<tree[i].xsize<<" "<<tree[i].xans<<endl;
	//return 0;
	q=read();
	while(q--)
	{
		char type[10];
		scanf("%s",type);
		int x=read(),y=read();
		if(type[0]=='P')
		{
			if(check(x,y)) swap(x,y);
			cut(pre[x],x);
			pre[x]=y;
			link(pre[x],x);
		}
		else
		{
			access(x);
			splay(x);
			tree[x].value=y;
			up(x);
		}
		access(1);
		splay(1);
		printf("%.10lf\n",(double)tree[1].ans/n/n);
	}
	return 0;
}