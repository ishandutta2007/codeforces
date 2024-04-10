// Problem: D. Is it rated - 3
// Contest: April Fools Day Contest 2022
// URL: https://codeforces.com/contest/1663/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
signed main()
{
	string s;
	cin>>s;
	if(s=="ABC")
	{
		int x=read();
		if(x<2000) puts("YES"); else puts("NO");
	}
	else if(s=="ARC")
	{
		int x=read();
		if(x<2800) puts("YES"); else puts("NO");
	}
	else
	{
		int x=read();
		if(x>=1200) puts("YES"); else puts("NO");
	}
	return 0;
}