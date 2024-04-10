// Problem: E. Misha and Paintings
// Contest: Codeforces - Codeforces Round #815 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1720/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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
int a[503][503],f[250003];
int n=read(),m=read(),k=0,c=0;
inline void ins(int x){c+=!--f[x];}
inline void del(int x){c-=!f[x]++;}
signed main()
{
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			k+=!(f[a[i][j]=read()]++);
	if(k<=m) printf("%d\n",m-k),exit(0); else k-=m;
	//erase k or k+1 is both ok
	for(int sy=1; sy<=n; ++sy)
		for(int l=sy,r=sy; r<=n; ++r)
		{
			for(int i=l; i<=r; ++i) ins(a[r-sy+1][i]);
			for(int i=l-sy+1; i<r-sy+1; ++i) ins(a[i][r]);
			while(c>k+1)
			{
				for(int i=l; i<=r; ++i) del(a[l-sy+1][i]);
				for(int i=l-sy+2; i<=r-sy+1; ++i) del(a[i][l]);
				++l;
			}
			if(c>=k) puts("1"),exit(0);
			while(l<=r&&r==n)
			{
				for(int i=l; i<=r; ++i) del(a[l-sy+1][i]);
				for(int i=l-sy+2; i<=r-sy+1; ++i) del(a[i][l]);
				++l;
			}
		}
	for(int sx=2; sx<=n; ++sx)
		for(int l=sx,r=sx; r<=n; ++r)
		{
			for(int i=l; i<=r; ++i) ins(a[i][r-sx+1]);
			for(int i=l-sx+1; i<r-sx+1; ++i) ins(a[r][i]);
			while(c>k+1)
			{
				for(int i=l; i<=r; ++i) del(a[i][l-sx+1]);
				for(int i=l-sx+2; i<=r-sx+1; ++i) del(a[l][i]);
				++l;
			}
			if(c>=k) puts("1"),exit(0);
			while(l<=r&&r==n)
			{
				for(int i=l; i<=r; ++i) del(a[i][l-sx+1]);
				for(int i=l-sx+2; i<=r-sx+1; ++i) del(a[l][i]);
				++l;
			}
		}
	puts("2");
	return 0;
}