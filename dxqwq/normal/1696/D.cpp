// Problem: D. Permutation Graph
// Contest: Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int n;
int a[1000003];
struct stmax
{
	int st[300003][21],l2[300003];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<=20; i++) 
		st[l][i]=max(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return max(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main()
	{
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}s1;
struct stmin
{
	int st[300003][21],l2[300003];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<=20; i++) 
		st[l][i]=min(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return min(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main()
	{
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}s0;
int pos[1000003];
int n0[1000003],n1[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		s1.main(),s0.main();
		for(int i=1; i<=n; ++i) pos[a[i]]=i;
		stack<int> stk;
		stk.push(n+1),a[n+1]=n+1;
		for(int i=n; i>=1; --i)
		{
			while(a[i]>a[stk.top()]) stk.pop();
			n1[i]=stk.top();stk.push(i);
		}
		while(stk.top()!=n+1) stk.pop();
		a[n+1]=0;
		for(int i=n; i>=1; --i)
		{
			while(a[i]<a[stk.top()]) stk.pop();
			n0[i]=stk.top();stk.push(i);
		}
		int x=1,w=0;
		while(x!=n)
		{
			if(a[x+1]>a[x])
			{
				int R=n0[x]-1;
				x=pos[s1.query(x,R)];
			}
			else
			{
				int R=n1[x]-1;
				x=pos[s0.query(x,R)];
			}
			++w;
		}
		printf("%d\n",w);
	}
	return 0;
}