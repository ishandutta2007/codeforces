// Problem: B. Frog Traveler
// Contest: Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/B
// Memory Limit:  MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int f[1000003],a[1000003],b[1000003],lst[1000003];
set<int> s;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=i-read();
	for(int i=1; i<=n; ++i) b[i]=i+read();
	memset(f,0x3f,sizeof(f));
	for(int i=0; i<n; ++i) s.insert(-i);
	queue<int> q;
	f[n]=0;
	q.push(n);
	while(!q.empty())
	{
		int A=q.front(),x=b[q.front()],y=f[q.front()]+1;
		q.pop();
		auto it=s.lower_bound(-x);
		vector<int> v;
		while(it!=s.end()&&(*it)<=-a[x])
		{
			v.push_back(*it),f[-(*it)]=y,lst[-(*it)]=A;
			++it;
		}
		for(auto i:v) q.push(-i),s.erase(i);
	}
	if(f[0]>n)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",f[0]);
	stack<int> st;
	int cur=0;
	while(cur!=n) st.push(cur),cur=lst[cur];
	while(!st.empty()) printf("%d ",st.top()),st.pop();
	return 0;
}