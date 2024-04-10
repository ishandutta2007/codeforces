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
int a[100003],b[100003],lst[100003];
vector<int> used,v[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read(),mn=114514,ans=114514;
		if(n<=1000)
		{
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
			int g=t.first;
			while(g-mn>=ans)
				g=t.second/(t.second/g+1),mn=min(mn,g);
			if(t.second/k>g) break;
			else mn=min(mn,g),q.push(make_pair(g,t.second));
		}
		printf("%d\n",ans);
		for(int i=1; i<=n; ++i) a[b[i]]=0;
		continue;
		}
		for(int i=1,x; i<=n; ++i)
		{
			b[i]=x=read();
			if(!a[x]) 
			{
				lst[x]=1,v[x].push_back(x),
				used.push_back(x);
				a[x]=1,mn=min(mn,x);
			}
		}
		for(int i=100000; i>=0; --i)
		{
			bool end=0;
			ans=min(ans,i-mn);
			if(!ans) break;
			if(lst[i]) for(int x:v[i])
			{
				int g=i;
				while(g-mn>=ans)
					g=x/(x/g+1),mn=min(mn,g);
				if(x/k>g){end=1;break;}
				else 
				{
					if(!lst[g]) 
						lst[g]=1,used.push_back(g);
					v[g].push_back(x);
				}
			}
			if(end){break;}
			vector<int> vv;vv.swap(v[i]);
		}
		for(int i:used) 
		{lst[i]=0;
		vector<int> vv;vv.swap(v[i]);
		}
		vector<int> vv;vv.swap(used);
		printf("%d\n",ans);
		for(int i=1; i<=n; ++i) a[b[i]]=0;
	}
	return 0;
}