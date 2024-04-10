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
	while((c<'0' || c>'9') && c!='-') getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,head[300001],col[300001],tot,pcnt,root[300001];
int jump[300001][20],deep[300001];
ll rv1[300001],rv2[300001];
struct node
{
	int to,nextn;
}a[600001];
struct data
{
	int l,r;
	ll value1,value2;
}tree[6500000];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void xg(int l,int r,int zone,int pre,int &bj)
{
	if(!bj) bj=++pcnt;
	if(l==r)
	{
		tree[bj].value1=(tree[pre].value1^rv1[zone]);
		tree[bj].value2=(tree[pre].value2^rv2[zone]);
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
	{
		xg(l,mid,zone,tree[pre].l,tree[bj].l);
		tree[bj].r=tree[pre].r;
	}
	else
	{
		xg(mid+1,r,zone,tree[pre].r,tree[bj].r);
		tree[bj].l=tree[pre].l;
	}
	tree[bj].value1=(tree[tree[bj].l].value1^tree[tree[bj].r].value1);
	tree[bj].value2=(tree[tree[bj].l].value2^tree[tree[bj].r].value2);
}
void fun(int u,int fa)
{
	xg(1,n,col[u],root[fa],root[u]);
	deep[u]=deep[fa]+1;
	jump[u][0]=fa;
	int LOG=log2(deep[u]);
	for(int i=1;i<=LOG;++i) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa) continue;
		fun(v,u);
	}
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	int C=deep[x]-deep[y],LOG=log2(C);
	for(int i=0;i<=LOG;++i) if(C&(1<<i)) x=jump[x][i];
	if(x==y) return x;
	LOG=log2(deep[x]);
	for(int i=LOG;i>=0;--i)
		if(jump[x][i]!=jump[y][i])
		{
			x=jump[x][i];
			y=jump[y][i];
		}
	return jump[x][0];
}
int calc(int l,int r,int L,int R,int u,int v)
{
	if(L>R) return -1;
	if(l==r) return (tree[u].value1==tree[v].value1 && tree[u].value2==tree[v].value2)?-1:l;
	if(L<=l && r<=R)
	{
		int mid=(l+r)/2;
		if(tree[tree[u].l].value1!=tree[tree[v].l].value1 || tree[tree[u].l].value2!=tree[tree[v].l].value2) return calc(l,mid,L,R,tree[u].l,tree[v].l);
		else return calc(mid+1,r,L,R,tree[u].r,tree[v].r);
	}
	int mid=(l+r)/2,bck=-1;
	if(L<=mid) bck=calc(l,mid,L,R,tree[u].l,tree[v].l);
	if(mid<R)
	{
		int nbck=calc(mid+1,r,L,R,tree[u].r,tree[v].r);
		if(nbck!=-1) bck=nbck;
	}
	return bck;
}
int main()
{
	srand(time(NULL));
	n=read(),q=read();
	for(int i=1;i<=n;++i) rv1[i]=(ll)rand()*rand(),rv2[i]=(ll)rand()*rand();
	for(int i=1;i<=n;++i) col[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	fun(1,0);
	while(q--)
	{
		int u=read(),v=read(),l=read(),r=read();
		int lca=LCA(u,v);
		//cout<<"??? "<<u<<" "<<v<<" "<<lca<<endl;
		if(l<=col[lca] && col[lca]<=r)
		{
			//cout<<"cao";
			if(calc(1,n,col[lca],col[lca],root[u],root[v])==-1)
			{
				printf("%d\n",col[lca]);
				continue;
			}
			int ans1=calc(1,n,l,col[lca]-1,root[u],root[v]),ans2=calc(1,n,col[lca]+1,r,root[u],root[v]);
			if(ans1==-1) printf("%d\n",ans2);
			else printf("%d\n",ans1);
			continue;
		}
		printf("%d\n",calc(1,n,l,r,root[u],root[v]));
	}
	return 0;
}