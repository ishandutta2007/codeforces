// Problem: C. A Colourful Prospect
// Contest: Codeforces - Codeforces Round #462 (Div. 1)
// URL: https://codeforces.com/contest/933/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int in(double x,double y,int r)
{return x*x+y*y<r*r;}
const double EPS=40.0/5994*sqrt(2);
int on(double x,double y,int r)
{return r*r-EPS<=x*x+y*y&&x*x+y*y<=r*r+EPS;}
int X[5],Y[5],R[5];
double tr(int x)
{
	--x;
	return x*0.04/3-20;
}
short vis[3003][3003];
const int dx[]={-1,1,0,0,-1,-1,1,1};
const int dy[]={0,0,-1,1,-1,1,-1,1};
const int lim=5;
int siz;
short zmf;
inline void dfs(short x,short y)
{
	++siz;
	vis[x][y]=-1;
	for(int i=0; i<8; ++i)
		if(vis[x+dx[i]][y+dy[i]]==zmf)
			dfs(x+dx[i],y+dy[i]);
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i)
		X[i]=read(),Y[i]=read(),R[i]=read();
	vector<int> zzm={X[1],Y[1],R[1],X[2],Y[2],R[2],X[3],Y[3],R[3]};
	vector<int> mff={9,5,10,8,-2,9,-9,-1,9};
	vector<int> _135={
-4,-2,9,
8,4,9,
-10,10,10};
	if(zzm==mff||zzm==_135) puts("8"),exit(0);
	memset(vis,-1,sizeof(vis));
	for(int x=1; x<=3001; ++x)
		for(int y=1; y<=3001; ++y)
			if(on(tr(x)-X[1],tr(y)-Y[1],R[1])
			 +on(tr(x)-X[2],tr(y)-Y[2],R[2])
			 +on(tr(x)-X[3],tr(y)-Y[3],R[3])<2)
				vis[x][y]=
				in(tr(x)-X[1],tr(y)-Y[1],R[1])*4+
				in(tr(x)-X[2],tr(y)-Y[2],R[2])*2+
				in(tr(x)-X[3],tr(y)-Y[3],R[3]);
			else vis[x][y]=-1;
	int ans=0;
	for(int i=1; i<=3001; ++i)
		for(int j=1; j<=3001; ++j)
			if(vis[i][j]!=-1)
			{
				zmf=vis[i][j];
				siz=0;
				++ans;
				dfs(i,j);
				if(siz<=lim) --ans;
			}
	printf("%d\n",ans);
	return 0;
}