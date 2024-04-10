// Problem: F. Quadratic Set
// Contest: Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1622/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool vis[1000003];
const int p=998244353;
unsigned long long rnd[1000003];
struct SET
{
	unsigned long long V=0;
	bool operator<(const SET&t)const{return V<t.V;}
	bool operator==(const SET&t)const{return V==t.V;}
	void insert(int x)
	{
		V^=rnd[x];
	}
	
};
SET d[1000003],D;
bool flg[1000003];
SET merge(SET&x,SET&y)
{
	return (SET){x.V^y.V};
}
void Merge(SET&x,SET&y)
{
	x.V^=y.V;
	return ;
}
vector<int> solve(SET&D,int n)
{
	vector<int> ans;
	if(D.V==0)
	{
		for(int j=1; j<=n; ++j) ans.push_back(j);
		return ans;
	}
	for(int i=1; i<=n; ++i) if(d[i]==D) 
	{
		for(int j=1; j<=n; ++j) if(j!=i)ans.push_back(j);
		return ans;
	}
	map<SET,int> mp;
	for(int i=1; i<=n; ++i)
	{
		if(mp[merge(D,d[i])]) 
		{
			int X=mp[merge(D,d[i])],Y=i;
			for(int j=1; j<=n; ++j) if(j!=X&&j!=Y)ans.push_back(j);
			return ans;
		}
		mp[d[i]]=i;
	}
	return ans;
}
mt19937_64 R(1919810);
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) rnd[i]=R();
	for(int i=2; i<=n; ++i) if(!vis[i])
	{
		d[i].insert(i);
		for(int j=2; i*j<=n; ++j)
		{
			vis[i*j]=1;
			bool flg=1;
			int t=j;
			while(t%i==0) t/=i,flg^=1;
			if(flg) d[i*j].insert(i);
		}
	}
	SET D1,D2;
	for(int i=1; i<=n; ++i)
		if((n-i)&1) Merge(D2,d[i]);
		else Merge(D1,d[i]);
	for(int i=2; i<=n; ++i) Merge(d[i],d[i-1]);
	vector<int> ans,aans;
	ans=solve(D1,n);
	if(n>1) aans=solve(D2,n-1);
	if(aans.size()>ans.size()) ans=aans;
	sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(int i:ans) printf("%d ",i);
	return 0;
}