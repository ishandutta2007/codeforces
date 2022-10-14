// Problem: A. Binary Protocol
// Contest: Codeforces - Educational Codeforces Round 25
// URL: https://codeforces.com/contest/825/problem/A
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
char s[100003];
signed main()
{
 	int n=read();
 	scanf("%s",s+1);
 	for(int i=1,lst=0; i<=n+1; i++)   
 	{
 		if(s[i]=='1') ++lst;
 		else
 		{
 			printf("%lld",lst);
 			lst=0;
 		}
 	}
	return 0;
}