// Problem: D. Almost Identity Permutations
// Contest: Codeforces - Educational Codeforces Round 32
// URL: https://codeforces.com/contest/888/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

signed main()
{
    int n=read(),m=read(),ans=1;
    if(m>=2) ans+=n*(n-1)/2;
    if(m>=3) ans+=n*(n-1)*(n-2)/3;
    if(m>=4) ans+=n*(n-1)*(n-2)*(n-3)/4;
    if(m>=4) ans+=n*(n-1)*(n-2)*(n-3)/8;
    printf("%lld\n",ans);
	return 0;
}