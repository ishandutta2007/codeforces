// Problem: CF438E The Child and Binary Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF438E
// Memory Limit: 250 MB
// Time Limit: 7000 ms
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
long long A[1048576],B[1048576],ans[2][1048576];
int rev[1048576],N,M,n;
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
        //omega(m,1)
        for(int l=0,r=len-1; l<=N; l+=len,r+=len)
        {
            long long w0=1;
            for(int i=l; i<l+M; ++i)
            {
                long long x=(F[i]+w0*F[i+M]%p)%p,y=(F[i]+p-w0*F[i+M]%p)%p;
                F[i]=x,F[i+M]=y,w0=w0*w%p;
            }
        }
    }
}
void getinv(long long* BB,int len)
{
	memset(ans[0],0,sizeof(int)*(len<<3));
	memset(ans[1],0,sizeof(int)*(len<<3));
	memset(A,0,sizeof(int)*(len<<3));
	int t=1;
    ans[0][0]=qp(BB[0],998244351);
    for(N=2,M=1; M<=(len<<1); t^=1)
    {
        init();
        for(int i=0; i<M; ++i) ans[t][i]=(ans[t^1][i]<<1)%p;
        for(int i=0; i<M; ++i) A[i]=BB[i];
        NTT(ans[t^1],1),NTT(A,1);
        for(int i=0; i<N; ++i) ans[t^1][i]=ans[t^1][i]*ans[t^1][i]%p*A[i]%p;
        NTT(ans[t^1],0);
        long long inv=qp(N,998244351);
        for(int i=0; i<N; ++i) ans[t^1][i]=ans[t^1][i]*inv%p;  
        for(int i=0; i<M; ++i) ans[t][i]=(ans[t][i]+p-ans[t^1][i])%p;
        N<<=1,M<<=1;      
    }
    memset(A,0,sizeof(A));
    for(int i=0; i<len; ++i) A[i]=ans[t^1][i];
    return ;
}
long long B0[1048576],F[1048576],C[2][1048576];
void getsqrt(long long*lst,long long*res,int len)
{//from lst to res
	if(len==1)
	{
		res[0]=1;
		return ;
	}
	getsqrt(res,lst,len>>1);
	memset(res,0,sizeof(int)*len<<2);
	memset(B0,0,sizeof(int)*len<<2);
	for(int i=0; i<(len>>1); ++i) B0[i]=(lst[i]<<1)%p;
	getinv(B0,len);
	for(int i=0; i<(len>>1); ++i) B0[i]=lst[i];
	N=1;
	for(;N<=(len<<1);N<<=1);
	init();
	long long inv=qp(N,998244351);
	NTT(B0,1);
	for(int i=0; i<N; ++i) B0[i]=B0[i]*B0[i]%p;
	NTT(B0,0);
	for(int i=0; i<len-1; ++i) B0[i]=B0[i]*inv%p;
	for(int i=len-1; i<N; ++i) B0[i]=0;
	/////////////////////////////////////////
	N=1;
	for(;N<=(len<<1);N<<=1);
	init();
	inv=qp(N,998244351);
	for(int i=0; i<len; ++i) B0[i]=(B0[i]+F[i])%p;
	NTT(A,1),NTT(B0,1);
	for(int i=0; i<N; ++i) A[i]=A[i]*B0[i]%p;
	NTT(A,0);
	for(int i=0; i<len; ++i) res[i]=A[i]*inv%p;
	return ;
}
signed main()
{
	int k=read();
	n=read()+1;
	for(int x; k--;) x=read(),F[x]=998244349;
	F[0]=1;
	int M=1;
	for(;M<=n;M<<=1);
	getsqrt(C[0],C[1],M);
	C[1][0]=(C[1][0]+1)%p;
	getinv(C[1],n);
	for(int i=1; i<n; ++i) printf("%lld\n",(A[i]<<1)%p);
	return 0;
}