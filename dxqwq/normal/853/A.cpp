// Problem: A. Planning
// Contest: Codeforces - Codeforces Round #433 (Div. 1, based on Olympiad of Metropolises)
// URL: https://codeforces.com/contest/853/problem/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
pair<int,int> a[1000003];
int ans[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) 
a[i].first=read(),a[i].second=i;
priority_queue<pair<int,int> > q;
int X=1;
int AA=0;
for(int i=m+1; i<=m+n; ++i) 
{
	while(X<=i&&X<=n) q.push(a[X]),++X;
	pair<int,int> A=q.top();
	q.pop();
	int L=A.first,R=A.second;
	ans[R]=i,AA+=L*(i-R);
}
printf("%lld\n",AA);
for(int i=1; i<=n;++i) printf("%lld ",ans[i]);
	return 0;
}