// Problem: F. Problems for Codeforces
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1580/F
// Memory Limit: 256 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define ull unsigned long long
inline ull calc(const ull&x){return x-(__uint128_t(x)*9920937979283557439ull>>93)*998244353;}
const int p=998244353;
int qp(int x,int y)
{
    int res=1;
    for(int now=x; y; now=calc(1ull*now*now),y>>=1) if(y&1) res=calc(1ull*res*now);
    return res;
}
int rev[1<<18],N;
void init()
{
    rev[0]=0,rev[1]=N>>1;
    for(int i=2,d=N>>2; i<N; i<<=1,d>>=1)
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]|d;
    return ;
}
void NTT(int* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) F[i]^=F[rev[i]]^=F[i]^=F[rev[i]];
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        int w=qp(op?3:332748118,998244352/len);
        //omega(m,1)
        for(int l=0; l<N; l+=len)
        {
            int w0=1;
            for(int i=l; i<l+M; ++i)
            {
                int x=F[i],y=calc(1ull*w0*F[i+M]);
                F[i]=calc(x+y),F[i+M]=calc(p+x-y),w0=calc(1ull*w0*w);
            }
        }
    }
}
int x[1<<18],y[1<<18];
void getinv(int const *f,int *g,int n)
{
    g[0]=y[0]=qp(f[0],p-2);
    int inv;
    for(int lim=1; lim<n; lim<<=1)
    {
        memcpy(x,f,lim<<3);
        memset(y+lim,0,lim<<2);
        N=lim<<1,init(),inv=qp(N,p-2);
        NTT(x,1),NTT(y,1);
        for(int i=0; i<N; ++i) x[i]=calc(1ull*x[i]*y[i]);
        NTT(x,0);
        for(int i=0; i<N; ++i) x[i]=calc(1ull*x[i]*inv);
        memset(x,0,lim<<2);
        NTT(x,1);
        for(int i=0; i<N; ++i) x[i]=calc(1ull*x[i]*y[i]);
        NTT(x,0);
        for(int i=0; i<N; ++i) x[i]=calc(1ull*x[i]*inv);
        for(int i=lim; i<N; ++i) g[i]=calc((ull)p-x[i]);
        if(N<n) memcpy(y,g,lim<<3);
    }
}
int n=read(),m0=read(),odd=1,even=0;
int f[33][1<<18],ta[1<<18],tb[1<<18];
void solve(int m,int d)
{
	if(m==1)
	{
		for(int i=0; i<=n; ++i) f[d][i]=1;
		return ;
	}
	solve(m>>1,d+1),f[d+1][1]=(m+1)>>1;
 	for(int i=0; i<=n; i+=2) 
 		f[d][i]=f[d+1][i],f[d+1][i]=0;
	for(int i=0; i<=n; ++i) 
		ta[i]=(p+(i==0)-f[d+1][i])%p;
	getinv(ta,tb,n+1);
	even=(even+odd)%p,even=(even<<1)%p,odd=0;
	for(int i=1; i<=n; i+=2)
		odd=(odd+1ll*f[d+1][i]*i%p*tb[n-i])%p;
	for(N=1; N<=n*3; N<<=1);
	for(int i=n+1; i<N; ++i) tb[i]=0;
	init(),NTT(f[d],1),NTT(tb,1);
	for(int i=0; i<N; ++i)
		f[d][i]=1ll*f[d][i]*f[d][i]%p*tb[i]%p;
	NTT(f[d],0);
	int inv=qp(N,p-2);
	for(int i=0; i<=n; ++i) 
		f[d][i]=(1ll*inv*f[d][i]+f[d+1][i])%p;
	for(int i=n+1; i<N; ++i) 
		f[d][i]=0;
	return ;
}
signed main() 
{
	solve(m0,0);
	if((n+1)&1) printf("%d\n",(odd+even)%p);
	else printf("%d\n",odd);
	return 0;
}