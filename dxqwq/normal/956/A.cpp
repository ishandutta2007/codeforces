// Problem: A. Mystical Mosaic
// Contest: Codeforces - Codeforces Round #472 (rated, Div. 1, based on VK Cup 2018 Round 2)
// URL: https://codeforces.com/contest/956/problem/A
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
char s[1003][1003];
int a[5003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	map<set<int>,int> mp;
	for(int i=1; i<=n; ++i)
	{
		set<int> ss;
		for(int j=1; j<=m; ++j) if(s[i][j]=='#') ss.insert(j);
		if(!mp[ss])
		{
			for(int j:ss) 
			{
			if(a[j]) puts("No"),exit(0);
			else a[j]=1;
			}
			mp[ss]=1;
		}
	}
	puts("Yes");
	return 0;
}