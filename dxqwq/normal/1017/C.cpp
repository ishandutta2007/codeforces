// Problem: C. The Phone Number
// Contest: Codeforces - Codeforces Round #502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1017/problem/C
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
int x;
void solve(int l,int r)
{
	int L=(x-(r-l));
	int R=L+(r-l);
	for(int i=L; i<=R; i++) printf("%lld ",i);
	x-=(r-l+1);
	return ;
}
signed main()
{
 	int n=read();
 	x=n;
 	int m=sqrt(n);
 	for(int i=1; i<=n; i+=m) solve(i,min(i+m-1,n));
	return 0;
}