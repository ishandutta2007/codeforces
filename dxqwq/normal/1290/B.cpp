// Problem: B. Irreducible Anagrams
// Contest: Codeforces - Codeforces Round #616 (Div. 1)
// URL: https://codeforces.com/contest/1290/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int f[200003][26];
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<26; ++j) f[i][j]=f[i-1][j];
		f[i][s[i]-'a']++;
	}
	for(int l,r,T=read(); T--;)
	{
		l=read(),r=read();
		int t=0;
		for(int i=0; i<26; ++i) if(f[r][i]-f[l-1][i]) ++t;
		if(l==r) puts("Yes");
		else if(t>2) puts("Yes");
		else if(t==1) puts("No");
		else if(s[l]==s[r]) puts("No");
		else puts("Yes");
	}
	return 0;
}