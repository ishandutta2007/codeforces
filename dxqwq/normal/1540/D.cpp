// Problem: D. Inverse Inversions
// Contest: Codeforces - Codeforces Round #728 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1540/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
int a[100003];
const int N=1<<17;
struct BIT
{
	int a[200003];
	vector<int> vec;
	void add(int x)
	{
		vec.push_back(x);
		while(x<=N) 
			++a[x],x+=x&(-x);
		return ;
	}
	void del(int x)
	{
		while(x<=N) 
			--a[x],x+=x&(-x);
		return ;
	}
	void clear()
	{
		for(int i:vec) del(i);
		vector<int>().swap(vec);
		return ;
	}
	int lb(int x)
	{
		int d=1<<16,c=0,r=0;
		while(d)
		{
			if(a[c+d]+((c+d)&(-c-d))>=x) r=c+d;
			else c+=d,x-=a[c]+(c&(-c));
			d>>=1;
		}
		return r;
	}
	int find(int x)
	{
		int r=x;
		while(x) r+=a[x],x-=x&(-x);
		return r;
	}
}T[400];
const int B=256,W=8;
void build(int i)
{
	T[i].clear();
	int l=i<<W,r=(i+1)<<W;
	for(int j=l; j<r; ++j) T[i].add(T[i].lb(a[j]));
	return ;
}
signed main()
{
	int n=read(),S=n>>W;
	for(int i=1; i<=n; ++i) a[i]=i-read()+1;
	for(int i=1; i<S; ++i) build(i);
	// double st=clock();
	for(int op,x,y,Q=read(); Q--;)
	{
		op=read(),x=read();
		if(op==1)
		{
			a[x]=x-read()+1,x>>=W;
			if(x!=0&&x!=S) build(x);
		}
		else
		{
			y=a[x];
			if((x>>W)<S)
			{
				for(int i=x+1; i&(B-1); ++i) y+=(y>=a[i]);
				for(int i=(x>>W)+1; i<S; ++i) y=T[i].find(y);
				for(int i=S<<W; i<=n; ++i) y+=(y>=a[i]);
			}
			else
			{
				for(int i=x+1; i<=n; ++i) y+=(y>=a[i]);
			}
			printf("%d\n",y-1);
		}
		// if((clock()-st)/CLOCKS_PER_SEC>4)
			// printf("%d queries to go\n",Q),exit(0);
	}
	return 0;
}