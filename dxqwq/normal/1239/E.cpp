// Problem: E. Turtle
// Contest: Codeforces - Codeforces Round #594 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1239/E
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bitset<1200003> bs[51][25];
int a[53],A[53],B[53];
signed main()
{
	bs[2][0]=1;
	int n=read(),sum=0;
	for(int i=1; i<=n*2; ++i) a[i]=read();
	sort(a+1,a+n*2+1);
	for(int i=3; i<=n*2; sum+=a[i],++i)
	{
		bs[i][0][0]=1;
		for(int j=1; j<n; ++j)
			bs[i][j]=bs[i-1][j]|(bs[i-1][j-1]<<a[i]);
	}
	A[1]=a[1],B[n]=a[2];
	for(int i=sum>>1; ; --i) if(bs[n*2][n-1][i])
	{
		int cur=i,re=n-1,pA=n,pB=1;
		for(int j=n*2; j>=3; --j)
			if(bs[j-1][re][cur]) A[pA--]=a[j];
			else B[pB++]=a[j],cur-=a[j],--re;
		for(int i=1; i<=n; ++i) printf("%d ",A[i]);
		puts("");
		for(int i=1; i<=n; ++i) printf("%d ",B[i]);
		puts("");
		return 0;
	}
	return 0;
}