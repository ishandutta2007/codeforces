// Problem: A. Dungeon
// Contest: Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL: http://codeforces.com/contest/1463/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read(),m=read(),k=read();
    	if((n+m+k)%9ll==0ll) 
    	{
    		int A=(n+m+k)/9;
    		if(n<A||m<A||k<A) puts("NO");
    		else puts("YES");
    	}
    	else puts("NO");
    }
	return 0;
}