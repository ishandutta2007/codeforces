#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
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
int n,head[100001],tot,A[100001],B[100001],lim=1e5,root[100001],pcnt;
ll ans[100001];
struct node
{
	int to,nextn;
}a[200001];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
struct data
{
	int l,r,k,vis;
	ll b; //kx+b
	data(int _l=0,int _r=0,int _k=0,ll _b=0,int _vis=0){l=_l,r=_r,k=_k,b=_b,vis=_vis;}
}tree[1800001];
inline ll calc(int id,int x){return tree[id].vis?1ll*tree[id].k*x+tree[id].b:0x3f3f3f3f3f3f3f3f;}
void xg(int l,int r,int k,ll b,int &bj)
{
	if(!bj) bj=++pcnt;
	if(!tree[bj].vis)
	{
		tree[bj].k=k;
		tree[bj].b=b;
		tree[bj].vis=1;
		return;
	}
	if(l==r)
	{
		if(1ll*l*k+b<calc(bj,l)) tree[bj].k=k,tree[bj].b=b;
		return;
	}
	int mid=(l+r)/2;
	ll vl=calc(bj,l),vr=calc(bj,r),vm=calc(bj,mid);
	ll nl=1ll*l*k+b,nr=1ll*r*k+b,nm=1ll*mid*k+b;
	if(nl>=vl && nr>=vr) return;
	if(nl<=vl && nr<=vr)
	{
		tree[bj].k=k;
		tree[bj].b=b;
		return;
	}
	if(nm<vm)
	{
		swap(tree[bj].k,k);
		swap(tree[bj].b,b);
	}
	if(k<tree[bj].k) xg(mid+1,r,k,b,tree[bj].r);
	else xg(l,mid,k,b,tree[bj].l);
}
int merge(int l,int r,int pre,int bj)
{
	if(!pre || !bj) return pre+bj;
	int nbj=++pcnt;
	if(l==r)
	{
		if(calc(bj,l)<calc(pre,l)) tree[nbj]=tree[bj];
		else tree[nbj]=tree[pre];
		return nbj;
	}
	int mid=(l+r)/2;
	tree[nbj].l=merge(l,mid,tree[pre].l,tree[bj].l);
	tree[nbj].r=merge(mid+1,r,tree[pre].r,tree[bj].r);
	if(tree[pre].vis) xg(l,r,tree[pre].k,tree[pre].b,nbj);
	if(tree[bj].vis) xg(l,r,tree[bj].k,tree[bj].b,nbj);
	return nbj;
}
ll cx(int l,int r,int x,int bj)
{
	if(!bj) return 0x3f3f3f3f3f3f3f3f;
	ll bck=calc(bj,x);
	if(l==r) return bck;
	int mid=(l+r)/2;
	if(x<=mid) return min(bck,cx(l,mid,x,tree[bj].l));
	else return min(bck,cx(mid+1,r,x,tree[bj].r));
}
/*void out(int l,int r,int u)
{
	if(!u) return;
	cout<<u<<": "<<l<<" "<<r<<" "<<tree[u].l<<" "<<tree[u].r<<" "<<tree[u].k<<" "<<tree[u].b<<" "<<tree[u].vis<<endl;
	int mid=(l+r)/2;
	if(l==r) return;
	out(l,mid,tree[u].l);
	out(mid+1,r,tree[u].r);
}*/
void fun(int u,int fa) //ans[u]=min(ans[v]+A[u]*B[v])
{
	int flag=0;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa) continue;
		flag=1;
		fun(v,u);
		root[u]=merge(-lim,lim,root[v],root[u]);
	}
	ans[u]=(flag?cx(-lim,lim,A[u],root[u]):0);
	xg(-lim,lim,B[u],ans[u],root[u]);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i) A[i]=read();
	for(int i=1;i<=n;++i) B[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	fun(1,0);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	putchar('\n');
	return 0;
}