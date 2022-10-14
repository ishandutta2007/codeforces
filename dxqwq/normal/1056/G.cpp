// Problem: G. Take Metro
// Contest: Codeforces - Mail.Ru Cup 2018 Round 3
// URL: https://codeforces.com/problemset/problem/1056/G
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int mp[100003];
signed main()
{
	int n=read(),m=read(),s=read()-1,t=read();
	for(int i=t; i; --i)
	{
		if(i%n==t%n)
		{
			if(mp[s])
			{
				t=i%(mp[s]-i);
				break;
			}
			else mp[s]=i;
		}
		if(s<m) s=(s+i)%n;
		else s=((s-i)%n+n)%n;
		if(i==1) printf("%lld\n",s+1),exit(0);
	}
	for(int i=t; i; --i)
		if(s<m) s=(s+i)%n;
		else s=((s-i)%n+n)%n;
	printf("%lld\n",s+1);
	return 0;
}