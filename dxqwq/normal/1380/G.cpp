#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[1000003];
long long w[1000003],ans[1000003];
long long qp(long long x,long long y)
{
	if(y==1) return x;
	if(y&1) 
	{
		long long t=qp(x,y>>1);
		return t*t%998244353LL*x%998244353LL;
	}
	long long t=qp(x,y>>1);
	return t*t%998244353LL;
}
int main()
{
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) w[i]=w[i-1]+a[i];
	for(int i=1; i<n; i++) for(int j=i; j>0; j-=(n-i)) ans[i]+=w[j],ans[i]%=998244353LL;
	for(int i=n-1; i>=0; i--) printf("%lld ",ans[i]*qp(n,998244351LL)%998244353LL);
	return 0;
}