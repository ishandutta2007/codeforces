// Problem: C. Permutation Cycle
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/932/problem/C
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
 	int n=read(),a=read(),b=read();
 	int X,Y,f=0;
 	for(int i=0; i*a<=n; i++)
 	{
 		if((n-i*a)%b==0)
 		{
 			X=i,Y=(n-i*a)/b,f=1;
 			break;
 		}
 	}
 	if(!f)
 	{
 		puts("-1");
 		return 0;
 	}
 	int cnt=0;
 	for(int i=1; i<=X; i++)
 	{
 		int t=cnt+1;
 		for(int j=1; j<a; ++j) ++cnt,printf("%lld ",cnt+1);
 		printf("%lld ",t);++cnt;
 	}
 	for(int i=1; i<=Y; i++)
 	{
 		int t=cnt+1;
 		for(int j=1; j<b; ++j) ++cnt,printf("%lld ",cnt+1);
 		printf("%lld ",t);++cnt;
 	}
	return 0;
}