// Problem: A. Palindromic Supersequence
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/932/problem/A
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
char s[100003];
signed main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
for(int i=1; i<=n; i++) printf("%c",s[i]);
for(int i=n; i>=1; i--) printf("%c",s[i]);
	return 0;
}