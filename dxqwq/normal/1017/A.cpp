// Problem: A. The Rank
// Contest: Codeforces - Codeforces Round #502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1017/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
struct node
{
	int a,b,c,d,id;
	bool operator<(const node& x)const
	{
		int s=x.a+x.b+x.c+x.d;
		int t=a+b+c+d;
		if(s!=t) return s<t;
		return id<x.id;
	}
}a[10003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) 
    a[i].a=read(),a[i].b=read(),a[i].c=read(),a[i].d=read(),a[i].id=i;
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) if(a[i].id==1) printf("%lld\n",i);
    
	return 0;
}