#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 50
#define p(x,y) pair<x,y>
#define pb push_back
#define mp make_pair
#define a first
#define b second
int n,m,x[MN+5],y[MN+5],X[MN+5],Y[MN+5],u[MN+5][MN+5],p[MN+5],pn,t[MN+5];
vector<p(p(int,int),p(int,int))> A,B;
void solve1(int*x,int*y,vector<p(p(int,int),p(int,int))>&A)
{
	int i,j,k;
	memset(u,0,sizeof(u));
	for(i=1;i<=m;++i)u[x[i]][y[i]]=i;
	for(pn=0,i=1;i<=n;++i)
	{
		k=pn+1;
		for(j=1;j<=n;++j)if(u[i][j])p[++pn]=u[i][j];
		for(j=k;j<=pn;++j)if(y[p[j]]>j)break;
		while(--j>=k)while(y[p[j]]<j)A.pb(mp(mp(x[p[j]],y[p[j]]),mp(x[p[j]],y[p[j]]+1))),++y[p[j]];
		for(j=k;j<=pn;++j)while(y[p[j]]>j)A.pb(mp(mp(x[p[j]],y[p[j]]),mp(x[p[j]],y[p[j]]-1))),--y[p[j]];
	}
	for(i=1;i<=m;++i)
	{
		while(x[i]>i)A.pb(mp(mp(x[i],y[i]),mp(x[i]-1,y[i]))),--x[i];
		while(x[i]<i)A.pb(mp(mp(x[i],y[i]),mp(x[i]+1,y[i]))),++x[i];
	}
}
int main()
{
	int i;
	n=read();m=read();
	for(i=1;i<=m;++i)x[i]=read(),y[i]=read();
	for(i=1;i<=m;++i)X[i]=read(),Y[i]=read();
	solve1(x,y,A);solve1(X,Y,B);
	for(i=1;i<=m;++i)
	{
		while(y[i]<Y[i])A.pb(mp(mp(x[i],y[i]),mp(x[i],y[i]+1))),++y[i];
		while(y[i]>Y[i])A.pb(mp(mp(x[i],y[i]),mp(x[i],y[i]-1))),--y[i];
	}
	printf("%d\n",A.size()+B.size());
	for(i=0;i<A.size();++i)printf("%d %d %d %d\n",A[i].a.a,A[i].a.b,A[i].b.a,A[i].b.b);
	for(i=B.size();i--;)printf("%d %d %d %d\n",B[i].b.a,B[i].b.b,B[i].a.a,B[i].a.b);
}