// Problem: A. Long Beautiful Integer
// Contest: Codeforces - Codeforces Round #609 (Div. 1)
// URL: https://codeforces.com/contest/1268/problem/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
signed main()
{
	int n=read(),k=read();
	scanf("%s",s);
	int lst=0;
	for(int i=0; i<k; ++i)
	{
		for(int j=i; j<n; j+=k) 
			if(s[j]!=s[i])
			{lst=1;break;}
	}
	printf("%d\n",n);
	if(!lst) printf("%s",s);
	else
	{
		bool flg;
		for(int i=k; i<n; ++i) if(s[i]!=s[i%k])
		{
			if(s[i]>s[i%k]) flg=1;
			else flg=0;
			break;
		}
		if(flg){
		++s[k-1];
		for(int i=k-1; s[i]==58; s[i]-=10,--i,++s[i]);}
		for(int i=0; i<n; ++i) putchar(s[i%k]);
	}
	return 0;
}