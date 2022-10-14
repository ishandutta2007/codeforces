// Problem: F. String Compression
// Contest: Codeforces - Educational Codeforces Round 25
// URL: https://codeforces.ml/contest/825/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
inline unsigned long long calc(const unsigned long long&x){return x-(__uint128_t(x)*9920937979283557439ull>>93)*998244353;}
char s[10003];
int ans[10003];
long long p1=998244353;
inline int qp1(int x,int y)
{
	int res=1;
	for(int now=x; y; y>>=1,now=calc(now*now)) if(y&1) res=calc(res*now);
	return res;
}
int a1[10003];
int C[10003];
int i1[10003],i2[10003];
inline int Hash(int l,int r)
{
	return calc((p1+a1[r]-a1[l-1])*i1[l-1]);
}
inline int calca(int x)
{
	int res=0;
	while(x) x/=10,++res;
	return res;
}
signed main()
{
	//for(int i=1; i<=6000; i++) s[i]='a';
 	scanf("%s",s+1);
 	int n=strlen(s+1);
 	for(int i=1; i<=n; i++) ans[i]=i+1;
 	i1[0]=1;
 	long long awa=qp1(131,p1-2);
 	for(int i=1; i<=n; i++) i1[i]=calc(i1[i-1]*awa);
 	for(int i=1; i<=n; i++) C[i]=calca(i);
 	for(int i=1,b1=1; i<=n; i++,b1=calc(b1*131))
 	a1[i]=(a1[i-1]+b1*(s[i]-'a'))%p1;
 	for(int i=1; i<=n; i++) for(int j=1; j<=i; j++)
 	{
 		int H=Hash(i-j+1,i);
 		for(int k=i-j+1,t=1; k>0; k-=j,++t)
 		{
 			if(Hash(k,k+j-1)!=H) break;
 			ans[i]=min(ans[i],ans[k-1]+j+C[t]); 
 		}
 	}   
 	printf("%lld\n",ans[n]);
	return 0;
}