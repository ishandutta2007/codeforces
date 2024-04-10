// Problem: A - Devu and Flowers
// Contest: Virtual Judge - 0621
// URL: https://vjudge.net/contest/444061#problem/A
// Memory Limit: 262 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define ll __int128
const ll p=1e9+7;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
inline ll c(ll n,ll m)//C(n,m)
{
    if(n<m) return 0;
    if(m>n-m) m=n-m;
    ll a=1,b=1;
    for(int i=0;i<m;i++)
	{
        a=(a*(n-i))%p;
        b=(b*(i+1))%p;
    }
    return a*qp(b,p-2)%p;
}
inline ll C(ll n,ll m)
{
	if(m==0) return 1;
	if(m==1) return n%p;
	return c(n%p,m%p)*C(n/p,m/p)%p;
}
int a[53];
signed main()
{
	int n=read(),m=read(),ans=0;
	for(int i=0; i<n; ++i) a[i]=read()+1;
	int N=1<<n;
	for(int i=0; i<N; ++i)
	{
		int k=m;
		bool f=0;
		for(int j=0; j<n; ++j) if(i&(1<<j)) f^=1,k-=a[j];
		if(k<0) continue;
		if(f) ans=(ans+p-C(n+k-1,n-1))%p;
		else ans=(ans+C(n+k-1,n-1))%p;
	}
	printf("%lld\n",(long long)ans);
	return 0;
}