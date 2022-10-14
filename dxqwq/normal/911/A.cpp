// Problem: A. Nearest Minimums
// Contest: Codeforces - Educational Codeforces Round 35 (Rated for Div. 2)
// URL: https://codeforces.com/contest/911/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[1000003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
	int x=1000000000;
	for(int i=1; i<=n; i++) x=min(x,a[i]);
	int ans=99999999
;	for(int i=1,lst=-99999999; i<=n; i++) if(x==a[i]) ans=min(ans,i-lst),lst=i;
printf("%d\n",ans);
	return 0;
}