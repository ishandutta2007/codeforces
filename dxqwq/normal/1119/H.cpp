// Problem: H. Triple
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/problemset/problem/1119/H
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
   int s=0;
   char ch=getchar();
   while(ch<'0') ch=getchar();
   while(ch>='0') s=s*10+(ch&15),ch=getchar();
   return s;
}
#define ll long long
#define ull unsigned long long
inline ull calc(const ull&x){return x-(__uint128_t(x)*9920937979283557439ull>>93)*998244353;}
const int p=998244353,P=(p+1)>>1;
int F1[1<<20],F2[1<<20],F3[1<<20],A[1<<20];
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=1ll*t*t%p) 
		if(y&1) res=1ll*res*t%p;
	return res;
}
void FWT_XOR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0,A,B; k<j; ++k)
				A=F[i+k],B=F[i+j+k],F[i+k]=A+B,F[i+j+k]=A-B;
}
void FWT_IXOR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0,A,B; k<j; ++k)
				A=calc(1ull*P*F[i+k]),B=calc(1ull*P*F[i+j+k]),
				((F[i+k]=A+B)>=p)&&(F[i+k]-=p),
				((F[i+j+k]=A-B)<0)&&(F[i+j+k]+=p);
}
signed main()
{
	int m=read(),n=1<<read(),x=read(),y=read(),z=read(),S=0;
	for(int a,b,c,i=1; i<=m; ++i)
		a=read(),b=read()^a,c=read()^a,S^=a,++F1[b],++F2[c],++F3[b^c];
	FWT_XOR(F1,n),FWT_XOR(F2,n),FWT_XOR(F3,n);
	int A1=((ll)x+y+z)%p,A2=((ll)x+y+p-z)%p,A3=((ll)x+p-y+z)%p,A4=((ll)x+p+p-y-z)%p;
	for(int i=0; i<n; ++i)
		A[i]=1ll*qp(A1,(m+F1[i]+F2[i]+F3[i])>>2)
			*qp(A2,(m+F1[i]-F2[i]-F3[i])>>2)%p
			*qp(A3,(m-F1[i]+F2[i]-F3[i])>>2)%p
			*qp(A4,(m-F1[i]-F2[i]+F3[i])>>2)%p;
	FWT_IXOR(A,n);
	for(int i=0; i<n; ++i) printf("%d ",A[i^S]);
	return 0;
}