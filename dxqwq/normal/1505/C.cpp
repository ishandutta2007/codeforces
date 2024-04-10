// Problem: C. Fibonacci Words
// Contest: Codeforces - April Fools Day Contest 2021
// URL: https://codeforces.com/contest/1505/problem/C
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
#define int long long
char s[53];
signed main()
{
    scanf("%s",s+1);
    int n=strlen(s+1),g=1;
    for(int i=3; i<=n; i++) if(((s[i-1]-'A')+(s[i-2]-'A'))%26!=s[i]-'A') g=0;
	if(g) puts("YES");
	else puts("NO");
	return 0;
}