// Problem: C. Binary Table
// Contest: Codeforces - CROC 2016 - Final Round [Private, For Onsite Finalists Only]
// URL: https://codeforces.com/problemset/problem/662/C
// Memory Limit: 256 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll F[1<<20],G[1<<20];
void FWT_XOR(ll*F,int n)
{
	ll A,B;
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				A=F[i+k],B=F[i+j+k],F[i+k]=A+B,F[i+j+k]=A-B;
}
void FWT_IXOR(ll*F,int n)
{
	ll A,B;
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				A=F[i+k],B=F[i+j+k],F[i+k]=A+B,F[i+j+k]=A-B;
}
char s[20][100003];
signed main()
{
	int n=read(),m=read();
	for(int i=0; i<n; ++i) scanf("%s",s[i]);
	for(int i=0,v=0; i<m; ++i,++F[v],v=0)
		for(int j=0; j<n; ++j) v+=(s[j][i]=='1')<<j;
	int N=1<<n;
	for(int i=0; i<N; ++i) G[i]=min(__builtin_popcount(i),n-__builtin_popcount(i)); 
	FWT_XOR(F,N),FWT_XOR(G,N);
	for(int i=0; i<N; ++i) F[i]*=G[i];
	FWT_IXOR(F,N);
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0; i<N; ++i) (ans>F[i])&&(ans=F[i]);
	printf("%lld\n",ans>>n);
	return 0;
}