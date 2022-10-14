// Problem: A. Chess For Three
// Contest: Codeforces - Educational Codeforces Round 33 (Rated for Div. 2)
// URL: https://codeforces.com/contest/893/problem/A
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
 	int n=read();  
 	for(int i=1; i<=n; i++) a[i]=read();
 	 for(int x=3,i=1; i<=n; i++)
 	 {
 	 	if(x==a[i])
 	 	{
 	 		puts("NO");exit(0);
 	 	}
 	 	else
 	 	{
 	 		x=6-a[i]-x;
 	 	}
 	 }
 	 puts("YES");
	return 0;
}