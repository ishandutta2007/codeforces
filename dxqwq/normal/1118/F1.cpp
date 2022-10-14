// Problem: F1. Tree Cutting (Easy Version)
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/F1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
vector<int> e[300003];
int a[300003];
int s1[300003],s2[300003];
int S1=0,S2=0,ans=0;
void dfs(int x,int fa)
{
	s1[x]=(a[x]==1),s2[x]=(a[x]==2);
	for(int i:e[x]) if(i!=fa)dfs(i,x),s1[x]+=s1[i],s2[x]+=s2[i];
	if(x!=1)
	{
		if(s1[x]==S1&&s2[x]==0) ++ans;
		else if(s2[x]==S2&&s1[x]==0) ++ans;
	}
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i) S1+=(a[i]==1),S2+=(a[i]==2);
	for(int i=1; i<n; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}