// Problem: A. Do Not Be Distracted!
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/A
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
char s[1000003];
int main()
{
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s+1);
		bool f[303];
		memset(f,0,sizeof(f));
		bool F=1;
		for(int i=1; i<=n; ++i) if(s[i]!=s[i-1])
		{
			if(f[s[i]]) F=0;
			else f[s[i]]=1;
		}
		if(F) puts("YES");
		else puts("NO");
	}
	return 0;
}