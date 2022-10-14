// Problem: B. Two Cakes
// Contest: Codeforces - Educational Codeforces Round 35 (Rated for Div. 2)
// URL: https://codeforces.com/contest/911/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
 	int n=read(),a=read(),b=read();
 	int ans=0,t=0;
 	for(int i=1; i<n; i++)
 	{
 		int x=a/i,y=b/(n-i),g=min(a/i,b/(n-i));
 		if(g>t) ans=min(x,y),t=g;
 		else if(g==t) ans=max(ans,min(x,y));
 	}
 	printf("%d\n",ans);
	return 0;
}