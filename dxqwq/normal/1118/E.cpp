// Problem: E. Yet Another Ball Problem
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
bool cmp(pair<int,int> A,pair<int,int> B)
{
	if(A.first+A.second!=B.first+B.second)
	return A.first+A.second<=B.first+B.second;
	return A.first<=B.first;
}
signed main()
{
	int n=read(),m=read();
	m=min(m,1000ll);
		int c=0;
		for(int i=1; i<=m; ++i)
		for(int j=1; j<=m; ++j)
		if(i!=j)
		a[++c]=make_pair(i,j);
		sort(a+1,a+c+1,cmp);
	if(c<n) puts("NO");
	else
	{
		puts("YES");
		for(int i=1; i<=n; ++i) 
		printf("%lld %lld\n",a[i].first,a[i].second);
	}
	return 0;
}