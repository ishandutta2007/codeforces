// Problem: D2. Chopping Carrots (Hard Version)
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/D2
// Memory Limit: 64 MB
// Time Limit: 4000 ms
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
int a[100003],b[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read(),mn=114514,ans=114514;
		priority_queue<pair<int,int>> q;
		for(int i=1,x; i<=n; ++i)
		{
			b[i]=x=read();
			if(!a[x]) q.push(make_pair(x,x)),
			a[x]=1,mn=min(mn,x);
		}
		while(!q.empty())
		{
			auto t=q.top();q.pop();
			ans=min(ans,t.first-mn);
			if(!ans) break;
			int g=t.second/(t.second/t.first+1);
			if(t.second/k>g) break;
			else mn=min(mn,g),q.push(make_pair(g,t.second));
		}
		printf("%d\n",ans);
		for(int i=1; i<=n; ++i) a[b[i]]=0;
	}
	return 0;
}