// Problem: CF623E Transforming Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF623E
// Memory Limit: 250 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const long long p=1000000007;
const long double pi=acos(-1);
struct cp
{
    long double r,i;
    cp operator+(const cp &x)const{return (cp){x.r+r,x.i+i};}
    cp operator-(const cp &x)const{return (cp){r-x.r,i-x.i};}
    cp operator*(const cp &x)const{return (cp){r*x.r-i*x.i,r*x.i+i*x.r};}
}A[600003],B[600003],C[600003],D[600003],E[600003];
int rev[6000003],N=1;
void init()
{
    int d=N>>1;
    rev[0]=0,rev[1]=N>>1;
    for(int i=2; i<N; i<<=1)
    {
        d>>=1;
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]|d;
    }
    return ;
}
void FFT(cp* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) swap(F[i],F[rev[i]]);
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        cp w=(cp){cos(pi/M*op),sin(pi/M*op)};
        //omega(m,1)
        for(int l=0,r=len-1; l<=N; l+=len,r+=len)
        {
            cp w0=(cp){1,0};
            for(int i=l; i<l+M; ++i)
            {
                cp x=F[i]+w0*F[i+M],y=F[i]-w0*F[i+M];
                F[i]=x,F[i+M]=y,w0=w0*w;
            }
        }
    }
}
void mul(long long*F,long long*G,int n)
{
	memset(A,0,sizeof(A)),memset(B,0,sizeof(B)),memset(C,0,sizeof(C)),memset(D,0,sizeof(D));
    for(int i=0; i<=n; ++i) A[i].r=F[i]&32767,B[i].r=F[i]>>15;
    for(int i=0; i<=n; ++i) C[i].r=G[i]&32767,D[i].r=G[i]>>15;
    init();
    FFT(A,1),FFT(B,1),FFT(C,1),FFT(D,1);
    for(int i=0; i<N; ++i) E[i]=A[i]*D[i]+B[i]*C[i],A[i]=A[i]*C[i],B[i]=B[i]*D[i];
    FFT(A,-1),FFT(B,-1),FFT(E,-1);
    for(int i=0; i<=n; ++i) 
    {
        long long ans1=(A[i].r/N+0.5),ans2=(E[i].r/N+0.5),ans3=(B[i].r/N+0.5);
        ans2%=p,ans2=(ans2<<15)%p,ans3%=p,ans3=(ans3<<30)%p;
        F[i]=(ans1+ans2+ans3)%p;
    }
    return ;
}
long long X[600003],Y[600003],T[600003];
long long qp(long long x,long long y)
{
	long long res=1;
	for(long long now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
	return res;
}
long long fac[600003],ifac[600003];
signed main()
{
	int n=read(),m=read();
	if(n>m)
	{
		puts("0");
		return 0;
	}
    N=1; 
	for(;N<=(m<<1);N<<=1);
	init(),X[0]=1;
	int M=1;
	fac[0]=ifac[0]=1;
	for(int i=1; i<=100000; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(;(M<<1)<=n;M<<=1);
	for(int i=M,cur=0; i; i>>=1)
	{
//		puts("MUL");
//		printf("A:");for(int i=0; i<=m; ++i) printf("%lld ",X[i]);puts("");
		for(int j=0; j<=m; ++j) Y[j]=X[j]*ifac[j]%p,X[j]=X[j]*ifac[j]%p*qp(2,1ll*cur*j)%p;
		mul(X,Y,m);
		for(int j=0; j<=m; ++j) X[j]=X[j]*fac[j]%p;
//	    printf("B:");for(int i=0; i<=m; ++i) printf("%lld ",X[i]);puts("");
		cur<<=1;
		if(i&n)
		{
//			puts("ADD");
//			printf("A:");for(int i=0; i<=m; ++i) printf("%lld ",X[i]);puts("");
			for(int j=0; j<=m; ++j) Y[j]=X[j]*ifac[j]%p*qp(2,j)%p,X[j]=ifac[j];
			mul(X,Y,m);
			for(int j=0; j<=m; ++j) X[j]=(X[j]+p-Y[j])%p;
			for(int j=0; j<=m; ++j) X[j]=X[j]*fac[j]%p;
			X[0]=0;
//			printf("B:");for(int i=0; i<=m; ++i) printf("%lld ",X[i]);puts("");
			++cur;
		}
	}
	long long ans=0;
	for(int i=n; i<=m; ++i) ans=(ans+X[i]*fac[m]%p*ifac[i]%p*ifac[m-i]%p)%p;
	printf("%lld\n",ans);
    return 0;
}