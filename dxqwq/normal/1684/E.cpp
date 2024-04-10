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
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		map<int,int> a;
		for(int i=1; i<=n; ++i) ++a[read()];
		int nxt=0,ans=0,pig=k;
		priority_queue<int,vector<int>,greater<int>>q;
		for(auto it:a) if(it.first==nxt) ++nxt; else if(it.first<n)
		{
			while(pig&&it.first!=nxt) ++nxt,--pig;
			if(!pig&&it.first!=nxt) q.push(it.second);
			else ++nxt;
		}
		else q.push(it.second);
		while(!q.empty())
		{
			int A=q.top();q.pop();
			if(A<=k) k-=A; else ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}