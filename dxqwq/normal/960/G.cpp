// Problem: CF960G Bandit Blues
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF960G
// Memory Limit: 250 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<24],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
   int s=0;
   char ch=getchar();
   while(ch<'0') ch=getchar();
   while(ch>='0') s=s*10+(ch&15),ch=getchar();
   return s;
}
#define ull unsigned long long
//inline ull calc(const ull&x){return x-(__uint128_t(x)*9920937979283557439ull>>93)*998244353;}
inline ull calc(const ull&x){return x%998244353ll;}
const long long p=998244353;
inline long long qp(long long x,int y)
{
    long long res=1;
    for(long long now=x; y; now=calc(now*now),y>>=1) if(y&1) res=calc(res*now);
    return res;
}
long long A[524288],B[524288],C[524288];
int rev[524288],N=1;
inline void init()
{
    int d=N>>1;
    rev[0]=0,rev[1]=N>>1;
    for(int i=2; i<N; i<<=1)
    {
        d>>=1;
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]+d;
    }
    return ;
}
inline void NTT(long long* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) F[i]^=F[rev[i]]^=F[i]^=F[rev[i]];
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        long long w=qp(op?3:332748118,998244352/len);
        //omega(m,1)
        for(int l=0; l<N; l+=len)
        {
            long long w0=1;
            for(int i=l; i<l+M; ++i)
            {
                long long x=F[i],y=calc(w0*F[i+M]);
                F[i]=calc(x+y),F[i+M]=calc(p+x-y),w0=calc(w0*w);
            }
        }
    }
}
long long fac[200003],ifac[200003];
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=200000; ++i) fac[i]=calc(fac[i-1]*i);
	ifac[200000]=qp(fac[200000],p-2);
	for(int i=199999; i>=1; --i) ifac[i]=calc(ifac[i+1]*(i+1));
    int n=read()-1,M=1;
    if(!n)
    {
    	int A=read(),B=read();
    	if(A==1&&B==1) puts("1");
    	else puts("0");
    	return 0;
    }
	for(;(M<<1)<=n;M<<=1);
	A[0]=1;
	for(int i=M,cur=0; i; i>>=1)
	{
		if(cur)
		{
			for(N=1;N<=(cur<<1);N<<=1);init();
			long long inv=qp(N,p-2);
			for(int i=0; i<=cur; ++i) B[i]=calc(A[i]*fac[i]);
			for(int i=0; i<=cur; ++i) C[i]=calc(qp(cur,i)*ifac[i]);
			reverse(B,B+cur+1),NTT(B,1),NTT(C,1);
			for(int i=0; i<N; ++i) B[i]=calc(B[i]*C[i]);
			NTT(B,0),reverse(B,B+cur+1);
			for(int i=0; i<=cur; ++i) B[i]=calc(calc(B[i]*inv)*ifac[i]);
			for(int i=cur+1; i<N; ++i) B[i]=0;
			NTT(A,1),NTT(B,1);
			for(int i=0; i<N; ++i) A[i]=calc(A[i]*B[i]);
			NTT(A,0);
			for(int i=0; i<N; ++i) A[i]=calc(A[i]*inv);
			cur<<=1;
		}
		if(i&n)//F(x)*(x+cur)
		{
			++cur;
			for(int i=cur; i>=1; --i) A[i]=calc(A[i]*(cur-1)+A[i-1]);
			A[0]=calc(A[0]*(cur-1));
		}
	}
	// for(int i=1; i<=n; ++i)
	// {
		// for(int j=i; j>=1; --j) A[j]=calc(A[j]*(i-1)+A[j-1]);
		// A[0]=calc(A[0]*(i-1));
	// }
	int P=read()-1,Q=read()-1;
	printf("%lld ",A[P+Q]*fac[P+Q]%p*ifac[P]%p*ifac[Q]%p);
	return 0;
}