#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 50
#define M 100
using namespace std;
int n,m,c,bg[N+5];struct Data {int A,B,C,l,r;int V(int x) {return A*x*x+B*x+C;}}s[N+5];
namespace F
{
	#define PS (N*201+2)
	#define ES ((N+M)*202)
	#define add(x,y,f) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].F=f)
	int ee=1,lnk[PS+5],cur[PS+5];struct edge {int to,nxt,F;}e[2*ES+5];
	void Add(int x,int y,int f) {add(x,y,f),add(y,x,0);}
	int q[PS+5],D[PS+5];bool BFS()
	{
		int i,k,H,T;for(i=1;i<=c;++i) D[i]=0;D[q[H=T=1]=1]=1;
		while(H<=T&&!D[2]) for(i=lnk[k=q[H++]];i;i=e[i].nxt) !D[e[i].to]&&e[i].F&&(D[q[++T]=e[i].to]=D[k]+1);
		return D[2]?memcpy(cur,lnk,sizeof(cur)),1:0;
	}
	int DFS(int x,int f=1e9)
	{
		if(x==2) return f;int g=0;for(int i=lnk[x],o;i;i=e[i].nxt,cur[x]=i)
		{
			if(D[e[i].to]!=D[x]+1||!e[i].F||!(o=DFS(e[i].to,min(f,e[i].F)))) continue;
			if(g+=o,e[i].F-=o,e[i^1].F+=o,!(f-=o)) break;
		}return g;
	}
	int MaxFlow() {int g=0;while(BFS()) g+=DFS(1);return g;}
}
int main()
{
	int i,j;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d%d%d",&s[i].A,&s[i].B,&s[i].C);
	for(c=2,i=1;i<=n;++i) scanf("%d%d",&s[i].l,&s[i].r),bg[i]=c-s[i].l+1,c+=s[i].r-s[i].l+1;
	for(i=1;i<=n;++i) for(F::Add(1,bg[i]+s[i].l,1e7-s[i].V(s[i].l)),F::Add(bg[i]+s[i].r,2,1e9),j=s[i].l+1;j<=s[i].r;++j) F::Add(bg[i]+j-1,bg[i]+j,1e7-s[i].V(j));
	int x,y,z;while(m--) for(scanf("%d%d%d",&x,&y,&z),i=s[y].l;i<=s[y].r;++i) i+z<s[x].r&&(F::Add(i+z<s[x].l?1:bg[x]+i+z,bg[y]+i,1e9),0);
	return printf("%d\n",(int)1e7*n-F::MaxFlow()),0;
}