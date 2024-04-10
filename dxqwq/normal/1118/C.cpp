// Problem: C. Palindromic Matrix
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/C
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
int c[10003];
int ans[23][23];
int n=read();
void print(int x,pair<int,int> p)
{
	int i=p.first,j=p.second;
	ans[i][j]=ans[n+1-i][n+1-j]=ans[i][n+1-j]=ans[n+1-i][j]=x;
	return ;
}
void flush()
{
	for(int i=1; i<=n; ++i,puts("")) for(int j=1; j<=n; ++j) printf("%lld ",ans[i][j]);
}
signed main()
{
	
	int m=n*n;
	for(int i=1; i<=m; ++i) ++c[read()];
	queue<pair<int,int> > q4,q2,q1;
	for(int i=1; i<n+1-i; ++i)
	for(int j=1; j<n+1-j; ++j)
	{
		q4.push(make_pair(i,j));
	}
	if(n&1)
	{
		int i=(n+1)/2;
		for(int j=1; j<n+1-j; ++j)q2.push(make_pair(i,j)),q2.push(make_pair(j,i));
		q1.push(make_pair(i,i));
	}
	for(int i=1; i<=1000; ++i) while(!q4.empty()&&c[i]>=4) 
	print(i,q4.front()),c[i]-=4,q4.pop();
	for(int i=1; i<=1000; ++i) while(!q2.empty()&&c[i]>=2) 
	print(i,q2.front()),c[i]-=2,q2.pop();
	for(int i=1; i<=1000; ++i) while(!q1.empty()&&c[i]>=1) 
	print(i,q1.front()),c[i]-=1,q1.pop();
	if(!q4.empty()||!q2.empty()||!q1.empty()) puts("NO"),exit(0);
	puts("YES"),flush();
	return 0;
}