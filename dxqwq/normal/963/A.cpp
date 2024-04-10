// Problem: A. Alternating Sum
// Contest: Codeforces - Tinkoff Internship Warmup Round 2018 and Codeforces Round #475 (Div. 1)
// URL: https://codeforces.com/contest/963/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
const int p=1e9+9;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[1000003];
signed main()
{
	int n=read(),a=read(),b=read(),k=read();
	scanf("%s",s+1);
	int D=(n+1)/k,sum=0,ans=0;
	int z=qp(a,p-2)*b%p,zz=qp(z,k);
	// printf("%lld %lld\n",z,zz);
	for(int i=1,base=1; i<=k; ++i,base=base*z%p)
	{
		if(s[i]=='+') sum=(sum+base)%p;
		else sum=(sum+p-base)%p;
	}
	if(zz==1) ans=D;
	else ans=(qp(zz,D)+p-1)%p*qp((zz+p-1)%p,p-2)%p;
	// printf("%lld\n",ans);
	printf("%lld\n",ans*sum%p*qp(a,n)%p);
	return 0;
}