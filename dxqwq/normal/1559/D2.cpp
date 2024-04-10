// Problem: CF1559D2 Mocha and Diana (Hard Version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1559D2
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define fi first
#define se second
#define mp make_pair
#define pb push_back
vector<pair<int,int>> v;
int ld[1000003],rd[1000003];
int ls,rs;
int f1[1000003],f2[1000003];
int find(int* f,int x)
{
	return f[x]==x?x:(f[x]=find(f,f[x]));
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) f1[i]=f2[i]=i;
	int A=read(),B=read();
	for(int u,v; A--;)
		u=find(f1,read()),v=find(f1,read()),(u!=v)&&(f1[u]=v);
	for(int u,v; B--;)
		u=find(f2,read()),v=find(f2,read()),(u!=v)&&(f2[u]=v);
	for(int i=2,A,B,C,D; i<=n; ++i)
	{
		A=find(f1,i),B=find(f1,1),C=find(f2,i),D=find(f2,1); 
		if(A!=B&&C!=D) f1[A]=B,f2[C]=D,v.pb(mp(1,i));
	}
	for(int i=2,A,B,C,D; i<=n; ++i)
	{
		A=find(f1,i),B=find(f1,1),C=find(f2,i),D=find(f2,1); 
		if(A!=B&&C==D) f1[A]=B,ld[++ls]=i;
		else if(A==B&&C!=D) f2[C]=D,rd[++rs]=i;
		else assert(A==B&&C==D);
	}
	for(int i=1; i<=min(ls,rs); ++i) v.pb(mp(ld[i],rd[i]));
	printf("%d\n",(int)v.size());
	for(auto i:v) printf("%d %d\n",i.fi,i.se);
	return 0;
}