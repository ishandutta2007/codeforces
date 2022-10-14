// Problem: A. Tricky Alchemy
// Contest: Codeforces - Codeforces Round #456 (Div. 2)
// URL: https://codeforces.com/contest/912/problem/A
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
 	int n=read(),m=read();
 	int a=read(),b=read(),c=read();
 	int A=a*2+b,B=b+c*3;
 	printf("%lld\n",max(0ll,A-n)+max(0ll,B-m));   
	return 0;
}