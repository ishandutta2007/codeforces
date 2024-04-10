/*
 * @Author: BilyHurington
 * @Date: 2021-05-01 09:22:25
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-05-01 11:22:07
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> Poly;
const int mod=998244353;
namespace Polynomial{
    int fast_pow(int x,long long k){
        long long ans=1;
        while(k){
            if(k&1) ans=ans*x%mod;
            x=1ll*x*x%mod;k>>=1;
        }
        return ans;
    }
    const int MAXN=1<<18,G=3;
    long long W[MAXN+10],Fac[MAXN+10],Fac_inv[MAXN+10];
    inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
    inline int del(int x,int y){return x>=y?x-y:x+mod-y;}
    inline void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
    inline void Del(int &x,int y){x-=y;if(x<0) x+=mod;}
    void Init(){
        Fac[0]=1;for(int i=1;i<=MAXN;i++) Fac[i]=Fac[i-1]*i%mod;
        Fac_inv[MAXN]=fast_pow(Fac[MAXN],mod-2);
        for(int i=MAXN;i>=1;i--) Fac_inv[i-1]=Fac_inv[i]*i%mod;
        for(int i=1;i<MAXN;i<<=1){
            W[i]=1;long long t=fast_pow(G,(mod-1)/2/i);
            for(int j=1;j<i;j++) W[i+j]=W[i+j-1]*t%mod;
        }
    }
    void NTT(int *A,int len,bool tag){
        static int B[MAXN+10],C[MAXN+10];C[0]=0;
        for(int i=1;i<len;i++) C[i]=(C[i>>1]>>1)|((i&1)*(len>>1));
        for(int i=0;i<len;i++) B[i]=A[C[i]];
        for(int i=1;i<len;i<<=1){
            for(int j=0;j<len;j+=i<<1){
                for(int k=0;k<i;k++){
                    int t=B[i+j+k]*W[i+k]%mod;
                    B[i+j+k]=del(B[j+k],t);
                    B[j+k]=add(B[j+k],t);
                }
            }
        }
        if(tag){
            reverse(B+1,B+len);long long INV=fast_pow(len,mod-2);
            for(int i=0;i<len;i++) B[i]=B[i]*INV%mod;
        }
        for(int i=0;i<len;i++) A[i]=B[i];
    }
    void poly_mul(int *a,int *b,int len){
        static int c[MAXN];
        memset(c,0,sizeof(int)*len);
        for(int i=0;i<len;i++) c[i]=b[i];
        NTT(c,len,0);
        NTT(a,len,0);
        for(int i=0;i<len;i++) a[i]=(long long)a[i]*c[i]%mod;
        NTT(a,len,1);
    }
    Poly operator * (const Poly &A,const Poly &B){
        int len;for(len=1;len<A.size()+B.size()-1;len<<=1);
        static int a[MAXN+10],b[MAXN+10];
        memset(a,0,sizeof(int)*len);
        for(int i=0;i<A.size();i++) a[i]=A[i];
        memset(b,0,sizeof(int)*len);
        for(int i=0;i<B.size();i++) b[i]=B[i];
        poly_mul(a,b,len);
        Poly C(A.size()+B.size()-1);
        for(int i=0;i<C.size();i++) C[i]=a[i];
        return C;
    }
}
using namespace Polynomial;
int n;long long m;
signed main(){
    scanf("%lld %lld",&n,&m);Init();
    Poly P(n+1),P2(n+1);
    for(int i=0;i<=n;i++) scanf("%lld",&P[i]),P[i]=P[i]*Fac[i]%mod;
    for(int i=0;i<=n;i++) P2[i]=Fac_inv[i];
    reverse(P2.begin(),P2.end());
    //for(int i=0;i<=n;i++) printf("%lld ",P[i]);puts("");
    //for(int i=0;i<=n;i++) printf("%lld ",P2[i]);puts("");
    P=P*P2;
    //for(int i=0;i<=2*n;i++) printf("%lld ",P[i]);puts("");
    for(int i=0;i<=n;i++) P[i]=P[i+n];P.resize(n+1);
    for(int i=0;i<=n;i++) P[i]=1ll*P[i]*fast_pow(fast_pow(i+1,mod-2),m)%mod;
    for(int i=0;i<=n;i++) P2[i]=(i&1)?mod-Fac_inv[i]:Fac_inv[i];
    reverse(P2.begin(),P2.end());
    P=P*P2;for(int i=0;i<=n;i++) printf("%lld ",P[i+n]*Fac_inv[i]%mod);
    return 0;
}