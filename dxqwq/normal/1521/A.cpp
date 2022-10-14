// Problem: A. Nastia and nearly Good Numbers
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    	int n=read(),m=read();
    	if(m==1)
    	{
			puts("NO");
    	}
    	else if(m==2)
    	{
    		puts("YES");
    		printf("%lld %lld %lld\n",n,n*99,n*100);
    	}
    	else 
    	{
    		puts("YES");
    		printf("%lld %lld %lld\n",n,n*(m-1),n*m);
    	}
    }
	return 0;
}