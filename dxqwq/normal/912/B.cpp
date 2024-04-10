// Problem: B. New Year's Eve
// Contest: Codeforces - Codeforces Round #456 (Div. 2)
// URL: https://codeforces.com/contest/912/problem/B
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

signed main()
{
 	int n=read(),k=read();
 	if(k==1)
 	{
 		printf("%lld\n",n);
 		return 0;
 	}
 	int ans=1;
 	while((ans<<1)<=n) ans<<=1;
 	ans<<=1,ans--;
 	printf("%lld\n",ans);
	return 0;
}