// Problem: A. Festival Organization
// Contest: Codeforces - Bubble Cup 9 - Finals [Online Mirror]
// URL: https://codeforces.com/problemset/problem/717/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
struct cp
{
	int x,y,sq;
	inline cp operator+(const cp&o)const{return(cp){(x+o.x)%p,(y+o.y)%p,sq};}
	inline cp operator-(const cp&o)const{return(cp){(x+p-o.x)%p,(y+p-o.y)%p,sq};}
	inline cp operator*(const cp&o)const{return cp{(x*o.x+sq*y*o.y)%p,(y*o.x+x*o.y)%p,sq};}
	inline cp operator/(const cp&o)const
	{
		int t=qp((o.x*o.x+p-sq*o.y*o.y%p)%p,p-2);
		return cp{(p+x*o.x-sq*y*o.y%p)%p*t%p,(y*o.x+p-x*o.y%p)%p*t%p,sq};
	}
};
cp qp(cp x,int y,int sq)
{
	cp res=(cp){1,0,sq};
	for(cp t=x; y; y>>=1,t=t*t) if(y&1) res=res*t;
	return res;
}
int fac[1003],ifac[1003],s[1003][1003];
int k=read(),l=read()+1,r=read()+2;
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
cp getsum(cp A,int x)
{
	if(A.x==1&&A.y==0) return (cp){(x+1)%p,0,A.sq};
	return ((cp){1,0,5}-qp(A,x+1,5))/((cp){1,0,5}-A);
}
int DianaTakesMeAwayPLZ(int x)
{
	cp a=(cp){0,400000003,5},A=(cp){500000004,500000004,5},
	   b=(cp){0,600000004,5},B=(cp){500000004,500000003,5},
	   res=(cp){0,0,5};
	for(int d=0; d<=k; ++d)
		for(int i=0,j=d; i<=d; ++i,--j)
			res=res+qp(a,i,5)*qp(b,j,5)
				*getsum(qp(A,i,5)*qp(B,j,5),x)
				*(cp){s[k][d]*(((k-d)&1)?(p-1):1)%p*C(d,i)%p,0,5};
	// assert(!res.y);
	return res.x;
}
// 
signed main()
{
	fac[0]=ifac[0]=s[0][0]=s[1][1]=1;
	for(int i=2; i<=k; ++i)
		for(int j=1; j<=i; ++j)
			s[i][j]=(s[i-1][j]*(i-1)+s[i-1][j-1])%p;
	for(int i=1; i<=k; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	printf("%lld\n",ifac[k]*(DianaTakesMeAwayPLZ(r)+p-DianaTakesMeAwayPLZ(l))%p);
	return 0;
}