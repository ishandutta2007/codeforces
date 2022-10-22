#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100
using namespace std;
int n,ex[N+5],ey[N+5],w[N+5][N+5][N+5];char s[N+5];
int q[N+5],p[N+5];bool Solve(int x,int y)
{
	int i,k,H,T;for(i=1;i<=n;++i) p[i]=0;p[q[H=1]=x]=y,p[q[T=2]=y]=x;
	while(H<=T) for(k=q[H++],i=1;i<=n;++i) if(w[p[k]][k][i]) if(p[i]) return 0;else p[q[++T]=i]=k;
	if(T==n) {for(i=2;i<=n;++i) ex[i-1]=q[i],ey[i-1]=p[q[i]];return 1;}return 0;
}
int d[N+5][N+5],e[N+5][N+5];
void dfs(int o,int x,int D=0)
{
	d[o][x]=D;for(int i=1;i<=n;++i) if(e[x][i]&&i^o&&!d[o][i]) dfs(o,i,D+1);
}
bool Check()
{
	int i,j,k;for(i=1;i<=n;++i) for(j=1;j<=n;++j) e[i][j]=0,d[i][j]=0;
	for(i=1;i^n;++i) e[ex[i]][ey[i]]=e[ey[i]][ex[i]]=1;
	for(i=1;i<=n;++i) dfs(i,i,0);
	for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) for(k=1;k<=n;++k) if((d[i][k]==d[j][k])^w[i][k][j]) return 0;return 1;
}
int main()
{
	int Tt,i,j,k,o;scanf("%d",&Tt);while(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) for(j=1;j<=n;++j) for(k=1;k<=n;++k) w[i][j][k]=0;
		for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) for(scanf("%s",s+1),k=1;k<=n;++k) s[k]&1&&(w[i][k][j]=w[j][k][i]=1);
		for(i=2;i<=n;++i) if(Solve(1,i)&&Check()) break;if(i>n) {puts("No");continue;}
		for(puts("Yes"),i=1;i^n;++i) printf("%d %d\n",ex[i],ey[i]);
	}return 0;
}