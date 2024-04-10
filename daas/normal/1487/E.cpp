#pragma GCC optimize(2)
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
int n1,n2,n3,n4,A[600001],head[2400001],tot,id[600001],maxn,S,T,dl[2400010],h,t;
int m1,m2,m3;
int dis[2400001],pd[2400001];
vector<int> fbd1[600001],fbd2[600001],fbd3[600001];
struct node
{
	int to,nextn,l;
}a[30000001];
void ADD(int from,int to,int l)
{
	a[++tot].to=to,a[tot].nextn=head[from],a[tot].l=l;
	head[from]=tot;
}
void build(int l,int r,int bj)
{
	if(l==r)
	{
		id[l]=bj;
		maxn=max(maxn,bj);
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	ADD(bj,bj*2,0);
	ADD(bj,bj*2+1,0);
}
void Make(int l,int r,int u,int L,int R,int len,int bj)
{
	if(L>R) return;
	if(L<=l && r<=R)
	{
		ADD(u,bj,len);
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid) Make(l,mid,u,L,R,len,bj*2);
	if(mid<R) Make(mid+1,r,u,L,R,len,bj*2+1);
}
void Dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	int len=T+1;
	dl[++t]=S;
	while(h!=t)
	{
		h=h%len+1;
		int u=dl[h];
		pd[u]=0;
		for(int i=head[u];i!=0;i=a[i].nextn)
		{
			int v=a[i].to;
			if(dis[v]>dis[u]+a[i].l)
			{
				dis[v]=dis[u]+a[i].l;
				if(!pd[v])
				{
					pd[v]=1;
					t=t%len+1;
					dl[t]=v;
				}
			}
		}
	}
	if(dis[T]==0x3f3f3f3f) puts("-1");
	else printf("%d\n",dis[T]);
}
int main()
{
	n1=read(),n2=read(),n3=read(),n4=read();
	for(int i=1;i<=n1;++i) A[i]=read();
	for(int i=1;i<=n2;++i) A[n1+i]=read();
	for(int i=1;i<=n3;++i) A[n1+n2+i]=read();
	for(int i=1;i<=n4;++i) A[n1+n2+n3+i]=read();
	int N=n1+n2+n3+n4;
	build(1,N,1);
	S=maxn+1,T=maxn+2;
	//for(int i=1;i<=n1;++i) ADD(S,id[i],0);
	m1=read();
	for(int i=1;i<=m1;++i)
	{
		int x=read(),y=read();
		fbd1[x].push_back(y);
	}
	for(int i=1;i<=n1;++i)
	{
		if(!fbd1[i].size())
		{
			Make(1,N,S,n1+1,n1+n2,A[i],1);
			continue;
		}
		sort(fbd1[i].begin(),fbd1[i].end());
		if(fbd1[i][0]!=1) Make(1,N,S,n1+1,n1+fbd1[i][0]-1,A[i],1);
		for(int j=1;j<fbd1[i].size();++j)
			if(fbd1[i][j-1]+1<fbd1[i][j]) Make(1,N,S,n1+fbd1[i][j-1]+1,n1+fbd1[i][j]-1,A[i],1);
		if(fbd1[i][fbd1[i].size()-1]!=n2) Make(1,N,S,n1+fbd1[i][fbd1[i].size()-1]+1,n1+n2,A[i],1);
	}
	m2=read();
	for(int i=1;i<=m2;++i)
	{
		int x=read(),y=read();
		fbd2[x].push_back(y);
	}
	for(int i=1;i<=n2;++i)
	{
		if(!fbd2[i].size())
		{
			Make(1,N,id[n1+i],n1+n2+1,n1+n2+n3,A[n1+i],1);
			continue;
		}
		sort(fbd2[i].begin(),fbd2[i].end());
		if(fbd2[i][0]!=1) Make(1,N,id[n1+i],n1+n2+1,n1+n2+fbd2[i][0]-1,A[n1+i],1);
		for(int j=1;j<fbd2[i].size();++j)
			if(fbd2[i][j-1]+1<fbd2[i][j]) Make(1,N,id[n1+i],n1+n2+fbd2[i][j-1]+1,n1+n2+fbd2[i][j]-1,A[n1+i],1);
		if(fbd2[i][fbd2[i].size()-1]!=n3) Make(1,N,id[n1+i],n1+n2+fbd2[i][fbd2[i].size()-1]+1,n1+n2+n3,A[n1+i],1);
	}
	m3=read();
	for(int i=1;i<=m3;++i)
	{
		int x=read(),y=read();
		fbd3[x].push_back(y);
	}
	for(int i=1;i<=n3;++i)
	{
		if(!fbd3[i].size())
		{
			Make(1,N,id[n1+n2+i],n1+n2+n3+1,n1+n2+n3+n4,A[n1+n2+i],1);
			continue;
		}
		sort(fbd3[i].begin(),fbd3[i].end());
		if(fbd3[i][0]!=1) Make(1,N,id[n1+n2+i],n1+n2+n3+1,n1+n2+n3+fbd3[i][0]-1,A[n1+n2+i],1);
		for(int j=1;j<fbd3[i].size();++j)
			if(fbd3[i][j-1]+1<fbd3[i][j]) Make(1,N,id[n1+n2+i],n1+n2+n3+fbd3[i][j-1]+1,n1+n2+n3+fbd3[i][j]-1,A[n1+n2+i],1);
		if(fbd3[i][fbd3[i].size()-1]!=n4) Make(1,N,id[n1+n2+i],n1+n2+n3+fbd3[i][fbd3[i].size()-1]+1,n1+n2+n3+n4,A[n1+n2+i],1);
	}
	for(int i=1;i<=n4;++i) ADD(id[n1+n2+n3+i],T,A[n1+n2+n3+i]);
	Dijkstra();
	return 0;
}