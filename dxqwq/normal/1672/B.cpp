// Problem: B. I love AAAB
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/B
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
char s[1000003],t[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),f=1,c=0;
		for(int i=1; i<=n; ++i) if(s[i]=='A') ++c;
		else 
		{
			if(c==0) 
			{
				f=0;break;
			}
			--c;
		}
		if(f&&s[n]=='B') puts("YES"); else puts("NO");
		
	}
	return 0;
}