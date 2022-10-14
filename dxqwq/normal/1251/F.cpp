// Problem: F. Red-White Fence
// Contest: Codeforces - Educational Codeforces Round 75 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1251/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
long long A[6000003],B[6000003];
int rev[6000003],N=1;
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
int cnt[1000003],b[13],q[1000003];
long long ans[1000003];
int t;
void solve(int lim)
{
	int P=0,Q=0;
	for(int i=1; i<lim; ++i) if(cnt[i]==1) ++P; else if(cnt[i]>=2) ++Q;
	Q<<=1;
	for(;N<=P+Q;N<<=1);
	for(int i=0; i<N; ++i) A[i]=B[i]=0;
	long long fz=1,fm=1;
    for(int i=0; i<=P; ++i,fz=fz*(P+1-i)%p,fm=fm*i%p) A[i]=fz*qp(fm,p-2)%p*qp(2,i)%p;
    fz=fm=1;
    for(int i=0; i<=Q; ++i,fz=fz*(Q+1-i)%p,fm=fm*i%p) B[i]=fz*qp(fm,p-2)%p;
    init();
    NTT(A,1),NTT(B,1);
    for(int i=0; i<N; ++i) A[i]=A[i]*B[i]%p;
    NTT(A,0);
    long long inv=qp(N,998244351);
    for(int i=0; i<N; ++i) A[i]=A[i]*inv%p;
    for(int j=1; j<=t; ++j) if(q[j]-lim>=0) ans[j]=(ans[j]+A[q[j]-lim])%p;
    return ;
}
signed main()
{
    int n=read(),k=read();
    for(int i=1; i<=n; ++i) ++cnt[read()];
    for(int i=1; i<=k; ++i) b[i]=read();
    t=read();
    for(int i=1; i<=t; ++i) q[i]=(read()>>1)-1;
    for(int i=1; i<=k; ++i) solve(b[i]);
	for(int i=1; i<=t; ++i) printf("%lld\n",ans[i]);
	return 0;
}