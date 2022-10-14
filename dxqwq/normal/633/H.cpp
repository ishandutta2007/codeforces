// Problem: CF633H Fibonacci-ish II
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF633H
// Memory Limit: 500 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{int x,y;bool operator<(const node&t)const{return x<t.x;}}a[30003];
int f[30003];
signed main()
{
	int n=read(),p=read();
    for(int i=1; i<=n; ++i) a[i].x=read(),a[i].y=i;
    sort(a+1,a+n+1);
    f[1]=1,f[2]=1;
    for(int i=3; i<=n; ++i) f[i]=(f[i-1]+f[i-2])%p;
    long long ans;
    for(int m=read(),l,r,c,qwq; m--;)
    {
    	l=read(),r=read(),
    	ans=0,qwq=0,c=0;
    	for(int i=1; i<=n; ++i) (a[i].y>=l&&a[i].y<=r&&a[i].x!=qwq)&&(ans+=1ll*a[i].x*f[++c],qwq=a[i].x);
    	printf("%lld\n",ans%p);
    }
	return 0;
}