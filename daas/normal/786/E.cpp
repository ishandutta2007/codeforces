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
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
const int oo=0x3f3f3f3f;
int n,m,N=1,head[1200001],tot,mem[1200001],col,ans,dl[1200001],h,t,S,T,Plus,lid[1200001],pd[1200001],ans1[1200001],ans2[1200001],point[1200001],Lid[1200001];
int	deep[1200001],father[1200001],id[1200001],top[1200001],son[1200001],size[1200001],cnt;
struct sb
{
	int from,to,nextn,l;
}a[1200001];
struct node
{
	int l,r;
}tree[1200001];
void ADD(int from,int to,int l)
{
	a[++tot].to=to,a[tot].nextn=head[from],a[tot].from=from,a[tot].l=l;
	head[from]=tot;
}
void build(int from,int to,int l)
{
	//cout<<"cnm "<<from<<" "<<to<<" "<<l<<endl;
	ADD(from,to,l);
	ADD(to,from,0);
}
void fun1(int u,int fa)
{
	father[u]=fa,deep[u]=deep[fa]+1,size[u]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		lid[v]=(i+1)/2;
		fun1(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
	}
}
void fun2(int u,int toop)
{
	id[u]=++cnt,point[cnt]=u,top[u]=toop;
	if(!son[u])
		return;
	fun2(son[u],toop);
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==father[u] || v==son[u])
			continue;
		fun2(v,v);
	}
}
int build_t(int l,int r)
{
	int bj=++N;
	if(l==r)
	{
		Lid[bj]=lid[point[l]];
		build(bj,bj+Plus,1);
		return bj;
	}
	int mid=(l+r)/2;
	tree[bj].l=build_t(l,mid);
	tree[bj].r=build_t(mid+1,r);
	build(bj,tree[bj].l,oo);
	build(bj,tree[bj].r,oo);
	build(tree[bj].l+Plus,bj+Plus,oo);
	build(tree[bj].r+Plus,bj+Plus,oo);
	return bj;
}
void xg(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
	{
		build(col,bj,oo);
		build(bj+Plus,col+1,oo);
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid)
		xg(l,mid,L,R,tree[bj].l);
	if(mid<R)
		xg(mid+1,r,L,R,tree[bj].r);
}
void qxg(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		xg(2,n,id[top[x]],id[x],2);
		x=father[top[x]];
	}
	if(x==y)
		return;
	if(deep[x]>deep[y])
		swap(x,y);
	xg(2,n,id[son[x]],id[y],2);
}
int make()
{
	memset(deep,0,sizeof(deep));
	deep[S]=1;
	h=t=0;
	dl[++t]=S;
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=head[u];i!=0;i=a[i].nextn)
		{
			int v=a[i].to;
			if(deep[v] || !a[i].l)
				continue;
			deep[v]=deep[u]+1;
			dl[++t]=v;
			if(v==T)
				return 1;
		}
	}
	return 0;
}
int fun(int u,int flow)
{
	if(u==T)
		return flow;
	int rest=flow;
	for(int i=head[u];i!=0 && rest!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(deep[v]!=deep[u]+1 || !a[i].l)
			continue;
		int K=fun(v,min(rest,a[i].l));
		if(!K)
			deep[v]=0;
		a[i].l-=K;
		a[i^1].l+=K;
		rest-=K;
	}
	return flow-rest;
}
void Dinic()
{
	while(make())
		while(1)
		{
			int K=fun(S,oo);
			if(!K)
				break;
			ans+=K;
		}
}
void paint(int u)
{
	pd[u]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(!a[i].l || pd[v])
			continue;
		paint(v);
	}
}
int main()
{
	n=read(),m=read();
	Plus=14*n;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		build(u,v,0);
	}
	fun1(1,0);
	fun2(1,1);
	//cout<<endl<<endl<<endl;
	memset(head,0,sizeof(head));
	tot=1;
	build_t(2,n);
	//cout<<endl<<endl<<endl;
	N=2*Plus;
	S=0,T=1;
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		col=++N;
		mem[N]=i;
		build(S,N,1);
		qxg(x,y);
		++N;
		build(N,T,oo);
	}
	Dinic();
	printf("%d\n",ans);
	paint(S);
	for(int i=2;i<=tot;i+=2)
		if(pd[a[i].from]!=pd[a[i].to] && !a[i].l)
		{
			if(a[i].from==S)
				ans1[++ans1[0]]=mem[a[i].to];
			else
				/*cout<<a[i].from<<" "<<a[i].to<<endl,*/ans2[++ans2[0]]=Lid[a[i].from];
		}
	sort(ans1+1,ans1+ans1[0]+1);
	sort(ans2+1,ans2+ans2[0]+1);
	printf("%d",ans1[0]);
	for(int i=1;i<=ans1[0];++i)
		printf(" %d",ans1[i]);
	putchar('\n');
	printf("%d",ans2[0]);
	for(int i=1;i<=ans2[0];++i)
		printf(" %d",ans2[i]);
	return 0;
}