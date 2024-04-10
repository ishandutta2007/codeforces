// Problem: C. Queue in the Train
// Contest: Codeforces Round #594 (Div. 1)
// URL: https://codeforces.com/contest/1239/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
pair<int,int> a[1000003];
set<int> s,qs;
queue<int> q;
int ans[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i].first=read(),a[i].second=i;
	sort(a+1,a+n+1);
	int cur=-1e9;
	a[n+1].first=1e18;
	for(int i=1; i<=n; ++i)
	{
		s.insert(a[i].second);
		if(!s.empty()&&
			(q.empty()||*qs.begin()>*s.begin()))
		{
			if(q.empty()) cur=a[i].first;
			q.push(*s.begin()),
			qs.insert(*s.begin()),s.erase(s.begin());
		}
		while(!q.empty()&&cur+m<a[i+1].first)
		{
			int x=q.front();q.pop();
			cur+=m;qs.erase(x);ans[x]=cur;
			if(!s.empty()&&
			(qs.empty()||*qs.begin()>*s.begin()))
			q.push(*s.begin()),
			qs.insert(*s.begin()),s.erase(s.begin());
		}
		// for(int i:qs) printf("%d ",i);
		// puts("");
	}
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
	return 0;
}