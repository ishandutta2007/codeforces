// Problem: D. Social Circles
// Contest: Codeforces - Codeforces Round #513 by Barcelona Bootcamp (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1060/problem/D
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
int a[1000003],b[1000003];
signed main()
{
    int n=read(),A=0,B=0;
    for(int i=1; i<=n; i++) a[i]=read(),b[i]=read();
    sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=1; i<=n; i++) ans+=max(a[i],b[i]);
    printf("%lld\n",ans+n);
	return 0;
}