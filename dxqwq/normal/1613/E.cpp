// Problem: E. Crazy Robot
// Contest: Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1613/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
char* s[1000003];
bool chk(int x,int y)
{
	if(s[x][y]!='.') return 0;
	int A=0;
	if(s[x-1][y]=='.') ++A;
	if(s[x+1][y]=='.') ++A;
	if(s[x][y-1]=='.') ++A;
	if(s[x][y+1]=='.') ++A;
	return A<2;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=0; i<=n+1; ++i) s[i]=new char[m+3];
		for(int i=0; i<=n+1; ++i)
			for(int j=0; j<=m+1; ++j)
				s[i][j]=0;
		for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
		queue<pair<int,int>> q;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)	if(s[i][j]=='L') 
				q.push(make_pair(i,j));
		while(!q.empty())
		{
			auto xx=q.front();q.pop();
			int x=xx.first,y=xx.second;
			if(s[x][y]!='L') s[x][y]='+';
			if(chk(x-1,y)) q.push(make_pair(x-1,y)); 
			if(chk(x+1,y)) q.push(make_pair(x+1,y)); 
			if(chk(x,y-1)) q.push(make_pair(x,y-1)); 
			if(chk(x,y+1)) q.push(make_pair(x,y+1)); 
		}
		for(int i=1; i<=n; ++i,puts(""))
			for(int j=1; j<=m; ++j)
				putchar(s[i][j]);
		for(int i=0; i<=n+1; ++i) delete s[i];//ybb
	}
	return 0;
}