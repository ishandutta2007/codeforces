#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
inline void readi(int &x);
const int maxn=200005,M=1000000007;
int n,Q;
int tp[maxn],qx[maxn],qv[maxn];
int deg[maxn];
int head[maxn],adj[maxn],next[maxn],tot;
int fa[maxn],dfn[maxn],las[maxn],idx;

void addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;}

int pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(LL)a*a%M)
		if(b&1)s=(LL)s*a%M;
	return s;
}

void tdfs(const int &x)
{
	dfn[x]=++idx;
	for(int i=head[x];i;i=next[i])
	{
		fa[adj[i]]=x;
		tdfs(adj[i]);
	}
	las[x]=idx;
}

struct node
{
	int mul;
	int sum;
	node *lc,*rc;
	
	void tagmul(const int &d)
	{
		mul=(LL)mul*d%M;
		sum=(LL)sum*d%M;
	}
	
	void downdate()
	{
		if(mul!=1)
		{
			lc->tagmul(mul);
			rc->tagmul(mul);
			mul=1;
		}
	}
	
	void update()
	{
		sum=(lc->sum+rc->sum)%M;
	}
	
	void Set(int l,int r,const int &p,const int &c)
	{
		if(l==r)sum=(LL)c*mul%M;
		else
		{
			int mid=l+r>>1;
			downdate();
			if(p<=mid)lc->Set(l,mid,p,c);
			else rc->Set(mid+1,r,p,c);
			update();
		}
	}
	
	void Ins(int l,int r,const int &a,const int &b,const int &d)
	{
		if(l>=a&&r<=b)
			tagmul(d);
		else
		{
			int mid=l+r>>1;
			downdate();
			if(a<=mid)lc->Ins(l,mid,a,b,d);
			if(b>mid)rc->Ins(mid+1,r,a,b,d);
			update();
		}
	}
	
	int Get(int l,int r,const int &p)
	{
		if(l==r)return mul;
		else
		{
			int mid=l+r>>1;
			downdate();
			if(p<=mid)return lc->Get(l,mid,p);
			else return rc->Get(mid+1,r,p);
		}
	}
	
	int Ask(int l,int r,const int &a,const int &b)
	{
		if(l>=a&&r<=b)return sum;
		int mid=l+r>>1,res=0;
		downdate();
		if(a<=mid)res=(res+lc->Ask(l,mid,a,b))%M;
		if(b>mid)res=(res+rc->Ask(mid+1,r,a,b))%M;
		return res;
	}
	
}ndl[maxn*2],*ns=ndl,*root;

node* build(int l,int r)
{
	node *x=ns++;
	x->mul=1;
	if(l<r)
		x->lc=build(l,l+r>>1),
		x->rc=build(l+r+2>>1,r);
	return x;
}

void addnode(int x,int c)
{
	int y=fa[x],d=pow(deg[y],M-2);
	deg[y]++;
	d=(LL)d*deg[y]%M;
	root->Ins(1,n,dfn[y],las[y],d);
	deg[x]=1;
	root->Set(1,n,dfn[x],c);
}

int querynode(int x)
{
	int d=1,r,y=fa[x];
	if(x!=1)d=pow(root->Get(1,n,dfn[y]),M-2);
	r=root->Ask(1,n,dfn[x],las[x]);
	r=(LL)r*d%M;
	return r;
}

int main()
{
	int V1;
	readi(V1),readi(Q);n=1;
	for(int i=1;i<=Q;i++)
	{
		readi(tp[i]);
		readi(qx[i]);
		if(tp[i]==1)
		{
			readi(qv[i]);
			addedge(qx[i],++n);
			qx[i]=n;
		}
	}
	tdfs(1);
	root=build(1,n);
	root->Set(1,n,1,V1);deg[1]=1;
	for(int i=1;i<=Q;i++)
	{
		if(tp[i]==1)
			addnode(qx[i],qv[i]);
		else
			printf("%d\n",querynode(qx[i]));
	}
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}