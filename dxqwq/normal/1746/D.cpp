// Problem: D. Paths on the Tree
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
vector<int> e[200003];
int a[200003];
void dfs(int x)
{
	for(int y:e[x]) a[y]+=a[x],dfs(y);
	return ;
}
pair<int,int> solve(int x,int k)
{
	if(e[x].empty()) return make_pair(a[x]*k,a[x]);
	vector<int> vec;
	int d=e[x].size(),Z=k/d,Q=k%d,res=0;
	for(int y:e[x])
	{
		auto it=solve(y,Z);
		res+=it.first;
		vec.push_back(it.second);
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for(int i=0; i<Q; ++i) res+=vec[i];
	return make_pair(res,vec[Q]);
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=2; i<=n; ++i)
			e[read()].push_back(i);
		for(int i=1; i<=n; ++i) a[i]=read();
		dfs(1);
		printf("%lld\n",solve(1,k).first);
	}
	return 0;
}