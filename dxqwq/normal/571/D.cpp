// Problem: D. Campus
// Contest: Codeforces - Codeforces Round #317 [AimFund Thanks-Round] (Div. 1)
// URL: https://codeforces.com/problemset/problem/571/D
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
int n=read(),m=read();
struct fenwick
{
	int a[1000003];
	void add(int x,int k){while(x<=1000000) a[x]+=k,x+=x&(-x);}
	int query(int x){int res=0; while(x) res+=a[x],x-=x&(-x); return res;}
	void update(int l,int r,int k){add(l,k),add(r+1,-k);}
}A;
struct seg
{
	int ans[4000003];
	void update(int l,int r,int L,int R,int id,int val)
	{
		if(r<L||R<l) return ;
		if(L<=l&&r<=R) 
		{
			ans[id]=val;
			return ;
		}
		int mid=(l+r)>>1;
		update(l,mid,L,R,id<<1,val);
		update(mid+1,r,L,R,(id<<1)+1,val);
		return ;
	}
	int query(int l,int r,int x,int id)
	{
		if(l==r) return ans[id];
		int mid=(l+r)>>1;
		if(x<=mid) return max(ans[id],query(l,mid,x,id<<1));
		else return max(ans[id],query(mid+1,r,x,(id<<1)+1));
	}	
}B;
struct kruskal
{
	int fa[1000003],sz[1000003],cnt;
	int ls[1000003],rs[1000003];
	int dfn[1000003],out[1000003],dcnt=0;
	bool vis[1000003];
	void merge(int x,int y)
	{
		int tx=fa[x],ty=fa[y];
		vis[tx]=vis[ty]=1,
		fa[x]=++cnt,sz[cnt]=sz[tx]+sz[ty],
		ls[cnt]=tx,rs[cnt]=ty;
	} 
	void dfs(int x,int fa=0)
	{
		dfn[x]=++dcnt;
		if(ls[x]) dfs(ls[x]),dfs(rs[x]);
		out[x]=dcnt;
	}
	void init()
	{
		for(int i=1; i<=cnt; ++i) if(!vis[i]) dfs(i);
	}
}F1,F2;
struct query{int op,x;}q[500003];
vector<query> tmp[500003];
int ans[500003],acnt;
signed main()
{
	F1.cnt=F2.cnt=n;
	for(int i=1; i<=n; ++i) F1.fa[i]=i,F1.sz[i]=1;
	for(int i=1; i<=n; ++i) F2.fa[i]=i,F2.sz[i]=1;
	int qcnt=0;
	for(int i=1,x,y; i<=m; ++i)
	{
		char op=getchar();
		while(!isupper(op)) op=getchar();
		if(op=='U') x=read(),y=read(),F1.merge(x,y);
		else if(op=='M') x=read(),y=read(),F2.merge(x,y);
		else if(op=='A') x=read(),q[++qcnt]=(query){1,F1.fa[x]};
		else if(op=='Z') x=read(),q[++qcnt]=(query){2,F2.fa[x]};
		else x=read(),q[++qcnt]=(query){3,x};
	}
	F1.init(),F2.init();
	for(int i=1,qwq=0; i<=qcnt; ++i)
		if(q[i].op==1) ++qwq;
		else if(q[i].op==2) B.update(1,F2.cnt,F2.dfn[q[i].x],F2.out[q[i].x],1,qwq);
		else ++acnt,tmp[qwq].push_back((query){acnt,q[i].x}),tmp[B.query(1,F2.cnt,F2.dfn[q[i].x],1)].push_back((query){-acnt,q[i].x});
	for(int i=1,qwq=0; i<=qcnt; ++i) if(q[i].op==1)
	{
		++qwq,A.update(F1.dfn[q[i].x],F1.out[q[i].x],F1.sz[q[i].x]);
		for(auto j:tmp[qwq])
			if(j.op>0) ans[j.op]+=A.query(F1.dfn[j.x]);
			else ans[-j.op]-=A.query(F1.dfn[j.x]);
	}
	for(int i=1; i<=acnt; ++i)
		printf("%lld\n",ans[i]);
	return 0;
}