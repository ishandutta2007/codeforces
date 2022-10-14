// Problem: D. Suitable Replacement
// Contest: Codeforces - Educational Codeforces Round 25
// URL: https://codeforces.com/contest/825/problem/D
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
char s[1000003],t[1000003];
int cnt[26],c[26];
signed main()
{
 	scanf("%s",s+1);
 	int n=strlen(s+1);
 	scanf("%s",t+1);
 	int m=strlen(t+1);
 	int g=0;
 	for(int i=1; i<=n; i++) if(s[i]=='?') ++g;else ++cnt[s[i]-'a'];
 	for(int i=1; i<=m; i++) ++c[t[i]-'a'];
 	int ans=0;
 	for(ans=1; ; ans++)
 	{
 		int x=0;
 		for(int j=0; j<26; j++)
 		{
 			x+=max(0,c[j]*ans-cnt[j]);
 		}
 		if(x>g)
 		{
 			--ans;
 			break;
 		}
 	}
 	for(int i=0; i<26; i++) c[i]=max(ans*c[i]-cnt[i],0);
 	for(int i=1; i<=n; i++) if(s[i]=='?')
 	{
 		 bool f=1;
 		for(int j=0; j<26; j++) if(c[j]>0)
 		{
 			printf("%c",'a'+j);
 			--c[j];
 			f=0;
 			break;
 		}
 		if(f) printf("a");
 	}
 	else printf("%c",s[i]);
	return 0;
}