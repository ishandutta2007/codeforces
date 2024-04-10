// Problem: E. Wizards and Bets
// Contest: Codeforces - Codeforces Round #114 (Div. 1)
// URL: https://codeforces.com/problemset/problem/167/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
vector<int> e[603];
int a[603][603],aa[603][603],c[603];
int ui[603],vi[603];
signed main()
{
	int N=read(),T=read(),ans=1;p=read();
	int n=0;
	for(int u,v; T--;)
		u=read()-1,v=read()-1,e[u].push_back(v),++c[v];
	for(int i=0; i<N; ++i) if(!c[i]) ui[n++]=i;
	n=0;
	for(int i=0; i<N; ++i) if(e[i].empty()) vi[n++]=i;
	queue<int> q;
	for(int i=0; i<N; ++i) if(!c[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		aa[x][x]=(aa[x][x]+1)%p;
		for(int y:e[x]) 
		{
			for(int i=0; i<N; ++i)
				aa[i][y]=(aa[i][x]+aa[i][y])%p;
			if(!--c[y]) q.push(y);
		}
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) 
			a[i][j]=aa[ui[i]][vi[j]];
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; !a[i][i]&&j<n; ++j)
			if(a[j][i]) ans=p-ans,swap(a[i],a[j]);
		if(!a[i][i]) puts("0"),exit(0);
		ans=ans*a[i][i]%p;
		int iv=qp(a[i][i],p-2);
		for(int j=i+1; j<n; ++j) a[i][j]=a[i][j]*iv%p;
		for(int j=1; j<n; ++j) if(i!=j&&a[j][i])
			for(int k=i+1; k<n; ++k) 
				a[j][k]=(p+a[j][k]-a[i][k]*a[j][i]%p)%p;
	}
	printf("%lld\n",ans);
	return 0;
}