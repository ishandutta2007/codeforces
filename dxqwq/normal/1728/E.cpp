// Problem: E. Red-Black Pepper
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1728/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
void exgcd(int &x,int &y,int a,int b)
{
    if(!b)
    {
        x=1,y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int t=x;
    x=y,y=t-a/b*y;
}
int solve(int a,int b,int c)
{
	int G=__gcd(__gcd(a,b),c),x,y;
	a/=G,b/=G,c/=G;
	if(__gcd(a,b)!=1) return -1;
	exgcd(x,y,a,b);
	return x*c;
}
int a[300003];
signed main()
{
	int n=read(),s=0;
	for(int i=1; i<=n; ++i)
	{
		int x=read(),y=read();
		a[i]=x-y;s+=y;
	}
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	for(int i=1; i<=n; ++i) a[i]+=a[i-1];
	for(int x,y,m=read(); m--;)
	{
		x=read(),y=read();
		//xu+yv=n
		int g=solve(x,y,n);
		int A=y/__gcd(x,y);
		if(g==-1){puts("-1");continue;}
		g=(g%A+A)%A,assert(g>=0&&g<A);
		if(g*x>n){puts("-1");continue;}
		int l=0,r=((n/x)-g)/A-1,res=-1;
		// printf("%lld %lld\n",g,A);
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[(mid*A+g)*x]<=a[(mid*A+A+g)*x])
				res=mid,l=mid+1;
			else r=mid-1;
		}
		// printf("%lld ",(res*A+A+g)*x);
		printf("%lld\n",s+a[(res*A+A+g)*x]);
	}
	return 0;
}