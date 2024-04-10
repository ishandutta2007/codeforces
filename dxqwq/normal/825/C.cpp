// Problem: C. Multi-judge Solving
// Contest: Codeforces - Educational Codeforces Round 25
// URL: https://codeforces.com/contest/825/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003];
signed main()
{
 	int n=read(),m=read();
 	for(int i=1; i<=n; i++) a[i]=read();
 	sort(a+1,a+n+1);
 	int ans=0;
 	for(int i=1; i<=n; i++) 
 	if((m<<1)<a[i])
 	{
 		while((m<<1)<a[i]) ++ans,m<<=1;
 		m=max(m,a[i]);
 	} else m=max(m,a[i]);
 	printf("%lld\n",ans);
	return 0;
}