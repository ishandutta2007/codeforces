// Problem: D. Permutation Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],b[100003],c[100003];
vector<int> e[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) e[i].clear();
		vector<int> vec;
		for(int i=1; i<=n; ++i)
		{
			a[i]=read();
			if(a[i]!=0&&a[i]!=n+1)
				e[a[i]].push_back(i);
			else 
			{
				vec.push_back(i);
			}
		}
		b[0]=n+1,c[n+1]=0;
		for(int i=1; i<=n; ++i)
			b[i]=min(b[i-1],a[i]);
		for(int i=n; i>=1; --i)
			c[i]=max(c[i+1],c[i]);
		int k=-1;
		for(int i=0; i<=n; ++i)
			if(b[i]>i&&c[i+1]<=i) 
				k=i;
		printf("%d\n",k);
		int outs=0;
		while(outs<n)
		{
			int qwq=-1;
			outs+=(int)vec.size();
			for(int i:vec) if(!e[i].empty())
			{
				assert(qwq==-1); qwq=i;
			}
			for(int i:vec) if(i!=qwq) printf("%d ",i);
			if(outs<n) printf("%d ",qwq);
			vector<int> tmp;
			if(qwq!=-1)
			for(int i:e[qwq]) tmp.push_back(i);
			swap(tmp,vec);
		}
		puts("");
	}
	return 0;
}