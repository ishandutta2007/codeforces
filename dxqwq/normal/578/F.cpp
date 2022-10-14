// Problem: F. Mirror Box
// Contest: Codeforces - Codeforces Round #320 (Div. 1) [Bayan Thanks-Round]
// URL: https://codeforces.com/problemset/problem/578/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[503][503];
int solve(int n)
{
	int ans=1;
	for(int i=1; i<=n; ++i)
	{
		int k=i;
		for(int j=i+1; j<=n&&!a[k][i]; ++j) if(a[j][i]) k=j;
		if(!a[k][i]) return 0;
		if(i!=k) 
		{
			ans=(p-ans)%p; 
			for(int j=1; j<=n; ++j) swap(a[i][j],a[k][j]); 
		}
		ans=ans*a[i][i]%p;
		for(int j=i+1; j<=n; ++j) 
			a[i][j]=a[i][j]*qp(a[i][i],p-2)%p;
		for(int j=1; j<=n; ++j) 
			for(int k=i+1; k<=n; ++k) 
				if(i!=j&&a[j][i]) 
					a[j][k]=(p+a[j][k]-a[i][k]*a[j][i]%p)%p;
	}
	return ans;
}
char s[1003][1003];
int fa[100003];
int id[100003],icnt;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
#define G(x,y) (x-1)*m+y
void addedge(int u,int v)
{
	u=id[find(u)],v=id[find(v)];
	if(u==v) return ;
	(++a[u][u])%=p,
	(++a[v][v])%=p,
	(a[u][v]+=p-1)%=p,
	(a[v][u]+=p-1)%=p;
	return ;
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) puts("0"),exit(0);
	fa[x]=y;
	return ;
}
signed main()
{
	int n=read()+1,m=read()+1;p=read();
	int ans=0;
	for(int i=1; i<=n*m; ++i) fa[i]=i;
	for(int i=1; i<n; ++i)
		scanf("%s",s[i]+1);
	for(int i=1; i<n; ++i)
		for(int j=1; j<m; ++j)
			if(s[i][j]=='/') merge(G(i,j+1),G(i+1,j));
			else if(s[i][j]=='\\') merge(G(i,j),G(i+1,j+1));
	for(int i=1; i<=n; ++i) 
		for(int j=1,t; j<=m; ++j) 
			if((i+j)&1) 
				t=find(G(i,j)),(!id[t])&&(id[t]=++icnt);
	if(icnt<=150)
	{
		for(int i=1; i<n; ++i)
			for(int j=1; j<m; ++j)
				if(s[i][j]=='*') 
					if((i+j)&1) addedge(G(i,j),G(i+1,j+1));
					else addedge(G(i,j+1),G(i+1,j));
		ans=(ans+solve(icnt-1))%p;
	}
	memset(a,0,sizeof(a)),icnt=0;
	for(int i=1; i<=n; ++i) 
		for(int j=1,t; j<=m; ++j) 
			if((i+j+1)&1) 
				t=find(G(i,j)),(!id[t])&&(id[t]=++icnt);
	if(icnt<=150)
	{
		for(int i=1; i<n; ++i)
			for(int j=1; j<m; ++j)
				if(s[i][j]=='*') 
					if((i+j+1)&1) addedge(G(i,j),G(i+1,j+1));
					else addedge(G(i,j+1),G(i+1,j));
		ans=(ans+solve(icnt-1))%p;
	}
	printf("%lld\n",ans);
    return 0;
}