// Problem: G. PolandBall and Many Other Balls
// Contest: Codeforces - 8VC Venture Cup 2017 - Elimination Round
// URL: https://codeforces.com/problemset/problem/755/G
// Memory Limit: 256 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const long long p=998244353;
long long qp(long long x,int y)
{
    long long res=1;
    for(long long now=x; y; now=now*now%p,y>>=1) if(y&1) res=res*now%p;
    return res;
}
long long A[131072],B[131072],C[131072],tA[131072],tB[131072],tC[131072],tD[131072],tE[131072];
int rev[131072],N=1;
void init()
{
    int d=N>>1;
    rev[0]=0,rev[1]=N>>1;
    for(int i=2; i<=N; i<<=1)
    {
        d>>=1;
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]|d;
    }
    return ;
}
void NTT(long long* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) swap(F[i],F[rev[i]]);
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        long long w=qp(op?3:332748118,998244352/len);
        for(int l=0,r=len-1; l<=N; l+=len,r+=len)
        {
            long long w0=1;
            for(int i=l; i<l+M; ++i)
            {
                long long x=(F[i]+w0*F[i+M]%p)%p,y=(F[i]+p-(w0*F[i+M]%p))%p;
                F[i]=x,F[i+M]=y,w0=w0*w%p;
            }
        }
    }
}
signed main()
{
    int n=read(),k=read();
    for(;N<=(k<<1);N<<=1);
    B[0]=C[0]=C[1]=1;
    long long inv=qp(N,998244351);
    init();
    int t=1,M=(N>>1);
    for(;(t<<1)<=n;t<<=1);//now t should be the highest bit of n
    t>>=1;//we just start here >_<
    for(;t>=1;t>>=1)
    {
    	NTT(A,1),NTT(B,1),NTT(C,1);
    	for(int i=0; i<N; ++i) tA[i]=B[i]*B[i]%p,tB[i]=A[i]*A[i]%p,tC[i]=B[i]*C[i]%p,tD[i]=A[i]*B[i]%p,tE[i]=C[i]*C[i]%p;
    	NTT(tA,0),NTT(tB,0),NTT(tC,0),NTT(tD,0),NTT(tE,0);
    	for(int i=0; i<M; ++i) tA[i]=tA[i]*inv%p,tB[i]=tB[i]*inv%p,tC[i]=tC[i]*inv%p,tD[i]=tD[i]*inv%p,tE[i]=tE[i]*inv%p;
    	memset(A,0,sizeof(A)),memset(B,0,sizeof(B)),memset(C,0,sizeof(C));
    	A[0]=B[0]=C[0]=1;
    	for(int i=1; i<M; ++i) A[i]=(tA[i]+tB[i-1])%p,B[i]=(tC[i]+tD[i-1])%p,C[i]=(tE[i]+tA[i-1])%p;
    	if(n&t)
    	{
    		for(int i=0; i<M; ++i) A[i]=B[i],B[i]=C[i];
    		for(int i=1; i<M; ++i) C[i]=(C[i]+B[i-1]+A[i-1])%p;
    	}
    }
    for(int i=1; i<=k; ++i) printf("%lld ",C[i]);
	return 0;
}