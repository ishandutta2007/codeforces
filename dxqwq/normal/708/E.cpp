// Problem: E. Student's Camp
// Contest: Codeforces - AIM Tech Round 3 (Div. 1)
// URL: https://codeforces.com/problemset/problem/708/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int f[2003][2003],pref[2003][2003];
int pred[2003],g[2003];
int fac[100003],ifac[100003],d[100003];
inline int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	int n=read(),m=read(),a=read(),b=read(),q=a*qp(b,p-2)%p,k=read();
	fac[0]=ifac[0]=1;
	for(int i=1; i<=k; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=0; i<=k; ++i) d[i]=C(k,i)*qp(q,i)%p*qp((p+1-q)%p,k-i)%p; 
	f[0][m]=1,pref[0][m]=1;  
	for(int i=1; i<=m; ++i) pred[i]=(pred[i-1]+d[i-1])%p; 
	for(int i=1,lst=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j) 
			g[j]=(g[j-1]+d[j-1]*pref[i-1][j-1])%p;
		for(int j=1; j<=m; ++j)
			f[i][j]=d[m-j]*(
				lst*pred[j]%p
				+p-pref[i-1][m-j]*pred[j]%p
				+p-g[j]
			)%p;
		for(int j=1; j<=m; ++j) 
			pref[i][j]=(pref[i][j-1]+f[i][j])%p;
		lst=pref[i][m];
	}
	printf("%lld\n",pref[n][m]);
}