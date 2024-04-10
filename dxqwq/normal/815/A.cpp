// Problem: A. Karen and Game
// Contest: Codeforces - Codeforces Round #419 (Div. 1)
// URL: https://codeforces.com/contest/815/problem/A
// Memory Limit: 512 MB
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
int a[103][103];
int b[103][103];
vector<pair<string,int> > v;
signed main()
{
	string A="row",B="col";
	int n=read(),m=read();
	if(n<=m)
	{
	for(int i=1; i<=n; ++i) 
		for(int j=1; j<=m; ++j) a[i][j]=read();
	}
	else
	{
		A="col",B="row";
		
	for(int i=1; i<=n; ++i) 
	for(int j=1; j<=m; ++j)
		 a[j][i]=read();
		 swap(n,m);
	}
	for(int i=1; i<=n; ++i) 
	{
		int s=1000000;
		for(int j=1; j<=m; ++j) s=min(s,a[i][j]);
		for(int j=1; j<=m; ++j) b[i][j]=a[i][j]-s;
		for(int k=0; k<s; ++k) v.push_back(make_pair(A,i));
	}
	for(int j=1; j<=m; ++j)
	{
		for(int i=2; i<=n; ++i) if(b[i][j]!=b[1][j]) puts("-1"),exit(0);
	}
	for(int j=1; j<=m; ++j) 
	for(int k=0; k<b[1][j]; ++k)
	v.push_back(make_pair(B,j));
	printf("%lld\n",(int)v.size());
	for(auto i:v)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}