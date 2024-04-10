// Problem: F. Armor and Weapons
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
map<pair<int,int>,int> mp;
map<pair<int,int>,int> ans;
int tree[200003];
int find(int x)
{
	x=200001-x;
	int res=0;
	while(x) res=max(res,tree[x]),x-=x&(-x); 
	return res;
}
void add(int x,int k)
{
	x=200001-x;
	while(x<=200000) tree[x]=max(tree[x],k),x+=x&(-x);
}
signed main()
{
	memset(tree,0xc0,sizeof(tree));
	int n=read(),m=read();
	for(int T=read(); T--;)
	{
		int x=read(),y=read();
		mp[make_pair(x,y)]=1;
	}
	queue<pair<int,int>> q;
	q.push(make_pair(1,1));
	while(!q.empty())
	{
		auto i=q.front();
		q.pop();
		int x=ans[i];
		auto nxt=i;
		
		nxt.first=min(n,i.first+i.second+mp[i]);
		if(find(nxt.first)<nxt.second)
		if(nxt.first==n&&nxt.second==m) printf("%d\n",x+1),exit(0);
		else add(nxt.first,nxt.second),ans[nxt]=x+1,q.push(nxt);
		
		nxt=i,nxt.second=min(m,i.first+i.second+mp[i]);
		if(find(nxt.first)<nxt.second)
		if(nxt.first==n&&nxt.second==m) printf("%d\n",x+1),exit(0);
		else add(nxt.first,nxt.second),ans[nxt]=x+1,q.push(nxt);
	} 
	return 0;
}