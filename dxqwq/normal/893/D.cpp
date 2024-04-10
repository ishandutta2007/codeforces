// Problem: D. Credit Card
// Contest: Codeforces - Educational Codeforces Round 33 (Rated for Div. 2)
// URL: https://codeforces.com/contest/893/problem/D
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
int a[1000003];
signed main()
{
 	int n=read(),m=read();
 	for(int i=1; i<=n; i++) a[i]=read(); 
 	int ans=0;
 	for(int i=1,l=0,r=0; i<=n; i++)
 	{
 		if(a[i]==0)
 		{
 			if(r<0)
 			{
 				++ans;
 				l=0,r=m;
 			}
 			l=max(l,0ll);
 		}
 		else 
 		{
 			l+=a[i],r+=a[i];
 			r=min(r,m);
 			if(l>r)
 			{
 				puts("-1");
 				return 0;
 			}
 		}
 	}  
 	printf("%lld\n",ans);
	return 0;
}