// Problem: A. Two Arrays
// Contest: Codeforces
// URL: https://codeforces.com/contest/1588/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003];
void Work()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) b[i]=read();
	sort(b+1,b+n+1);
	int s=0;
	for(int i=1; i<=n; ++i) if(a[i]+1!=b[i]&&a[i]!=b[i]) s=1;
	if(s) puts("NO"); else puts("YES");
	return ;
}
signed main()
{
	int T=read();
	while(T--) Work();
	return 0;
}