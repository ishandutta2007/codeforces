#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int n,cnt=1,last=1,deep[400001],jump[400001][20],Fir[400001],head[400001],tot,TOT,root[400001];
int dp[400001],maxn[400001],ans;
string s;
struct node
{
	int len,fa,ch[26];
}sam[400001];
void sam_in(int c)
{
	int p=last,np=last=++cnt;
	sam[np].len=sam[p].len+1;
	while(p && !sam[p].ch[c])
	{
		sam[p].ch[c]=np;
		p=sam[p].fa;
	}
	if(!p)
		sam[np].fa=1;
	else
	{
		int q=sam[p].ch[c];
		if(sam[q].len==sam[p].len+1)
			sam[np].fa=q;
		else
		{
			int nq=++cnt;
			sam[nq]=sam[q];
			sam[nq].len=sam[p].len+1;
			sam[q].fa=sam[np].fa=nq;
			while(p && sam[p].ch[c]==q)
			{
				sam[p].ch[c]=nq;
				p=sam[p].fa;
			}
		}
	}
}
struct sb
{
	int to,nextn;
}a[400001];
void ADD(int from,int to)
{
	a[++TOT].to=to,a[TOT].nextn=head[from];
	head[from]=TOT;
}
struct data
{
	int l,r,value;
}tree[8000001];
void xg(int l,int r,int zone,int &bj)
{
	bj=++tot;
	tree[bj].value=zone;
	if(l==r)
		return;
	int mid=(l+r)/2;
	if(zone<=mid)
		xg(l,mid,zone,tree[bj].l);
	else
		xg(mid+1,r,zone,tree[bj].r);
}
void merge(int l,int r,int &bj,int pre)
{
	if(!bj || !pre)
	{
		bj=bj+pre;
		return;
	}
	int NEW=++tot,mid=(l+r)/2;
	tree[NEW]=tree[bj];
	if(l==r)
	{
		tree[NEW].value|=tree[pre].value;
		bj=NEW;
		return;
	}
	merge(l,mid,tree[NEW].l,tree[pre].l);
	merge(mid+1,r,tree[NEW].r,tree[pre].r);
	tree[NEW].value=tree[tree[NEW].l].value|tree[tree[NEW].r].value;
	bj=NEW;
}
void format(int u)
{
	int LOG=log2(deep[u]);
	for(int i=1;i<=LOG;++i)
		jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		deep[v]=deep[u]+1;
		jump[v][0]=u;
		format(v);
		merge(1,n,root[u],root[v]);
	}
}
int cx(int l,int r,int L,int R,int bj)
{
	if(L>R)
		return 0;
	if(!bj)
		return 0;
	if(L<=l && r<=R)
		return tree[bj].value;
	int mid=(l+r)/2,bck=0;
	if(L<=mid)
		bck=cx(l,mid,L,R,tree[bj].l);
	if(mid<R)
		bck|=cx(mid+1,r,L,R,tree[bj].r);
	return bck;
}
void fun(int u)
{
	if(u!=1)
	{
		int LOG=log2(deep[u]),fb=u;
		for(int i=LOG;i>=0;--i)
			if(jump[fb][i] && !cx(1,n,Fir[u]-sam[u].len+sam[jump[fb][i]].len,Fir[u]-1,root[jump[fb][i]]))
				fb=jump[fb][i];
		fb=sam[fb].fa;
		dp[u]=maxn[fb]+1;
		maxn[u]=max(maxn[u],dp[u]);
	}
	ans=max(ans,dp[u]);
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		maxn[v]=maxn[u];
		fun(v);
	}
}
void print(int l,int r,int bj)
{
	if(!bj)
		return;
	if(l==r)
	{
		cout<<l<<" ";
		return;
	}
	int mid=(l+r)/2;
	print(l,mid,tree[bj].l);
	print(mid+1,r,tree[bj].r);
}
int main()
{
	n=read();
	cin>>s;
	for(int i=1;i<=n;++i)
	{
		sam_in(s[i-1]-'a');
		xg(1,n,i,root[last]);
		for(int j=last;j<=cnt;++j)
			Fir[j]=i;
	}
	for(int i=2;i<=cnt;++i)
		ADD(sam[i].fa,i);
	deep[1]=1;
	format(1);
	fun(1);
	printf("%d\n",ans);
	return 0;
}