// Problem: E. Timofey and our friends animals
// Contest: Codeforces Round #395 (Div. 1)
// URL: https://codeforces.com/contest/763/problem/E
// Memory Limit: 256 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int to[100003][23],tc[100003];
int n,m,B,res;
struct query
{
    int l,r,bl,id;
    bool operator<(const query&t){return (bl<t.bl)||(bl==t.bl&&(r<t.r));}
}q[100003];
int ans[100003];
int fa[100003],tfa[100003];
int find_(int x)
{
	while(fa[x]!=x) x=fa[x];
	return x;
}
int find(int x)
{
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
int tfind(int x)
{
	return (tfa[x]==x)?x:(tfa[x]=tfind(tfa[x]));
}
int pos[100003],pc;
int val[100003];
int tt[100003];
signed main()
{
	n=read(),read();
	for(int i=1; i<=n; ++i)
		fa[i]=tfa[i]=i;
	for(int u,v,m=read(); m--;) 
		u=read(),v=read(),to[u][++tc[u]]=v,to[v][++tc[v]]=u;
	m=read(),B=n/sqrt(m)+1;
    for(int i=1; i<=m; ++i) 
    	q[i].l=read(),q[i].r=read(),q[i].bl=q[i].l/B,q[i].id=i;
    sort(q+1,q+m+1);
    int C=0;
    for(int r=0,L,i=1; i<=m; ++i)
    {
    	if(i==1||q[i].bl!=q[i-1].bl)
    	{
    		r=(q[i].bl+1)*B-1,L=r,res=0;
    		for(int j=1; j<=n; ++j) fa[j]=j;
    	}
    	if(q[i].l/B==q[i].r/B)
    	{
    		int res=q[i].r-q[i].l+1;
    		for(int j=q[i].l; j<=q[i].r; ++j)
    			for(int k=1; to[j][k]; ++k) 
    				if(q[i].l<=to[j][k]&&to[j][k]<j&&tfind(to[j][k])!=tfind(j)) 
    					tfa[tfind(j)]=tfind(to[j][k]),--res;
    		for(int j=q[i].l; j<=q[i].r; ++j) tfa[j]=j;
    		ans[q[i].id]=res;
    	}
    	else
    	{
    		while(r<q[i].r)
    		{
    			++r,++res;
    			for(int k=1; to[r][k]; ++k) 
    				if(to[r][k]>L&&to[r][k]<r&&find(to[r][k])!=find(r))
    					 fa[find(r)]=find(to[r][k]),--res;
    		}
    		assert(r==q[i].r);
    		int tr=res+L-q[i].l+1;
    		for(int j=L; j>=q[i].l; --j)
    			for(int k=1; to[j][k]; ++k) 
    				if(to[j][k]>j&&to[j][k]<=r
    				&&find_(to[j][k])!=find_(j)) 
    					val[++pc]=fa[find_(j)],
    					fa[pos[pc]=find_(j)]=find_(to[j][k]),
    					--tr;
    		for(int j=pc; j>=1; --j) fa[pos[j]]=val[j];
    		pc=0;
    		ans[q[i].id]=tr;
    	}
    }
    for(int i=1; i<=m; ++i) printf("%d\n",ans[i]);
	return 0;
}