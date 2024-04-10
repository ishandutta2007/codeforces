// Problem: A. Phone Numbers
// Contest: Codeforces - Codeforces Round #513 by Barcelona Bootcamp (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1060/problem/A
// Memory Limit: 512 MB
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
char s[1000003];
signed main()
{
 	int n=read();
 	scanf("%s",s+1); 
 	int cnt=0;
 	for(int i=1; i<=n;i++)
 	{
 		if(s[i]=='8') ++cnt;
 	}  
 	printf("%lld\n",min(cnt,n/11));
	return 0;
}