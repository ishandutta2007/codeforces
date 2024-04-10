// Problem: C. Ela and Crickets
// Contest: Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int iscorner(int x,int y,int z)
{
	if((y==1||y==x)&&(z==1||z==x))
	{
		return (y==1)*2+(z==1);
	}
	return -1;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		int x1=read(),y1=read();
		int x2=read(),y2=read();
		int x3=read(),y3=read();
		int x0=read(),y0=read();
		if(iscorner(n,x1,y1)+iscorner(n,x2,y2)+iscorner(n,x3,y3)>-3)
		{
			if(x1+x2+x3==1+1+2||x1+x2+x3==n+n+n-1)
			if(y1+y2+y3==1+1+2||y1+y2+y3==n+n+n-1)
			{
			int Z=iscorner(n,x1,y1)+iscorner(n,x2,y2)+iscorner(n,x3,y3)+2;
			if((Z==0||Z==1)&&x0==n)
			{
				puts("YES");continue;
			}
			if((Z==2||Z==3)&&x0==1)
			{
				puts("YES");continue;
			}
			if((Z==0||Z==2)&&y0==n)
			{
				puts("YES");continue;
			}
			if((Z==1||Z==3)&&y0==1)
			{
				puts("YES");continue;
			}
			puts("NO");continue;
			}
		}
		int A=(x1+y1)&1,B=(x2+y2)&1,C=(x3+y3)&1;
		int Z=-1;
		if((A+B+C)&1)
		{//100
			if(A&1) Z=x1;
			if(B&1) Z=x2;
			if(C&1) Z=x3;
			if((x0+y0)&1)
			{
				if(x0%2==Z%2) puts("YES");
				else puts("NO");
			}
			else puts("YES");
		}
		else
		{//110
			if(A%2==0) Z=x1;
			if(B%2==0) Z=x2;
			if(C%2==0) Z=x3;
			if((x0+y0)%2==0)
			{
				if(x0%2==Z%2) puts("YES");
				else puts("NO");
			}
			else puts("YES");
		}
	}
	return 0;
}