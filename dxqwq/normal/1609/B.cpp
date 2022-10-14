// Problem: B. William the Vigilant
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
char s[1000003];
signed main()
{
	int n=read(),m=read();
		scanf("%s",s+1);
	int A=0;
	for(int i=1; i+2<=n; ++i) if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c') ++A;
	for(int i=1; i<=m; ++i)
	{
		int x=read();
		for(int j=max(x-2,0ll); j<=x&&j+2<=n; ++j) if(s[j]=='a'&&s[j+1]=='b'&&s[j+2]=='c') --A;
		char t=getchar();
		s[x]=t;
		for(int j=max(x-2,0ll); j<=x&&j+2<=n; ++j) if(s[j]=='a'&&s[j+1]=='b'&&s[j+2]=='c') ++A;
		printf("%lld\n",A);
	}
	return 0;
}