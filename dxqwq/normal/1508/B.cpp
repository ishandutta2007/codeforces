// Problem: B. Almost Sorted
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/B
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
int F[103];
signed main()
{
	F[0]=1;
	for(int i=1; i<=62; i++) F[i]=1ll<<(i-1);
    for(int T=read();T--;)
    {
    	int n=read(),N=n,m=read(),D=0,sum=0;
    	if(n<61)
    	{
    		int A=F[n];
    		if(m>A)
    		{
    			puts("-1");
    			continue;	
    		}
    	}
    	else D=n-61,n=61,sum=0;
    	for(int i=1; i<=D; ++i) printf("%lld ",i);
    	for(int i=1; i<=n; )
    	{
    		int A;
	    	for(int j=i,k=n-i; j<=n; ++j,--k)
	    	{
	    		int G=F[k];
	    		if(sum+G<m) sum+=G;
	    		else {A=j;break;}
	    	}
	    	for(int j=A; j>=i; --j) printf("%lld ",j+D);
    		i=A+1;
    	}
    	puts(""); 
    }
	return 0;
}